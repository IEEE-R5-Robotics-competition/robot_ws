cmake_minimum_required(VERSION 3.8)
project(firebot)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate message interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/EncoderData.msg"
  "msg/MotorCommand.msg"
  "srv/SetPIDParams.srv"
)

# Include directories
include_directories(include)

# C++ nodes
add_executable(lidar_node src/lidar_node.cpp)
ament_target_dependencies(lidar_node rclcpp sensor_msgs)

add_executable(motor_controller src/motor_controller.cpp)
ament_target_dependencies(motor_controller rclcpp std_msgs)

add_executable(odometry_publisher src/odometry_publisher.cpp)
ament_target_dependencies(odometry_publisher rclcpp geometry_msgs)

add_executable(tf_broadcaster src/tf_broadcaster.cpp)
ament_target_dependencies(tf_broadcaster rclcpp geometry_msgs)

# Install C++ executables
install(TARGETS
  lidar_node
  motor_controller
  odometry_publisher
  tf_broadcaster
  DESTINATION lib/${PROJECT_NAME}
)

# Install Python modules
if(NOT TARGET ament_cmake_python_symlink_${PROJECT_NAME})
    ament_python_install_package(firebot_py)

endif()

# Install launch and config files
install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()