// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/RobotMotorSpeed.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__STRUCT_H_
#define MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RobotMotorSpeed in the package messages.
typedef struct messages__msg__RobotMotorSpeed
{
  int8_t right_motor_speed;
  int8_t left_motor_speed;
} messages__msg__RobotMotorSpeed;

// Struct for a sequence of messages__msg__RobotMotorSpeed.
typedef struct messages__msg__RobotMotorSpeed__Sequence
{
  messages__msg__RobotMotorSpeed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__RobotMotorSpeed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__ROBOT_MOTOR_SPEED__STRUCT_H_
