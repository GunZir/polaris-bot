// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/EncoderFeedBack.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__msg__EncoderFeedBack __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__EncoderFeedBack __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EncoderFeedBack_
{
  using Type = EncoderFeedBack_<ContainerAllocator>;

  explicit EncoderFeedBack_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enc_right_wheel = 0l;
      this->enc_left_wheel = 0l;
    }
  }

  explicit EncoderFeedBack_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enc_right_wheel = 0l;
      this->enc_left_wheel = 0l;
    }
  }

  // field types and members
  using _enc_right_wheel_type =
    int32_t;
  _enc_right_wheel_type enc_right_wheel;
  using _enc_left_wheel_type =
    int32_t;
  _enc_left_wheel_type enc_left_wheel;

  // setters for named parameter idiom
  Type & set__enc_right_wheel(
    const int32_t & _arg)
  {
    this->enc_right_wheel = _arg;
    return *this;
  }
  Type & set__enc_left_wheel(
    const int32_t & _arg)
  {
    this->enc_left_wheel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::EncoderFeedBack_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::EncoderFeedBack_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::EncoderFeedBack_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::EncoderFeedBack_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::EncoderFeedBack_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::EncoderFeedBack_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::EncoderFeedBack_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::EncoderFeedBack_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::EncoderFeedBack_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::EncoderFeedBack_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__EncoderFeedBack
    std::shared_ptr<messages::msg::EncoderFeedBack_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__EncoderFeedBack
    std::shared_ptr<messages::msg::EncoderFeedBack_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EncoderFeedBack_ & other) const
  {
    if (this->enc_right_wheel != other.enc_right_wheel) {
      return false;
    }
    if (this->enc_left_wheel != other.enc_left_wheel) {
      return false;
    }
    return true;
  }
  bool operator!=(const EncoderFeedBack_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EncoderFeedBack_

// alias to use template instance with default allocator
using EncoderFeedBack =
  messages::msg::EncoderFeedBack_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__STRUCT_HPP_
