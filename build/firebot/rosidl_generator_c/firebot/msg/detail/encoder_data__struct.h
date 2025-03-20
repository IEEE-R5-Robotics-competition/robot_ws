// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from firebot:msg/EncoderData.idl
// generated code does not contain a copyright notice

#ifndef FIREBOT__MSG__DETAIL__ENCODER_DATA__STRUCT_H_
#define FIREBOT__MSG__DETAIL__ENCODER_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EncoderData in the package firebot.
typedef struct firebot__msg__EncoderData
{
  uint8_t structure_needs_at_least_one_member;
} firebot__msg__EncoderData;

// Struct for a sequence of firebot__msg__EncoderData.
typedef struct firebot__msg__EncoderData__Sequence
{
  firebot__msg__EncoderData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} firebot__msg__EncoderData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FIREBOT__MSG__DETAIL__ENCODER_DATA__STRUCT_H_
