// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from firebot:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__MSG__DETAIL__MOTOR_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define FIREBOT__MSG__DETAIL__MOTOR_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "firebot/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "firebot/msg/detail/motor_command__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace firebot
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_firebot
cdr_serialize(
  const firebot::msg::MotorCommand & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_firebot
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  firebot::msg::MotorCommand & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_firebot
get_serialized_size(
  const firebot::msg::MotorCommand & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_firebot
max_serialized_size_MotorCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace firebot

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_firebot
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, firebot, msg, MotorCommand)();

#ifdef __cplusplus
}
#endif

#endif  // FIREBOT__MSG__DETAIL__MOTOR_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
