// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from firebot:msg/EncoderData.idl
// generated code does not contain a copyright notice
#include "firebot/msg/detail/encoder_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
firebot__msg__EncoderData__init(firebot__msg__EncoderData * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
firebot__msg__EncoderData__fini(firebot__msg__EncoderData * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
firebot__msg__EncoderData__are_equal(const firebot__msg__EncoderData * lhs, const firebot__msg__EncoderData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
firebot__msg__EncoderData__copy(
  const firebot__msg__EncoderData * input,
  firebot__msg__EncoderData * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

firebot__msg__EncoderData *
firebot__msg__EncoderData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__msg__EncoderData * msg = (firebot__msg__EncoderData *)allocator.allocate(sizeof(firebot__msg__EncoderData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(firebot__msg__EncoderData));
  bool success = firebot__msg__EncoderData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
firebot__msg__EncoderData__destroy(firebot__msg__EncoderData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    firebot__msg__EncoderData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
firebot__msg__EncoderData__Sequence__init(firebot__msg__EncoderData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__msg__EncoderData * data = NULL;

  if (size) {
    data = (firebot__msg__EncoderData *)allocator.zero_allocate(size, sizeof(firebot__msg__EncoderData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = firebot__msg__EncoderData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        firebot__msg__EncoderData__fini(&data[i - 1]);
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
firebot__msg__EncoderData__Sequence__fini(firebot__msg__EncoderData__Sequence * array)
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
      firebot__msg__EncoderData__fini(&array->data[i]);
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

firebot__msg__EncoderData__Sequence *
firebot__msg__EncoderData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__msg__EncoderData__Sequence * array = (firebot__msg__EncoderData__Sequence *)allocator.allocate(sizeof(firebot__msg__EncoderData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = firebot__msg__EncoderData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
firebot__msg__EncoderData__Sequence__destroy(firebot__msg__EncoderData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    firebot__msg__EncoderData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
firebot__msg__EncoderData__Sequence__are_equal(const firebot__msg__EncoderData__Sequence * lhs, const firebot__msg__EncoderData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!firebot__msg__EncoderData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
firebot__msg__EncoderData__Sequence__copy(
  const firebot__msg__EncoderData__Sequence * input,
  firebot__msg__EncoderData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(firebot__msg__EncoderData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    firebot__msg__EncoderData * data =
      (firebot__msg__EncoderData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!firebot__msg__EncoderData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          firebot__msg__EncoderData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!firebot__msg__EncoderData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
