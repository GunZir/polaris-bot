// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_message:msg/MyMessage.idl
// generated code does not contain a copyright notice

#ifndef MY_MESSAGE__MSG__DETAIL__MY_MESSAGE__TRAITS_HPP_
#define MY_MESSAGE__MSG__DETAIL__MY_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_message/msg/detail/my_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_message
{

namespace msg
{

inline void to_flow_style_yaml(
  const MyMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: ice
  {
    out << "ice: ";
    rosidl_generator_traits::value_to_yaml(msg.ice, out);
    out << ", ";
  }

  // member: prad
  {
    out << "prad: ";
    rosidl_generator_traits::value_to_yaml(msg.prad, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ice
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ice: ";
    rosidl_generator_traits::value_to_yaml(msg.ice, out);
    out << "\n";
  }

  // member: prad
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prad: ";
    rosidl_generator_traits::value_to_yaml(msg.prad, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyMessage & msg, bool use_flow_style = false)
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

}  // namespace my_message

namespace rosidl_generator_traits
{

[[deprecated("use my_message::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_message::msg::MyMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_message::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_message::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_message::msg::MyMessage & msg)
{
  return my_message::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_message::msg::MyMessage>()
{
  return "my_message::msg::MyMessage";
}

template<>
inline const char * name<my_message::msg::MyMessage>()
{
  return "my_message/msg/MyMessage";
}

template<>
struct has_fixed_size<my_message::msg::MyMessage>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_message::msg::MyMessage>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_message::msg::MyMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_MESSAGE__MSG__DETAIL__MY_MESSAGE__TRAITS_HPP_
