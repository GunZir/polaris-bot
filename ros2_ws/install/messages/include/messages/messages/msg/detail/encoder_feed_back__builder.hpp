// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/EncoderFeedBack.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/encoder_feed_back__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_EncoderFeedBack_enc_left_wheel
{
public:
  explicit Init_EncoderFeedBack_enc_left_wheel(::messages::msg::EncoderFeedBack & msg)
  : msg_(msg)
  {}
  ::messages::msg::EncoderFeedBack enc_left_wheel(::messages::msg::EncoderFeedBack::_enc_left_wheel_type arg)
  {
    msg_.enc_left_wheel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::EncoderFeedBack msg_;
};

class Init_EncoderFeedBack_enc_right_wheel
{
public:
  Init_EncoderFeedBack_enc_right_wheel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EncoderFeedBack_enc_left_wheel enc_right_wheel(::messages::msg::EncoderFeedBack::_enc_right_wheel_type arg)
  {
    msg_.enc_right_wheel = std::move(arg);
    return Init_EncoderFeedBack_enc_left_wheel(msg_);
  }

private:
  ::messages::msg::EncoderFeedBack msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::EncoderFeedBack>()
{
  return messages::msg::builder::Init_EncoderFeedBack_enc_right_wheel();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__BUILDER_HPP_
