// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from firebot:srv/SetPIDParams.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__SRV__DETAIL__SET_PID_PARAMS__FUNCTIONS_H_
#define FIREBOT__SRV__DETAIL__SET_PID_PARAMS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "firebot/msg/rosidl_generator_c__visibility_control.h"

#include "firebot/srv/detail/set_pid_params__struct.h"

/// Initialize srv/SetPIDParams message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * firebot__srv__SetPIDParams_Request
 * )) before or use
 * firebot__srv__SetPIDParams_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Request__init(firebot__srv__SetPIDParams_Request * msg);

/// Finalize srv/SetPIDParams message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
void
firebot__srv__SetPIDParams_Request__fini(firebot__srv__SetPIDParams_Request * msg);

/// Create srv/SetPIDParams message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * firebot__srv__SetPIDParams_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
firebot__srv__SetPIDParams_Request *
firebot__srv__SetPIDParams_Request__create();

/// Destroy srv/SetPIDParams message.
/**
 * It calls
 * firebot__srv__SetPIDParams_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
void
firebot__srv__SetPIDParams_Request__destroy(firebot__srv__SetPIDParams_Request * msg);

/// Check for srv/SetPIDParams message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Request__are_equal(const firebot__srv__SetPIDParams_Request * lhs, const firebot__srv__SetPIDParams_Request * rhs);

/// Copy a srv/SetPIDParams message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Request__copy(
  const firebot__srv__SetPIDParams_Request * input,
  firebot__srv__SetPIDParams_Request * output);

/// Initialize array of srv/SetPIDParams messages.
/**
 * It allocates the memory for the number of elements and calls
 * firebot__srv__SetPIDParams_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Request__Sequence__init(firebot__srv__SetPIDParams_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetPIDParams messages.
/**
 * It calls
 * firebot__srv__SetPIDParams_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
void
firebot__srv__SetPIDParams_Request__Sequence__fini(firebot__srv__SetPIDParams_Request__Sequence * array);

/// Create array of srv/SetPIDParams messages.
/**
 * It allocates the memory for the array and calls
 * firebot__srv__SetPIDParams_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
firebot__srv__SetPIDParams_Request__Sequence *
firebot__srv__SetPIDParams_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetPIDParams messages.
/**
 * It calls
 * firebot__srv__SetPIDParams_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
void
firebot__srv__SetPIDParams_Request__Sequence__destroy(firebot__srv__SetPIDParams_Request__Sequence * array);

/// Check for srv/SetPIDParams message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Request__Sequence__are_equal(const firebot__srv__SetPIDParams_Request__Sequence * lhs, const firebot__srv__SetPIDParams_Request__Sequence * rhs);

/// Copy an array of srv/SetPIDParams messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Request__Sequence__copy(
  const firebot__srv__SetPIDParams_Request__Sequence * input,
  firebot__srv__SetPIDParams_Request__Sequence * output);

/// Initialize srv/SetPIDParams message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * firebot__srv__SetPIDParams_Response
 * )) before or use
 * firebot__srv__SetPIDParams_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Response__init(firebot__srv__SetPIDParams_Response * msg);

/// Finalize srv/SetPIDParams message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
void
firebot__srv__SetPIDParams_Response__fini(firebot__srv__SetPIDParams_Response * msg);

/// Create srv/SetPIDParams message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * firebot__srv__SetPIDParams_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
firebot__srv__SetPIDParams_Response *
firebot__srv__SetPIDParams_Response__create();

/// Destroy srv/SetPIDParams message.
/**
 * It calls
 * firebot__srv__SetPIDParams_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
void
firebot__srv__SetPIDParams_Response__destroy(firebot__srv__SetPIDParams_Response * msg);

/// Check for srv/SetPIDParams message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Response__are_equal(const firebot__srv__SetPIDParams_Response * lhs, const firebot__srv__SetPIDParams_Response * rhs);

/// Copy a srv/SetPIDParams message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Response__copy(
  const firebot__srv__SetPIDParams_Response * input,
  firebot__srv__SetPIDParams_Response * output);

/// Initialize array of srv/SetPIDParams messages.
/**
 * It allocates the memory for the number of elements and calls
 * firebot__srv__SetPIDParams_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Response__Sequence__init(firebot__srv__SetPIDParams_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetPIDParams messages.
/**
 * It calls
 * firebot__srv__SetPIDParams_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
void
firebot__srv__SetPIDParams_Response__Sequence__fini(firebot__srv__SetPIDParams_Response__Sequence * array);

/// Create array of srv/SetPIDParams messages.
/**
 * It allocates the memory for the array and calls
 * firebot__srv__SetPIDParams_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
firebot__srv__SetPIDParams_Response__Sequence *
firebot__srv__SetPIDParams_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetPIDParams messages.
/**
 * It calls
 * firebot__srv__SetPIDParams_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
void
firebot__srv__SetPIDParams_Response__Sequence__destroy(firebot__srv__SetPIDParams_Response__Sequence * array);

/// Check for srv/SetPIDParams message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Response__Sequence__are_equal(const firebot__srv__SetPIDParams_Response__Sequence * lhs, const firebot__srv__SetPIDParams_Response__Sequence * rhs);

/// Copy an array of srv/SetPIDParams messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_firebot
bool
firebot__srv__SetPIDParams_Response__Sequence__copy(
  const firebot__srv__SetPIDParams_Response__Sequence * input,
  firebot__srv__SetPIDParams_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FIREBOT__SRV__DETAIL__SET_PID_PARAMS__FUNCTIONS_H_
