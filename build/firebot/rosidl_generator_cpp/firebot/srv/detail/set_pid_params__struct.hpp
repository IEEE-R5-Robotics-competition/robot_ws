// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from firebot:srv/SetPIDParams.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__SRV__DETAIL__SET_PID_PARAMS__STRUCT_HPP_
#define FIREBOT__SRV__DETAIL__SET_PID_PARAMS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__firebot__srv__SetPIDParams_Request __attribute__((deprecated))
#else
# define DEPRECATED__firebot__srv__SetPIDParams_Request __declspec(deprecated)
#endif

namespace firebot
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetPIDParams_Request_
{
  using Type = SetPIDParams_Request_<ContainerAllocator>;

  explicit SetPIDParams_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->kp = 0.0;
      this->ki = 0.0;
      this->kd = 0.0;
    }
  }

  explicit SetPIDParams_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->kp = 0.0;
      this->ki = 0.0;
      this->kd = 0.0;
    }
  }

  // field types and members
  using _kp_type =
    double;
  _kp_type kp;
  using _ki_type =
    double;
  _ki_type ki;
  using _kd_type =
    double;
  _kd_type kd;

  // setters for named parameter idiom
  Type & set__kp(
    const double & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__ki(
    const double & _arg)
  {
    this->ki = _arg;
    return *this;
  }
  Type & set__kd(
    const double & _arg)
  {
    this->kd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    firebot::srv::SetPIDParams_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const firebot::srv::SetPIDParams_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<firebot::srv::SetPIDParams_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<firebot::srv::SetPIDParams_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      firebot::srv::SetPIDParams_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<firebot::srv::SetPIDParams_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      firebot::srv::SetPIDParams_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<firebot::srv::SetPIDParams_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<firebot::srv::SetPIDParams_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<firebot::srv::SetPIDParams_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__firebot__srv__SetPIDParams_Request
    std::shared_ptr<firebot::srv::SetPIDParams_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__firebot__srv__SetPIDParams_Request
    std::shared_ptr<firebot::srv::SetPIDParams_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPIDParams_Request_ & other) const
  {
    if (this->kp != other.kp) {
      return false;
    }
    if (this->ki != other.ki) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPIDParams_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPIDParams_Request_

// alias to use template instance with default allocator
using SetPIDParams_Request =
  firebot::srv::SetPIDParams_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace firebot


#ifndef _WIN32
# define DEPRECATED__firebot__srv__SetPIDParams_Response __attribute__((deprecated))
#else
# define DEPRECATED__firebot__srv__SetPIDParams_Response __declspec(deprecated)
#endif

namespace firebot
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetPIDParams_Response_
{
  using Type = SetPIDParams_Response_<ContainerAllocator>;

  explicit SetPIDParams_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetPIDParams_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    firebot::srv::SetPIDParams_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const firebot::srv::SetPIDParams_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<firebot::srv::SetPIDParams_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<firebot::srv::SetPIDParams_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      firebot::srv::SetPIDParams_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<firebot::srv::SetPIDParams_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      firebot::srv::SetPIDParams_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<firebot::srv::SetPIDParams_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<firebot::srv::SetPIDParams_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<firebot::srv::SetPIDParams_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__firebot__srv__SetPIDParams_Response
    std::shared_ptr<firebot::srv::SetPIDParams_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__firebot__srv__SetPIDParams_Response
    std::shared_ptr<firebot::srv::SetPIDParams_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPIDParams_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPIDParams_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPIDParams_Response_

// alias to use template instance with default allocator
using SetPIDParams_Response =
  firebot::srv::SetPIDParams_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace firebot

namespace firebot
{

namespace srv
{

struct SetPIDParams
{
  using Request = firebot::srv::SetPIDParams_Request;
  using Response = firebot::srv::SetPIDParams_Response;
};

}  // namespace srv

}  // namespace firebot

#endif  // FIREBOT__SRV__DETAIL__SET_PID_PARAMS__STRUCT_HPP_
