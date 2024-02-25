// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/EncoderFeedBack.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__STRUCT_H_
#define MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EncoderFeedBack in the package messages.
typedef struct messages__msg__EncoderFeedBack
{
  int32_t enc_right_wheel;
  int32_t enc_left_wheel;
} messages__msg__EncoderFeedBack;

// Struct for a sequence of messages__msg__EncoderFeedBack.
typedef struct messages__msg__EncoderFeedBack__Sequence
{
  messages__msg__EncoderFeedBack * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__EncoderFeedBack__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__ENCODER_FEED_BACK__STRUCT_H_
