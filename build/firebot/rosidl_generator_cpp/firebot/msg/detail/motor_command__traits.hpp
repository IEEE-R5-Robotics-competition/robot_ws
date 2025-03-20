// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from firebot:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
#define FIREBOT__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "firebot/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace firebot
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCommand & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace firebot

namespace rosidl_generator_traits
{

[[deprecated("use firebot::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const firebot::msg::MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  firebot::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use firebot::msg::to_yaml() instead")]]
inline std::string to_yaml(const firebot::msg::MotorCommand & msg)
{
  return firebot::msg::to_yaml(msg);
}

template<>
inline const char * data_type<firebot::msg::MotorCommand>()
{
  return "firebot::msg::MotorCommand";
}

template<>
inline const char * name<firebot::msg::MotorCommand>()
{
  return "firebot/msg/MotorCommand";
}

template<>
struct has_fixed_size<firebot::msg::MotorCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<firebot::msg::MotorCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<firebot::msg::MotorCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FIREBOT__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
