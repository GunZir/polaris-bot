// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from services:srv/TestService.idl
// generated code does not contain a copyright notice

#ifndef SERVICES__SRV__DETAIL__TEST_SERVICE__TRAITS_HPP_
#define SERVICES__SRV__DETAIL__TEST_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "services/srv/detail/test_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace services
{

namespace srv
{

inline void to_flow_style_yaml(
  const TestService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TestService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TestService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace services

namespace rosidl_generator_traits
{

[[deprecated("use services::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const services::srv::TestService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  services::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use services::srv::to_yaml() instead")]]
inline std::string to_yaml(const services::srv::TestService_Request & msg)
{
  return services::srv::to_yaml(msg);
}

template<>
inline const char * data_type<services::srv::TestService_Request>()
{
  return "services::srv::TestService_Request";
}

template<>
inline const char * name<services::srv::TestService_Request>()
{
  return "services/srv/TestService_Request";
}

template<>
struct has_fixed_size<services::srv::TestService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<services::srv::TestService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<services::srv::TestService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace services
{

namespace srv
{

inline void to_flow_style_yaml(
  const TestService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: c
  {
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TestService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TestService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace services

namespace rosidl_generator_traits
{

[[deprecated("use services::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const services::srv::TestService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  services::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use services::srv::to_yaml() instead")]]
inline std::string to_yaml(const services::srv::TestService_Response & msg)
{
  return services::srv::to_yaml(msg);
}

template<>
inline const char * data_type<services::srv::TestService_Response>()
{
  return "services::srv::TestService_Response";
}

template<>
inline const char * name<services::srv::TestService_Response>()
{
  return "services/srv/TestService_Response";
}

template<>
struct has_fixed_size<services::srv::TestService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<services::srv::TestService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<services::srv::TestService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<services::srv::TestService>()
{
  return "services::srv::TestService";
}

template<>
inline const char * name<services::srv::TestService>()
{
  return "services/srv/TestService";
}

template<>
struct has_fixed_size<services::srv::TestService>
  : std::integral_constant<
    bool,
    has_fixed_size<services::srv::TestService_Request>::value &&
    has_fixed_size<services::srv::TestService_Response>::value
  >
{
};

template<>
struct has_bounded_size<services::srv::TestService>
  : std::integral_constant<
    bool,
    has_bounded_size<services::srv::TestService_Request>::value &&
    has_bounded_size<services::srv::TestService_Response>::value
  >
{
};

template<>
struct is_service<services::srv::TestService>
  : std::true_type
{
};

template<>
struct is_service_request<services::srv::TestService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<services::srv::TestService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SERVICES__SRV__DETAIL__TEST_SERVICE__TRAITS_HPP_
