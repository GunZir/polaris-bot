// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/MotorRobotSpeed.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__MOTOR_ROBOT_SPEED__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__MOTOR_ROBOT_SPEED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/motor_robot_speed__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_MotorRobotSpeed_left_motor_speed
{
public:
  explicit Init_MotorRobotSpeed_left_motor_speed(::messages::msg::MotorRobotSpeed & msg)
  : msg_(msg)
  {}
  ::messages::msg::MotorRobotSpeed left_motor_speed(::messages::msg::MotorRobotSpeed::_left_motor_speed_type arg)
  {
    msg_.left_motor_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::MotorRobotSpeed msg_;
};

class Init_MotorRobotSpeed_right_motor_speed
{
public:
  Init_MotorRobotSpeed_right_motor_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorRobotSpeed_left_motor_speed right_motor_speed(::messages::msg::MotorRobotSpeed::_right_motor_speed_type arg)
  {
    msg_.right_motor_speed = std::move(arg);
    return Init_MotorRobotSpeed_left_motor_speed(msg_);
  }

private:
  ::messages::msg::MotorRobotSpeed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::MotorRobotSpeed>()
{
  return messages::msg::builder::Init_MotorRobotSpeed_right_motor_speed();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__MOTOR_ROBOT_SPEED__BUILDER_HPP_
