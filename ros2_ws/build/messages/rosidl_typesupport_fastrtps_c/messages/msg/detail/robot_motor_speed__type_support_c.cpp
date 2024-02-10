// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from messages:msg/RobotMotorSpeed.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/robot_motor_speed__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "messages/msg/detail/robot_motor_speed__struct.h"
#include "messages/msg/detail/robot_motor_speed__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RobotMotorSpeed__ros_msg_type = messages__msg__RobotMotorSpeed;

static bool _RobotMotorSpeed__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotMotorSpeed__ros_msg_type * ros_message = static_cast<const _RobotMotorSpeed__ros_msg_type *>(untyped_ros_message);
  // Field name: right_motor_speed
  {
    cdr << ros_message->right_motor_speed;
  }

  // Field name: left_motor_speed
  {
    cdr << ros_message->left_motor_speed;
  }

  return true;
}

static bool _RobotMotorSpeed__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotMotorSpeed__ros_msg_type * ros_message = static_cast<_RobotMotorSpeed__ros_msg_type *>(untyped_ros_message);
  // Field name: right_motor_speed
  {
    cdr >> ros_message->right_motor_speed;
  }

  // Field name: left_motor_speed
  {
    cdr >> ros_message->left_motor_speed;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t get_serialized_size_messages__msg__RobotMotorSpeed(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotMotorSpeed__ros_msg_type * ros_message = static_cast<const _RobotMotorSpeed__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name right_motor_speed
  {
    size_t item_size = sizeof(ros_message->right_motor_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left_motor_speed
  {
    size_t item_size = sizeof(ros_message->left_motor_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RobotMotorSpeed__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_messages__msg__RobotMotorSpeed(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t max_serialized_size_messages__msg__RobotMotorSpeed(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: right_motor_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: left_motor_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = messages__msg__RobotMotorSpeed;
    is_plain =
      (
      offsetof(DataType, left_motor_speed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _RobotMotorSpeed__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_messages__msg__RobotMotorSpeed(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_RobotMotorSpeed = {
  "messages::msg",
  "RobotMotorSpeed",
  _RobotMotorSpeed__cdr_serialize,
  _RobotMotorSpeed__cdr_deserialize,
  _RobotMotorSpeed__get_serialized_size,
  _RobotMotorSpeed__max_serialized_size
};

static rosidl_message_type_support_t _RobotMotorSpeed__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotMotorSpeed,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, messages, msg, RobotMotorSpeed)() {
  return &_RobotMotorSpeed__type_support;
}

#if defined(__cplusplus)
}
#endif
