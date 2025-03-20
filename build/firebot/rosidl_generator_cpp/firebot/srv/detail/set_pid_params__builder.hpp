// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from firebot:srv/SetPIDParams.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__SRV__DETAIL__SET_PID_PARAMS__BUILDER_HPP_
#define FIREBOT__SRV__DETAIL__SET_PID_PARAMS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "firebot/srv/detail/set_pid_params__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace firebot
{

namespace srv
{

namespace builder
{

class Init_SetPIDParams_Request_kd
{
public:
  explicit Init_SetPIDParams_Request_kd(::firebot::srv::SetPIDParams_Request & msg)
  : msg_(msg)
  {}
  ::firebot::srv::SetPIDParams_Request kd(::firebot::srv::SetPIDParams_Request::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::firebot::srv::SetPIDParams_Request msg_;
};

class Init_SetPIDParams_Request_ki
{
public:
  explicit Init_SetPIDParams_Request_ki(::firebot::srv::SetPIDParams_Request & msg)
  : msg_(msg)
  {}
  Init_SetPIDParams_Request_kd ki(::firebot::srv::SetPIDParams_Request::_ki_type arg)
  {
    msg_.ki = std::move(arg);
    return Init_SetPIDParams_Request_kd(msg_);
  }

private:
  ::firebot::srv::SetPIDParams_Request msg_;
};

class Init_SetPIDParams_Request_kp
{
public:
  Init_SetPIDParams_Request_kp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPIDParams_Request_ki kp(::firebot::srv::SetPIDParams_Request::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_SetPIDParams_Request_ki(msg_);
  }

private:
  ::firebot::srv::SetPIDParams_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::firebot::srv::SetPIDParams_Request>()
{
  return firebot::srv::builder::Init_SetPIDParams_Request_kp();
}

}  // namespace firebot


namespace firebot
{

namespace srv
{

namespace builder
{

class Init_SetPIDParams_Response_message
{
public:
  explicit Init_SetPIDParams_Response_message(::firebot::srv::SetPIDParams_Response & msg)
  : msg_(msg)
  {}
  ::firebot::srv::SetPIDParams_Response message(::firebot::srv::SetPIDParams_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::firebot::srv::SetPIDParams_Response msg_;
};

class Init_SetPIDParams_Response_success
{
public:
  Init_SetPIDParams_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPIDParams_Response_message success(::firebot::srv::SetPIDParams_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetPIDParams_Response_message(msg_);
  }

private:
  ::firebot::srv::SetPIDParams_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::firebot::srv::SetPIDParams_Response>()
{
  return firebot::srv::builder::Init_SetPIDParams_Response_success();
}

}  // namespace firebot

#endif  // FIREBOT__SRV__DETAIL__SET_PID_PARAMS__BUILDER_HPP_
