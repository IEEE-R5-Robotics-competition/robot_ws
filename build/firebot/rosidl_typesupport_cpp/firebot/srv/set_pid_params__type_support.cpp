// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from firebot:srv/SetPIDParams.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "firebot/srv/detail/set_pid_params__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace firebot
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetPIDParams_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetPIDParams_Request_type_support_ids_t;

static const _SetPIDParams_Request_type_support_ids_t _SetPIDParams_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetPIDParams_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetPIDParams_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetPIDParams_Request_type_support_symbol_names_t _SetPIDParams_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, firebot, srv, SetPIDParams_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, firebot, srv, SetPIDParams_Request)),
  }
};

typedef struct _SetPIDParams_Request_type_support_data_t
{
  void * data[2];
} _SetPIDParams_Request_type_support_data_t;

static _SetPIDParams_Request_type_support_data_t _SetPIDParams_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetPIDParams_Request_message_typesupport_map = {
  2,
  "firebot",
  &_SetPIDParams_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetPIDParams_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetPIDParams_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetPIDParams_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetPIDParams_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace firebot

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<firebot::srv::SetPIDParams_Request>()
{
  return &::firebot::srv::rosidl_typesupport_cpp::SetPIDParams_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, firebot, srv, SetPIDParams_Request)() {
  return get_message_type_support_handle<firebot::srv::SetPIDParams_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "firebot/srv/detail/set_pid_params__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace firebot
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetPIDParams_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetPIDParams_Response_type_support_ids_t;

static const _SetPIDParams_Response_type_support_ids_t _SetPIDParams_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetPIDParams_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetPIDParams_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetPIDParams_Response_type_support_symbol_names_t _SetPIDParams_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, firebot, srv, SetPIDParams_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, firebot, srv, SetPIDParams_Response)),
  }
};

typedef struct _SetPIDParams_Response_type_support_data_t
{
  void * data[2];
} _SetPIDParams_Response_type_support_data_t;

static _SetPIDParams_Response_type_support_data_t _SetPIDParams_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetPIDParams_Response_message_typesupport_map = {
  2,
  "firebot",
  &_SetPIDParams_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetPIDParams_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetPIDParams_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetPIDParams_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetPIDParams_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace firebot

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<firebot::srv::SetPIDParams_Response>()
{
  return &::firebot::srv::rosidl_typesupport_cpp::SetPIDParams_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, firebot, srv, SetPIDParams_Response)() {
  return get_message_type_support_handle<firebot::srv::SetPIDParams_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "firebot/srv/detail/set_pid_params__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace firebot
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SetPIDParams_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetPIDParams_type_support_ids_t;

static const _SetPIDParams_type_support_ids_t _SetPIDParams_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SetPIDParams_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetPIDParams_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetPIDParams_type_support_symbol_names_t _SetPIDParams_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, firebot, srv, SetPIDParams)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, firebot, srv, SetPIDParams)),
  }
};

typedef struct _SetPIDParams_type_support_data_t
{
  void * data[2];
} _SetPIDParams_type_support_data_t;

static _SetPIDParams_type_support_data_t _SetPIDParams_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetPIDParams_service_typesupport_map = {
  2,
  "firebot",
  &_SetPIDParams_service_typesupport_ids.typesupport_identifier[0],
  &_SetPIDParams_service_typesupport_symbol_names.symbol_name[0],
  &_SetPIDParams_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetPIDParams_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetPIDParams_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace firebot

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<firebot::srv::SetPIDParams>()
{
  return &::firebot::srv::rosidl_typesupport_cpp::SetPIDParams_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, firebot, srv, SetPIDParams)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<firebot::srv::SetPIDParams>();
}

#ifdef __cplusplus
}
#endif
