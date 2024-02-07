// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/RobotMotorSpeed.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/robot_motor_speed__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_RobotMotorSpeed_left_motor_speed
{
public:
  explicit Init_RobotMotorSpeed_left_motor_speed(::messages::msg::RobotMotorSpeed & msg)
  : msg_(msg)
  {}
  ::messages::msg::RobotMotorSpeed left_motor_speed(::messages::msg::RobotMotorSpeed::_left_motor_speed_type arg)
  {
    msg_.left_motor_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::RobotMotorSpeed msg_;
};

class Init_RobotMotorSpeed_right_motor_speed
{
public:
  Init_RobotMotorSpeed_right_motor_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMotorSpeed_left_motor_speed right_motor_speed(::messages::msg::RobotMotorSpeed::_right_motor_speed_type arg)
  {
    msg_.right_motor_speed = std::move(arg);
    return Init_RobotMotorSpeed_left_motor_speed(msg_);
  }

private:
  ::messages::msg::RobotMotorSpeed msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::RobotMotorSpeed>()
{
  return messages::msg::builder::Init_RobotMotorSpeed_right_motor_speed();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__BUILDER_HPP_
