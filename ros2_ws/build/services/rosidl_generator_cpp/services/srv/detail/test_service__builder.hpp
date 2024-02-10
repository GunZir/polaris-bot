// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from services:srv/TestService.idl
// generated code does not contain a copyright notice

#ifndef SERVICES__SRV__DETAIL__TEST_SERVICE__BUILDER_HPP_
#define SERVICES__SRV__DETAIL__TEST_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "services/srv/detail/test_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace services
{

namespace srv
{

namespace builder
{

class Init_TestService_Request_b
{
public:
  explicit Init_TestService_Request_b(::services::srv::TestService_Request & msg)
  : msg_(msg)
  {}
  ::services::srv::TestService_Request b(::services::srv::TestService_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::services::srv::TestService_Request msg_;
};

class Init_TestService_Request_a
{
public:
  Init_TestService_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TestService_Request_b a(::services::srv::TestService_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_TestService_Request_b(msg_);
  }

private:
  ::services::srv::TestService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::services::srv::TestService_Request>()
{
  return services::srv::builder::Init_TestService_Request_a();
}

}  // namespace services


namespace services
{

namespace srv
{

namespace builder
{

class Init_TestService_Response_c
{
public:
  Init_TestService_Response_c()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::services::srv::TestService_Response c(::services::srv::TestService_Response::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::services::srv::TestService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::services::srv::TestService_Response>()
{
  return services::srv::builder::Init_TestService_Response_c();
}

}  // namespace services

#endif  // SERVICES__SRV__DETAIL__TEST_SERVICE__BUILDER_HPP_
