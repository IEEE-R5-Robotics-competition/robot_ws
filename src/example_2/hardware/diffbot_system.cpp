// Copyright 2021 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "ros2_control_demo_example_2/diffbot_system.hpp"

#include <chrono>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

#include "hardware_interface/lexical_casts.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "rclcpp/rclcpp.hpp"

namespace ros2_control_demo_example_2
{
hardware_interface::CallbackReturn DiffBotSystemHardware::on_init(
  const hardware_interface::HardwareInfo & info)
{
  if (
    hardware_interface::SystemInterface::on_init(info) !=
    hardware_interface::CallbackReturn::SUCCESS)
  {
    return hardware_interface::CallbackReturn::ERROR;
  }

  config_.left_wheel_name = info_.hardware_parameters["left_wheel_name"];
  config_.right_wheel_name = info_.hardware_parameters["right_wheel_name"];
  config_.loop_rate = std::stof(info_.hardware_parameters["loop_rate"]);
  config_.device = info_.hardware_parameters["device"];
  config_.baud_rate = std::stoi(info_.hardware_parameters["baud_rate"]);
  config_.timeout_ms = std::stoi(info_.hardware_parameters["timeout_ms"]);
  config_.enc_counts_per_rev = std::stoi(info_.hardware_parameters["enc_counts_per_rev"]);

  wheel_left_.setup(config_.left_wheel_name, config_.enc_counts_per_rev);
  wheel_right_.setup(config_.right_wheel_name, config_.enc_counts_per_rev);

  // logger_ = std::make_shared<rclcpp::Logger>(
  //   rclcpp::get_logger("controller_manager.resource_manager.hardware_component.system.DiffBot"));
  // clock_ = std::make_shared<rclcpp::Clock>(rclcpp::Clock());

  
  for (const hardware_interface::ComponentInfo & joint : info_.joints)
  {
    // DiffBotSystem has exactly two states and one command interface on each joint
    if (joint.command_interfaces.size() != 1)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("DiffBotSystemHardware"), "Joint '%s' has %zu command interfaces found. 1 expected.",
        joint.name.c_str(), joint.command_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.command_interfaces[0].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("DiffBotSystemHardware"), "Joint '%s' have %s command interfaces found. '%s' expected.",
        joint.name.c_str(), joint.command_interfaces[0].name.c_str(),
        hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces.size() != 2)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("DiffBotSystemHardware"), "Joint '%s' has %zu state interface. 2 expected.", joint.name.c_str(),
        joint.state_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces[0].name != hardware_interface::HW_IF_POSITION)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("DiffBotSystemHardware"), "Joint '%s' have '%s' as first state interface. '%s' expected.",
        joint.name.c_str(), joint.state_interfaces[0].name.c_str(),
        hardware_interface::HW_IF_POSITION);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces[1].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("DiffBotSystemHardware"), "Joint '%s' have '%s' as second state interface. '%s' expected.",
        joint.name.c_str(), joint.state_interfaces[1].name.c_str(),
        hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }
  }

  return hardware_interface::CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> DiffBotSystemHardware::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> state_interfaces;

  state_interfaces.emplace_back(hardware_interface::StateInterface(
    wheel_left_.name, hardware_interface::HW_IF_POSITION, &wheel_left_.pos));
  state_interfaces.emplace_back(hardware_interface::StateInterface(
    wheel_left_.name, hardware_interface::HW_IF_VELOCITY, &wheel_left_.vel));

  state_interfaces.emplace_back(hardware_interface::StateInterface(
    wheel_right_.name, hardware_interface::HW_IF_POSITION, &wheel_right_.pos));
  state_interfaces.emplace_back(hardware_interface::StateInterface(
    wheel_right_.name, hardware_interface::HW_IF_VELOCITY, &wheel_right_.vel));

  return state_interfaces;
}

std::vector<hardware_interface::CommandInterface> DiffBotSystemHardware::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> command_interfaces;
  command_interfaces.emplace_back(hardware_interface::CommandInterface(
    wheel_left_.name, hardware_interface::HW_IF_VELOCITY, &wheel_left_.cmd));

  command_interfaces.emplace_back(hardware_interface::CommandInterface(
    wheel_right_.name, hardware_interface::HW_IF_VELOCITY, &wheel_right_.cmd));

  return command_interfaces;
}

hardware_interface::CallbackReturn DiffBotSystemHardware::on_activate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("DiffBotSystemHardware"), "Activating ...please wait...");

  comms_.connect(config_.device, config_.baud_rate, config_.timeout_ms);

  RCLCPP_INFO(rclcpp::get_logger("DiffBotSystemHardware"), "Successfully activated!");

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn DiffBotSystemHardware::on_deactivate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // BEGIN: This part here is for exemplary purposes - Please do not copy to your production code
  RCLCPP_INFO(rclcpp::get_logger("DiffBotSystemHardware"), "Deactivating ...please wait...");

  comms_.disconnect();
  RCLCPP_INFO(rclcpp::get_logger("DiffBotSystemHardware"), "Successfully deactivated!");

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::return_type DiffBotSystemHardware::read(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & period)
{
  comms_.read_encoder_values(wheel_left_.enc, wheel_right_.enc);

  double pos_prev = wheel_left_.pos;
  wheel_left_.pos = wheel_left_.calcEncAngle();
  wheel_left_.vel = (wheel_left_.pos - pos_prev) / period.seconds();

  pos_prev = wheel_right_.pos;
  wheel_right_.pos = wheel_right_.calcEncAngle();
  wheel_right_.vel = (wheel_right_.pos - pos_prev) / period.seconds();


  return hardware_interface::return_type::OK;
}

hardware_interface::return_type ros2_control_demo_example_2 ::DiffBotSystemHardware::write(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  int motor_left_counts_per_loop = wheel_left_.cmd / wheel_left_.rads_per_count / config_.loop_rate;
  int motor_right_counts_per_loop = wheel_right_.cmd / wheel_right_.rads_per_count / config_.loop_rate;
  comms_.set_motor_values(motor_left_counts_per_loop, motor_right_counts_per_loop); //added negative here
  return hardware_interface::return_type::OK;
}

}  // namespace ros2_control_demo_example_2

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(
  ros2_control_demo_example_2::DiffBotSystemHardware, hardware_interface::SystemInterface)
