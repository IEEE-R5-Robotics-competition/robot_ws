// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from firebot:srv/SetPIDParams.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__SRV__DETAIL__SET_PID_PARAMS__STRUCT_H_
#define FIREBOT__SRV__DETAIL__SET_PID_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetPIDParams in the package firebot.
typedef struct firebot__srv__SetPIDParams_Request
{
  double kp;
  double ki;
  double kd;
} firebot__srv__SetPIDParams_Request;

// Struct for a sequence of firebot__srv__SetPIDParams_Request.
typedef struct firebot__srv__SetPIDParams_Request__Sequence
{
  firebot__srv__SetPIDParams_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} firebot__srv__SetPIDParams_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetPIDParams in the package firebot.
typedef struct firebot__srv__SetPIDParams_Response
{
  bool success;
  rosidl_runtime_c__String message;
} firebot__srv__SetPIDParams_Response;

// Struct for a sequence of firebot__srv__SetPIDParams_Response.
typedef struct firebot__srv__SetPIDParams_Response__Sequence
{
  firebot__srv__SetPIDParams_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} firebot__srv__SetPIDParams_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FIREBOT__SRV__DETAIL__SET_PID_PARAMS__STRUCT_H_
