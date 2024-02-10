// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/RobotMotorSpeed.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__msg__RobotMotorSpeed __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__RobotMotorSpeed __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotMotorSpeed_
{
  using Type = RobotMotorSpeed_<ContainerAllocator>;

  explicit RobotMotorSpeed_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->right_motor_speed = 0ul;
      this->left_motor_speed = 0ul;
    }
  }

  explicit RobotMotorSpeed_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->right_motor_speed = 0ul;
      this->left_motor_speed = 0ul;
    }
  }

  // field types and members
  using _right_motor_speed_type =
    uint32_t;
  _right_motor_speed_type right_motor_speed;
  using _left_motor_speed_type =
    uint32_t;
  _left_motor_speed_type left_motor_speed;

  // setters for named parameter idiom
  Type & set__right_motor_speed(
    const uint32_t & _arg)
  {
    this->right_motor_speed = _arg;
    return *this;
  }
  Type & set__left_motor_speed(
    const uint32_t & _arg)
  {
    this->left_motor_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::RobotMotorSpeed_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::RobotMotorSpeed_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::RobotMotorSpeed_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::RobotMotorSpeed_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::RobotMotorSpeed_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::RobotMotorSpeed_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::RobotMotorSpeed_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::RobotMotorSpeed_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::RobotMotorSpeed_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::RobotMotorSpeed_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__RobotMotorSpeed
    std::shared_ptr<messages::msg::RobotMotorSpeed_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__RobotMotorSpeed
    std::shared_ptr<messages::msg::RobotMotorSpeed_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMotorSpeed_ & other) const
  {
    if (this->right_motor_speed != other.right_motor_speed) {
      return false;
    }
    if (this->left_motor_speed != other.left_motor_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMotorSpeed_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMotorSpeed_

// alias to use template instance with default allocator
using RobotMotorSpeed =
  messages::msg::RobotMotorSpeed_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__STRUCT_HPP_
