// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from services:srv/TestService.idl
// generated code does not contain a copyright notice
#include "services/srv/detail/test_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
services__srv__TestService_Request__init(services__srv__TestService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // a
  // b
  return true;
}

void
services__srv__TestService_Request__fini(services__srv__TestService_Request * msg)
{
  if (!msg) {
    return;
  }
  // a
  // b
}

bool
services__srv__TestService_Request__are_equal(const services__srv__TestService_Request * lhs, const services__srv__TestService_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // a
  if (lhs->a != rhs->a) {
    return false;
  }
  // b
  if (lhs->b != rhs->b) {
    return false;
  }
  return true;
}

bool
services__srv__TestService_Request__copy(
  const services__srv__TestService_Request * input,
  services__srv__TestService_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // a
  output->a = input->a;
  // b
  output->b = input->b;
  return true;
}

services__srv__TestService_Request *
services__srv__TestService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  services__srv__TestService_Request * msg = (services__srv__TestService_Request *)allocator.allocate(sizeof(services__srv__TestService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(services__srv__TestService_Request));
  bool success = services__srv__TestService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
services__srv__TestService_Request__destroy(services__srv__TestService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    services__srv__TestService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
services__srv__TestService_Request__Sequence__init(services__srv__TestService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  services__srv__TestService_Request * data = NULL;

  if (size) {
    data = (services__srv__TestService_Request *)allocator.zero_allocate(size, sizeof(services__srv__TestService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = services__srv__TestService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        services__srv__TestService_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
services__srv__TestService_Request__Sequence__fini(services__srv__TestService_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      services__srv__TestService_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

services__srv__TestService_Request__Sequence *
services__srv__TestService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  services__srv__TestService_Request__Sequence * array = (services__srv__TestService_Request__Sequence *)allocator.allocate(sizeof(services__srv__TestService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = services__srv__TestService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
services__srv__TestService_Request__Sequence__destroy(services__srv__TestService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    services__srv__TestService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
services__srv__TestService_Request__Sequence__are_equal(const services__srv__TestService_Request__Sequence * lhs, const services__srv__TestService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!services__srv__TestService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
services__srv__TestService_Request__Sequence__copy(
  const services__srv__TestService_Request__Sequence * input,
  services__srv__TestService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(services__srv__TestService_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    services__srv__TestService_Request * data =
      (services__srv__TestService_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!services__srv__TestService_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          services__srv__TestService_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!services__srv__TestService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
services__srv__TestService_Response__init(services__srv__TestService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // c
  return true;
}

void
services__srv__TestService_Response__fini(services__srv__TestService_Response * msg)
{
  if (!msg) {
    return;
  }
  // c
}

bool
services__srv__TestService_Response__are_equal(const services__srv__TestService_Response * lhs, const services__srv__TestService_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // c
  if (lhs->c != rhs->c) {
    return false;
  }
  return true;
}

bool
services__srv__TestService_Response__copy(
  const services__srv__TestService_Response * input,
  services__srv__TestService_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // c
  output->c = input->c;
  return true;
}

services__srv__TestService_Response *
services__srv__TestService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  services__srv__TestService_Response * msg = (services__srv__TestService_Response *)allocator.allocate(sizeof(services__srv__TestService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(services__srv__TestService_Response));
  bool success = services__srv__TestService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
services__srv__TestService_Response__destroy(services__srv__TestService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    services__srv__TestService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
services__srv__TestService_Response__Sequence__init(services__srv__TestService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  services__srv__TestService_Response * data = NULL;

  if (size) {
    data = (services__srv__TestService_Response *)allocator.zero_allocate(size, sizeof(services__srv__TestService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = services__srv__TestService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        services__srv__TestService_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
services__srv__TestService_Response__Sequence__fini(services__srv__TestService_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      services__srv__TestService_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

services__srv__TestService_Response__Sequence *
services__srv__TestService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  services__srv__TestService_Response__Sequence * array = (services__srv__TestService_Response__Sequence *)allocator.allocate(sizeof(services__srv__TestService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = services__srv__TestService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
services__srv__TestService_Response__Sequence__destroy(services__srv__TestService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    services__srv__TestService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
services__srv__TestService_Response__Sequence__are_equal(const services__srv__TestService_Response__Sequence * lhs, const services__srv__TestService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!services__srv__TestService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
services__srv__TestService_Response__Sequence__copy(
  const services__srv__TestService_Response__Sequence * input,
  services__srv__TestService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(services__srv__TestService_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    services__srv__TestService_Response * data =
      (services__srv__TestService_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!services__srv__TestService_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          services__srv__TestService_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!services__srv__TestService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
