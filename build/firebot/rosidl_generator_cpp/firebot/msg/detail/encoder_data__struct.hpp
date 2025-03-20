// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from firebot:msg/EncoderData.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__MSG__DETAIL__ENCODER_DATA__STRUCT_HPP_
#define FIREBOT__MSG__DETAIL__ENCODER_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__firebot__msg__EncoderData __attribute__((deprecated))
#else
# define DEPRECATED__firebot__msg__EncoderData __declspec(deprecated)
#endif

namespace firebot
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EncoderData_
{
  using Type = EncoderData_<ContainerAllocator>;

  explicit EncoderData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit EncoderData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    firebot::msg::EncoderData_<ContainerAllocator> *;
  using ConstRawPtr =
    const firebot::msg::EncoderData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<firebot::msg::EncoderData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<firebot::msg::EncoderData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      firebot::msg::EncoderData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<firebot::msg::EncoderData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      firebot::msg::EncoderData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<firebot::msg::EncoderData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<firebot::msg::EncoderData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<firebot::msg::EncoderData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__firebot__msg__EncoderData
    std::shared_ptr<firebot::msg::EncoderData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__firebot__msg__EncoderData
    std::shared_ptr<firebot::msg::EncoderData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EncoderData_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const EncoderData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EncoderData_

// alias to use template instance with default allocator
using EncoderData =
  firebot::msg::EncoderData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace firebot

#endif  // FIREBOT__MSG__DETAIL__ENCODER_DATA__STRUCT_HPP_
