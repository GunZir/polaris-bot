// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/EncoderFeedBack.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/encoder_feed_back__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const EncoderFeedBack & msg,
  std::ostream & out)
{
  out << "{";
  // member: enc_right_wheel
  {
    out << "enc_right_wheel: ";
    rosidl_generator_traits::value_to_yaml(msg.enc_right_wheel, out);
    out << ", ";
  }

  // member: enc_left_wheel
  {
    out << "enc_left_wheel: ";
    rosidl_generator_traits::value_to_yaml(msg.enc_left_wheel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EncoderFeedBack & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: enc_right_wheel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enc_right_wheel: ";
    rosidl_generator_traits::value_to_yaml(msg.enc_right_wheel, out);
    out << "\n";
  }

  // member: enc_left_wheel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enc_left_wheel: ";
    rosidl_generator_traits::value_to_yaml(msg.enc_left_wheel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EncoderFeedBack & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::msg::EncoderFeedBack & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::EncoderFeedBack & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::EncoderFeedBack>()
{
  return "messages::msg::EncoderFeedBack";
}

template<>
inline const char * name<messages::msg::EncoderFeedBack>()
{
  return "messages/msg/EncoderFeedBack";
}

template<>
struct has_fixed_size<messages::msg::EncoderFeedBack>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<messages::msg::EncoderFeedBack>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<messages::msg::EncoderFeedBack>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__TRAITS_HPP_
