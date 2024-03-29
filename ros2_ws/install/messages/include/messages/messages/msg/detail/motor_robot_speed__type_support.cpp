// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from messages:msg/MotorRobotSpeed.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "messages/msg/detail/motor_robot_speed__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace messages
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotorRobotSpeed_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) messages::msg::MotorRobotSpeed(_init);
}

void MotorRobotSpeed_fini_function(void * message_memory)
{
  auto typed_message = static_cast<messages::msg::MotorRobotSpeed *>(message_memory);
  typed_message->~MotorRobotSpeed();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorRobotSpeed_message_member_array[2] = {
  {
    "right_motor_speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages::msg::MotorRobotSpeed, right_motor_speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "left_motor_speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages::msg::MotorRobotSpeed, left_motor_speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorRobotSpeed_message_members = {
  "messages::msg",  // message namespace
  "MotorRobotSpeed",  // message name
  2,  // number of fields
  sizeof(messages::msg::MotorRobotSpeed),
  MotorRobotSpeed_message_member_array,  // message members
  MotorRobotSpeed_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorRobotSpeed_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorRobotSpeed_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorRobotSpeed_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace messages


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<messages::msg::MotorRobotSpeed>()
{
  return &::messages::msg::rosidl_typesupport_introspection_cpp::MotorRobotSpeed_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, messages, msg, MotorRobotSpeed)() {
  return &::messages::msg::rosidl_typesupport_introspection_cpp::MotorRobotSpeed_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
