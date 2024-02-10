// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from services:srv/TestService.idl
// generated code does not contain a copyright notice

#ifndef SERVICES__SRV__DETAIL__TEST_SERVICE__STRUCT_HPP_
#define SERVICES__SRV__DETAIL__TEST_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__services__srv__TestService_Request __attribute__((deprecated))
#else
# define DEPRECATED__services__srv__TestService_Request __declspec(deprecated)
#endif

namespace services
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TestService_Request_
{
  using Type = TestService_Request_<ContainerAllocator>;

  explicit TestService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0l;
      this->b = 0l;
    }
  }

  explicit TestService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->a = 0l;
      this->b = 0l;
    }
  }

  // field types and members
  using _a_type =
    int32_t;
  _a_type a;
  using _b_type =
    int32_t;
  _b_type b;

  // setters for named parameter idiom
  Type & set__a(
    const int32_t & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const int32_t & _arg)
  {
    this->b = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    services::srv::TestService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const services::srv::TestService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<services::srv::TestService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<services::srv::TestService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      services::srv::TestService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<services::srv::TestService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      services::srv::TestService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<services::srv::TestService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<services::srv::TestService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<services::srv::TestService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__services__srv__TestService_Request
    std::shared_ptr<services::srv::TestService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__services__srv__TestService_Request
    std::shared_ptr<services::srv::TestService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TestService_Request_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    return true;
  }
  bool operator!=(const TestService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TestService_Request_

// alias to use template instance with default allocator
using TestService_Request =
  services::srv::TestService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace services


#ifndef _WIN32
# define DEPRECATED__services__srv__TestService_Response __attribute__((deprecated))
#else
# define DEPRECATED__services__srv__TestService_Response __declspec(deprecated)
#endif

namespace services
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TestService_Response_
{
  using Type = TestService_Response_<ContainerAllocator>;

  explicit TestService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->c = 0l;
    }
  }

  explicit TestService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->c = 0l;
    }
  }

  // field types and members
  using _c_type =
    int32_t;
  _c_type c;

  // setters for named parameter idiom
  Type & set__c(
    const int32_t & _arg)
  {
    this->c = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    services::srv::TestService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const services::srv::TestService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<services::srv::TestService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<services::srv::TestService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      services::srv::TestService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<services::srv::TestService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      services::srv::TestService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<services::srv::TestService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<services::srv::TestService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<services::srv::TestService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__services__srv__TestService_Response
    std::shared_ptr<services::srv::TestService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__services__srv__TestService_Response
    std::shared_ptr<services::srv::TestService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TestService_Response_ & other) const
  {
    if (this->c != other.c) {
      return false;
    }
    return true;
  }
  bool operator!=(const TestService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TestService_Response_

// alias to use template instance with default allocator
using TestService_Response =
  services::srv::TestService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace services

namespace services
{

namespace srv
{

struct TestService
{
  using Request = services::srv::TestService_Request;
  using Response = services::srv::TestService_Response;
};

}  // namespace srv

}  // namespace services

#endif  // SERVICES__SRV__DETAIL__TEST_SERVICE__STRUCT_HPP_
