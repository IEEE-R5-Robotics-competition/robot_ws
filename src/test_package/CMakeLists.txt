cmake_minimum_required(VERSION 3.5)
project(test_package)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add the executable
add_executable(my_publisher src/my_ros2_package.cpp)
ament_target_dependencies(my_publisher rclcpp std_msgs)

# Install the executable
install(TARGETS
  my_publisher
DESTINATION lib/${PROJECT_NAME})

ament_package()