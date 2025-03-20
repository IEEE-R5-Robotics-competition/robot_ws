// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from firebot:srv/SetPIDParams.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__SRV__DETAIL__SET_PID_PARAMS__TRAITS_HPP_
#define FIREBOT__SRV__DETAIL__SET_PID_PARAMS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "firebot/srv/detail/set_pid_params__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace firebot
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPIDParams_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: kp
  {
    out << "kp: ";
    rosidl_generator_traits::value_to_yaml(msg.kp, out);
    out << ", ";
  }

  // member: ki
  {
    out << "ki: ";
    rosidl_generator_traits::value_to_yaml(msg.ki, out);
    out << ", ";
  }

  // member: kd
  {
    out << "kd: ";
    rosidl_generator_traits::value_to_yaml(msg.kd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPIDParams_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kp: ";
    rosidl_generator_traits::value_to_yaml(msg.kp, out);
    out << "\n";
  }

  // member: ki
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ki: ";
    rosidl_generator_traits::value_to_yaml(msg.ki, out);
    out << "\n";
  }

  // member: kd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kd: ";
    rosidl_generator_traits::value_to_yaml(msg.kd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPIDParams_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace firebot

namespace rosidl_generator_traits
{

[[deprecated("use firebot::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const firebot::srv::SetPIDParams_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  firebot::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use firebot::srv::to_yaml() instead")]]
inline std::string to_yaml(const firebot::srv::SetPIDParams_Request & msg)
{
  return firebot::srv::to_yaml(msg);
}

template<>
inline const char * data_type<firebot::srv::SetPIDParams_Request>()
{
  return "firebot::srv::SetPIDParams_Request";
}

template<>
inline const char * name<firebot::srv::SetPIDParams_Request>()
{
  return "firebot/srv/SetPIDParams_Request";
}

template<>
struct has_fixed_size<firebot::srv::SetPIDParams_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<firebot::srv::SetPIDParams_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<firebot::srv::SetPIDParams_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace firebot
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPIDParams_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPIDParams_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPIDParams_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace firebot

namespace rosidl_generator_traits
{

[[deprecated("use firebot::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const firebot::srv::SetPIDParams_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  firebot::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use firebot::srv::to_yaml() instead")]]
inline std::string to_yaml(const firebot::srv::SetPIDParams_Response & msg)
{
  return firebot::srv::to_yaml(msg);
}

template<>
inline const char * data_type<firebot::srv::SetPIDParams_Response>()
{
  return "firebot::srv::SetPIDParams_Response";
}

template<>
inline const char * name<firebot::srv::SetPIDParams_Response>()
{
  return "firebot/srv/SetPIDParams_Response";
}

template<>
struct has_fixed_size<firebot::srv::SetPIDParams_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<firebot::srv::SetPIDParams_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<firebot::srv::SetPIDParams_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<firebot::srv::SetPIDParams>()
{
  return "firebot::srv::SetPIDParams";
}

template<>
inline const char * name<firebot::srv::SetPIDParams>()
{
  return "firebot/srv/SetPIDParams";
}

template<>
struct has_fixed_size<firebot::srv::SetPIDParams>
  : std::integral_constant<
    bool,
    has_fixed_size<firebot::srv::SetPIDParams_Request>::value &&
    has_fixed_size<firebot::srv::SetPIDParams_Response>::value
  >
{
};

template<>
struct has_bounded_size<firebot::srv::SetPIDParams>
  : std::integral_constant<
    bool,
    has_bounded_size<firebot::srv::SetPIDParams_Request>::value &&
    has_bounded_size<firebot::srv::SetPIDParams_Response>::value
  >
{
};

template<>
struct is_service<firebot::srv::SetPIDParams>
  : std::true_type
{
};

template<>
struct is_service_request<firebot::srv::SetPIDParams_Request>
  : std::true_type
{
};

template<>
struct is_service_response<firebot::srv::SetPIDParams_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FIREBOT__SRV__DETAIL__SET_PID_PARAMS__TRAITS_HPP_
