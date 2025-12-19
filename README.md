This Package is for the IEEE R5 Robotics Competition for the 2024-2025

This package runs on ROS2 humble and can be ran by building and running the Dockerfile on a rasberri pi.

3 main packages to this program:
1. Firebot Packages
- Handle Navigation and main logic
- Description package publishes transforms and odometry data for internal visualization
2. RosArduinoBridge & "Example 2"
- RosArduinoBridge is a set of ino and header files to run on any arduino that controls the motors. It allows the arduino to be controlled through serial commands
- Example 2 is an adapted hardware interface to work with this specific system. Atetempting to change the package name resulted in errors
3. Thermal Camera & RP-Lidar
  - Thermal camera uses an i2c interface with the MLX90640 IR sensor and publishes a boolean value if the average temps are above a threshold (currently 35 degrees C)
  - RP-Lidar is the standard ros package for the RP_lidar and publishes to laserscan
