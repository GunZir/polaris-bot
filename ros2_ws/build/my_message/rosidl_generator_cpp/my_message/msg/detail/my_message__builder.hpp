// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_message:msg/MyMessage.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGE__MSG__DETAIL__MY_MESSAGE__BUILDER_HPP_
#define MY_MESSAGE__MSG__DETAIL__MY_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_message/msg/detail/my_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_message
{

namespace msg
{

namespace builder
{

class Init_MyMessage_prad
{
public:
  explicit Init_MyMessage_prad(::my_message::msg::MyMessage & msg)
  : msg_(msg)
  {}
  ::my_message::msg::MyMessage prad(::my_message::msg::MyMessage::_prad_type arg)
  {
    msg_.prad = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_message::msg::MyMessage msg_;
};

class Init_MyMessage_ice
{
public:
  Init_MyMessage_ice()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyMessage_prad ice(::my_message::msg::MyMessage::_ice_type arg)
  {
    msg_.ice = std::move(arg);
    return Init_MyMessage_prad(msg_);
  }

private:
  ::my_message::msg::MyMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_message::msg::MyMessage>()
{
  return my_message::msg::builder::Init_MyMessage_ice();
}

}  // namespace my_message

#endif  // MY_MESSAGE__MSG__DETAIL__MY_MESSAGE__BUILDER_HPP_
