// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from messages:msg/EncoderFeedBack.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "messages/msg/detail/encoder_feed_back__rosidl_typesupport_introspection_c.h"
#include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "messages/msg/detail/encoder_feed_back__functions.h"
#include "messages/msg/detail/encoder_feed_back__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__msg__EncoderFeedBack__init(message_memory);
}

void messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_fini_function(void * message_memory)
{
  messages__msg__EncoderFeedBack__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_message_member_array[2] = {
  {
    "enc_right_wheel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__msg__EncoderFeedBack, enc_right_wheel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enc_left_wheel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__msg__EncoderFeedBack, enc_left_wheel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_message_members = {
  "messages__msg",  // message namespace
  "EncoderFeedBack",  // message name
  2,  // number of fields
  sizeof(messages__msg__EncoderFeedBack),
  messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_message_member_array,  // message members
  messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_message_type_support_handle = {
  0,
  &messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, msg, EncoderFeedBack)() {
  if (!messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_message_type_support_handle.typesupport_identifier) {
    messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__msg__EncoderFeedBack__rosidl_typesupport_introspection_c__EncoderFeedBack_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
