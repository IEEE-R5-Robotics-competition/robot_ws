# Use the official ROS 2 Humble image as the base image
FROM ros:humble

# Set up the environment
ENV ROS_DISTRO=humble

# Update package lists and install ROS 2 packages
RUN apt-get update && apt-get install -y \
    ros-$ROS_DISTRO-ros-base \
    ros-$ROS_DISTRO-rmw-fastrtps-cpp \
    ros-$ROS_DISTRO-rclcpp \
    ros-$ROS_DISTRO-rclpy \
    ros-$ROS_DISTRO-std-msgs \
    ros-$ROS_DISTRO-sensor-msgs \
    ros-$ROS_DISTRO-geometry-msgs \
    ros-$ROS_DISTRO-nav-msgs \
    ros-$ROS_DISTRO-tf2-ros \
    ros-$ROS_DISTRO-robot-state-publisher \
    ros-$ROS_DISTRO-slam-toolbox \
    ros-$ROS_DISTRO-nav2-bringup \
    # The following packages have been problematic and are commented out:
    # ros-$ROS_DISTRO-map-server \
    # ros-$ROS_DISTRO-amcl \
    # ros-$ROS_DISTRO-dwa-local-planner \
    # ros-$ROS_DISTRO-serial \
    # ros-$ROS_DISTRO-i2c-tools \
    # python3-serial \
    ros-$ROS_DISTRO-rosbridge-server \
    ros-$ROS_DISTRO-rplidar-ros \
    ros-$ROS_DISTRO-robot-localization \
    ros-$ROS_DISTRO-ackermann-msgs \
    ros-$ROS_DISTRO-diff-drive-controller \
    ros-$ROS_DISTRO-desktop \
    ros-$ROS_DISTRO-demo-nodes-cpp \
    ros-$ROS_DISTRO-demo-nodes-py \
    ros-$ROS_DISTRO-xacro \
    ros-$ROS_DISTRO-joint-state-publisher-gui \
    ros-$ROS_DISTRO-slam-toolbox \
    ros-$ROS_DISTRO-nav2-bringup \
    ros-$ROS_DISTRO-navigation2 \
    ros-$ROS_DISTRO-serial-driver \
    ros-$ROS_DISTRO-ros2-control \
    ros-$ROS_DISTRO-ros2-controllers \
    ros-$ROS_DISTRO-rviz2 \
    ros-$ROS_DISTRO-rplidar-ros \
    libserial-dev \
    python3-pip \
    python3-rosdep \
    python3-colcon-common-extensions \
    i2c-tools \
    udev \
    git \
    build-essential && \
    rm -rf /var/lib/apt/lists/*

# Resolve any missing dependencies.
RUN rosdep update && rosdep install --from-paths /opt/ros/$ROS_DISTRO/share --ignore-src -r -y || true

# Install python3-serial separately (this is the correct package name)
RUN apt-get update && apt-get install -y python3-serial && rm -rf /var/lib/apt/lists/*

# Set the working directory to your ROS workspace
WORKDIR /robot_ws

# Copy only the source code, not the build files
COPY ./src /robot_ws/src

# Build the workspace using colcon
RUN . /opt/ros/$ROS_DISTRO/setup.sh && colcon build --symlink-install

# Set the default command
CMD ["bash", "-c", "source /opt/ros/$ROS_DISTRO/setup.bash && source /robot_ws/install/setup.bash && exec bash"]