// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from firebot:msg/EncoderData.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__MSG__DETAIL__ENCODER_DATA__BUILDER_HPP_
#define FIREBOT__MSG__DETAIL__ENCODER_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "firebot/msg/detail/encoder_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace firebot
{

namespace msg
{


}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::firebot::msg::EncoderData>()
{
  return ::firebot::msg::EncoderData(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace firebot

#endif  // FIREBOT__MSG__DETAIL__ENCODER_DATA__BUILDER_HPP_
