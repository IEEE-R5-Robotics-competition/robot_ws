# Use the official ROS 2 Humble image as the base image
FROM ros:humble

# Set up the environment
ENV ROS_DISTRO=humble

# Install necessary ROS 2 packages
RUN apt-get update && apt-get install -y \
    ros-$ROS_DISTRO-desktop \
    ros-$ROS_DISTRO-demo-nodes-cpp \
    ros-$ROS_DISTRO-demo-nodes-py \
    #xacro
    ros-$ROS_DISTRO-xacro \
    ros-$ROS_DISTRO-joint-state-publisher-gui \
    # SLAM packages
    ros-$ROS_DISTRO-slam-toolbox \
    ros-$ROS_DISTRO-nav2-bringup \
    ros-$ROS_DISTRO-navigation2 \
    # Serial communication
    ros-$ROS_DISTRO-serial-driver \
    # Visualization tools
    ros-$ROS_DISTRO-rviz2 \
    # For LiDAR support
    ros-$ROS_DISTRO-rplidar-ros \
    # Utils
    python3-pip \
    python3-rosdep \
    python3-colcon-common-extensions \
    # For serial port access
    udev \
    # Development tools
    git \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Create a workspace directory
RUN mkdir -p /ros2_ws/src

# Set the working directory
WORKDIR /ros2_ws

ARG CACHEBUST=1
# Copy your ROS 2 package into the workspace
COPY ./src /ros2_ws/src

# Set up serial permissions (optional - you might need to set up udev rules on the host)
RUN echo 'KERNEL=="ttyUSB*", MODE="0666"' > /etc/udev/rules.d/99-serial.rules
RUN echo 'KERNEL=="ttyACM*", MODE="0666"' >> /etc/udev/rules.d/99-serial.rules

# Source ROS 2 first - this is the critical fix
RUN . /opt/ros/$ROS_DISTRO/setup.sh && \
    apt-get update && \
    rosdep init || echo "rosdep already initialized" && \
    rosdep update && \
    rosdep install --from-paths src --ignore-src -y && \
    colcon build

# Build the workspace
# Add this line before the colcon build step

RUN colcon build --symlink-install

# Source the setup file
RUN echo "source /ros2_ws/install/setup.bash" >> ~/.bashrc

# Set the default command to run when the container starts
CMD ["bash"]