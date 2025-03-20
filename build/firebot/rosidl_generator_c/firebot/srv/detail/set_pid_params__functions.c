// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from firebot:srv/SetPIDParams.idl
// generated code does not contain a copyright notice
#include "firebot/srv/detail/set_pid_params__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
firebot__srv__SetPIDParams_Request__init(firebot__srv__SetPIDParams_Request * msg)
{
  if (!msg) {
    return false;
  }
  // kp
  // ki
  // kd
  return true;
}

void
firebot__srv__SetPIDParams_Request__fini(firebot__srv__SetPIDParams_Request * msg)
{
  if (!msg) {
    return;
  }
  // kp
  // ki
  // kd
}

bool
firebot__srv__SetPIDParams_Request__are_equal(const firebot__srv__SetPIDParams_Request * lhs, const firebot__srv__SetPIDParams_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // kp
  if (lhs->kp != rhs->kp) {
    return false;
  }
  // ki
  if (lhs->ki != rhs->ki) {
    return false;
  }
  // kd
  if (lhs->kd != rhs->kd) {
    return false;
  }
  return true;
}

bool
firebot__srv__SetPIDParams_Request__copy(
  const firebot__srv__SetPIDParams_Request * input,
  firebot__srv__SetPIDParams_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // kp
  output->kp = input->kp;
  // ki
  output->ki = input->ki;
  // kd
  output->kd = input->kd;
  return true;
}

firebot__srv__SetPIDParams_Request *
firebot__srv__SetPIDParams_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__srv__SetPIDParams_Request * msg = (firebot__srv__SetPIDParams_Request *)allocator.allocate(sizeof(firebot__srv__SetPIDParams_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(firebot__srv__SetPIDParams_Request));
  bool success = firebot__srv__SetPIDParams_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
firebot__srv__SetPIDParams_Request__destroy(firebot__srv__SetPIDParams_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    firebot__srv__SetPIDParams_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
firebot__srv__SetPIDParams_Request__Sequence__init(firebot__srv__SetPIDParams_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__srv__SetPIDParams_Request * data = NULL;

  if (size) {
    data = (firebot__srv__SetPIDParams_Request *)allocator.zero_allocate(size, sizeof(firebot__srv__SetPIDParams_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = firebot__srv__SetPIDParams_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        firebot__srv__SetPIDParams_Request__fini(&data[i - 1]);
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
firebot__srv__SetPIDParams_Request__Sequence__fini(firebot__srv__SetPIDParams_Request__Sequence * array)
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
      firebot__srv__SetPIDParams_Request__fini(&array->data[i]);
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

firebot__srv__SetPIDParams_Request__Sequence *
firebot__srv__SetPIDParams_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__srv__SetPIDParams_Request__Sequence * array = (firebot__srv__SetPIDParams_Request__Sequence *)allocator.allocate(sizeof(firebot__srv__SetPIDParams_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = firebot__srv__SetPIDParams_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
firebot__srv__SetPIDParams_Request__Sequence__destroy(firebot__srv__SetPIDParams_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    firebot__srv__SetPIDParams_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
firebot__srv__SetPIDParams_Request__Sequence__are_equal(const firebot__srv__SetPIDParams_Request__Sequence * lhs, const firebot__srv__SetPIDParams_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!firebot__srv__SetPIDParams_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
firebot__srv__SetPIDParams_Request__Sequence__copy(
  const firebot__srv__SetPIDParams_Request__Sequence * input,
  firebot__srv__SetPIDParams_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(firebot__srv__SetPIDParams_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    firebot__srv__SetPIDParams_Request * data =
      (firebot__srv__SetPIDParams_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!firebot__srv__SetPIDParams_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          firebot__srv__SetPIDParams_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!firebot__srv__SetPIDParams_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
firebot__srv__SetPIDParams_Response__init(firebot__srv__SetPIDParams_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    firebot__srv__SetPIDParams_Response__fini(msg);
    return false;
  }
  return true;
}

void
firebot__srv__SetPIDParams_Response__fini(firebot__srv__SetPIDParams_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
firebot__srv__SetPIDParams_Response__are_equal(const firebot__srv__SetPIDParams_Response * lhs, const firebot__srv__SetPIDParams_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
firebot__srv__SetPIDParams_Response__copy(
  const firebot__srv__SetPIDParams_Response * input,
  firebot__srv__SetPIDParams_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

firebot__srv__SetPIDParams_Response *
firebot__srv__SetPIDParams_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__srv__SetPIDParams_Response * msg = (firebot__srv__SetPIDParams_Response *)allocator.allocate(sizeof(firebot__srv__SetPIDParams_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(firebot__srv__SetPIDParams_Response));
  bool success = firebot__srv__SetPIDParams_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
firebot__srv__SetPIDParams_Response__destroy(firebot__srv__SetPIDParams_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    firebot__srv__SetPIDParams_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
firebot__srv__SetPIDParams_Response__Sequence__init(firebot__srv__SetPIDParams_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__srv__SetPIDParams_Response * data = NULL;

  if (size) {
    data = (firebot__srv__SetPIDParams_Response *)allocator.zero_allocate(size, sizeof(firebot__srv__SetPIDParams_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = firebot__srv__SetPIDParams_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        firebot__srv__SetPIDParams_Response__fini(&data[i - 1]);
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
firebot__srv__SetPIDParams_Response__Sequence__fini(firebot__srv__SetPIDParams_Response__Sequence * array)
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
      firebot__srv__SetPIDParams_Response__fini(&array->data[i]);
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

firebot__srv__SetPIDParams_Response__Sequence *
firebot__srv__SetPIDParams_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firebot__srv__SetPIDParams_Response__Sequence * array = (firebot__srv__SetPIDParams_Response__Sequence *)allocator.allocate(sizeof(firebot__srv__SetPIDParams_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = firebot__srv__SetPIDParams_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
firebot__srv__SetPIDParams_Response__Sequence__destroy(firebot__srv__SetPIDParams_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    firebot__srv__SetPIDParams_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
firebot__srv__SetPIDParams_Response__Sequence__are_equal(const firebot__srv__SetPIDParams_Response__Sequence * lhs, const firebot__srv__SetPIDParams_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!firebot__srv__SetPIDParams_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
firebot__srv__SetPIDParams_Response__Sequence__copy(
  const firebot__srv__SetPIDParams_Response__Sequence * input,
  firebot__srv__SetPIDParams_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(firebot__srv__SetPIDParams_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    firebot__srv__SetPIDParams_Response * data =
      (firebot__srv__SetPIDParams_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!firebot__srv__SetPIDParams_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          firebot__srv__SetPIDParams_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!firebot__srv__SetPIDParams_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
