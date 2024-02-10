// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from services:srv/TestService.idl
// generated code does not contain a copyright notice

#ifndef SERVICES__SRV__DETAIL__TEST_SERVICE__STRUCT_H_
#define SERVICES__SRV__DETAIL__TEST_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TestService in the package services.
typedef struct services__srv__TestService_Request
{
  int32_t a;
  int32_t b;
} services__srv__TestService_Request;

// Struct for a sequence of services__srv__TestService_Request.
typedef struct services__srv__TestService_Request__Sequence
{
  services__srv__TestService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} services__srv__TestService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TestService in the package services.
typedef struct services__srv__TestService_Response
{
  int32_t c;
} services__srv__TestService_Response;

// Struct for a sequence of services__srv__TestService_Response.
typedef struct services__srv__TestService_Response__Sequence
{
  services__srv__TestService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} services__srv__TestService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVICES__SRV__DETAIL__TEST_SERVICE__STRUCT_H_
