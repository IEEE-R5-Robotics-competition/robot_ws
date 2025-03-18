cmake_minimum_required(VERSION 3.5)
project(firebot)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

# Include directories
include_directories(
  include
)

# Build C++ nodes
add_executable(motor_controller_node src/motor_controller.cpp)
ament_target_dependencies(motor_controller_node rclcpp std_msgs sensor_msgs geometry_msgs nav_msgs tf2_ros)

add_executable(odometry_publisher_node src/odometry_publisher.cpp)
ament_target_dependencies(odometry_publisher_node rclcpp std_msgs sensor_msgs geometry_msgs nav_msgs tf2_ros)

add_executable(lidar_node src/lidar_node.cpp)
ament_target_dependencies(lidar_node rclcpp std_msgs sensor_msgs geometry_msgs nav_msgs tf2_ros)

add_executable(tf_broadcaster_node src/tf_broadcaster.cpp)
ament_target_dependencies(tf_broadcaster_node rclcpp std_msgs sensor_msgs geometry_msgs nav_msgs tf2_ros)

# Install executables
install(TARGETS
  motor_controller_node
  odometry_publisher_node
  lidar_node
  tf_broadcaster_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

# Install Python nodes (if using scripts for Python nodes)
install(PROGRAMS
  scripts/serial_bridge.py
  scripts/thermal_camera.py
  scripts/lidar_processing.py
  scripts/navigation_control.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
