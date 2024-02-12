// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_message:msg/MyMessage.idl
// generated code does not contain a copyright notice
#include "my_message/msg/detail/my_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_message__msg__MyMessage__init(my_message__msg__MyMessage * msg)
{
  if (!msg) {
    return false;
  }
  // ice
  // prad
  return true;
}

void
my_message__msg__MyMessage__fini(my_message__msg__MyMessage * msg)
{
  if (!msg) {
    return;
  }
  // ice
  // prad
}

bool
my_message__msg__MyMessage__are_equal(const my_message__msg__MyMessage * lhs, const my_message__msg__MyMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ice
  if (lhs->ice != rhs->ice) {
    return false;
  }
  // prad
  if (lhs->prad != rhs->prad) {
    return false;
  }
  return true;
}

bool
my_message__msg__MyMessage__copy(
  const my_message__msg__MyMessage * input,
  my_message__msg__MyMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // ice
  output->ice = input->ice;
  // prad
  output->prad = input->prad;
  return true;
}

my_message__msg__MyMessage *
my_message__msg__MyMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_message__msg__MyMessage * msg = (my_message__msg__MyMessage *)allocator.allocate(sizeof(my_message__msg__MyMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_message__msg__MyMessage));
  bool success = my_message__msg__MyMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_message__msg__MyMessage__destroy(my_message__msg__MyMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_message__msg__MyMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_message__msg__MyMessage__Sequence__init(my_message__msg__MyMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_message__msg__MyMessage * data = NULL;

  if (size) {
    data = (my_message__msg__MyMessage *)allocator.zero_allocate(size, sizeof(my_message__msg__MyMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_message__msg__MyMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_message__msg__MyMessage__fini(&data[i - 1]);
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
my_message__msg__MyMessage__Sequence__fini(my_message__msg__MyMessage__Sequence * array)
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
      my_message__msg__MyMessage__fini(&array->data[i]);
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

my_message__msg__MyMessage__Sequence *
my_message__msg__MyMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_message__msg__MyMessage__Sequence * array = (my_message__msg__MyMessage__Sequence *)allocator.allocate(sizeof(my_message__msg__MyMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_message__msg__MyMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_message__msg__MyMessage__Sequence__destroy(my_message__msg__MyMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_message__msg__MyMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_message__msg__MyMessage__Sequence__are_equal(const my_message__msg__MyMessage__Sequence * lhs, const my_message__msg__MyMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_message__msg__MyMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_message__msg__MyMessage__Sequence__copy(
  const my_message__msg__MyMessage__Sequence * input,
  my_message__msg__MyMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_message__msg__MyMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_message__msg__MyMessage * data =
      (my_message__msg__MyMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_message__msg__MyMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_message__msg__MyMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_message__msg__MyMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
