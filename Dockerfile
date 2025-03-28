FROM ros:humble

ENV ROS_DISTRO=humble

# --- Base system + ROS base ---
RUN apt-get update && apt-get install -y \
	ros-$ROS_DISTRO-ros-base \
	ros-$ROS_DISTRO-rclcpp \
	ros-$ROS_DISTRO-rclpy \
	&& rm -rf /var/lib/apt/lists/*

# --- Core ROS tools and messages ---
RUN apt-get update && apt-get install -y \
	ros-$ROS_DISTRO-std-msgs \
	ros-$ROS_DISTRO-sensor-msgs \
	ros-$ROS_DISTRO-geometry-msgs \
	ros-$ROS_DISTRO-nav-msgs \
	ros-$ROS_DISTRO-xacro \
	ros-$ROS_DISTRO-tf2-ros \
	&& rm -rf /var/lib/apt/lists/*

# --- Navigation, SLAM, Localization ---
RUN apt-get update && apt-get install -y \
	ros-$ROS_DISTRO-slam-toolbox \
	ros-$ROS_DISTRO-nav2-bringup \
	ros-$ROS_DISTRO-navigation2 \
	ros-$ROS_DISTRO-robot-localization \
	&& rm -rf /var/lib/apt/lists/*

# --- Robot drivers, control, UI ---
RUN apt-get update && apt-get install -y \
	ros-$ROS_DISTRO-rplidar-ros \
	ros-$ROS_DISTRO-ackermann-msgs \
	ros-$ROS_DISTRO-diff-drive-controller \
	ros-$ROS_DISTRO-joint-state-publisher-gui \
	ros-$ROS_DISTRO-serial-driver \
	ros-$ROS_DISTRO-ros2-control \
	ros-$ROS_DISTRO-ros2-controllers \
	&& rm -rf /var/lib/apt/lists/*

# --- GUI + dev tools ---
RUN apt-get update && apt-get install -y \
	ros-$ROS_DISTRO-desktop \
	ros-$ROS_DISTRO-rviz2 \
	ros-$ROS_DISTRO-rosbridge-server \
	&& rm -rf /var/lib/apt/lists/*

# --- Python + system build dependencies ---
RUN apt-get update && apt-get install -y \
	python3-pip \
	python3-dev \
	python3-rosdep \
	python3-colcon-common-extensions \
	python3-serial \
	python3-smbus \
	libffi-dev \
	libsystemd-dev \
	build-essential \
	i2c-tools \
	libserial-dev \
	udev \
	git \
	&& rm -rf /var/lib/apt/lists/*
    
# --- Install lgpio for Blinka on Raspberry Pi 5 (BCM2712) ---
RUN apt-get update && apt-get install -y \
	liblgpio1 \
	liblgpio-dev \
	&& rm -rf /var/lib/apt/lists/*

# --- Python package installs (with sysv_ipc fix) ---
RUN pip3 install --upgrade pip
RUN pip3 install "setuptools<69" wheel
RUN pip3 install sysv_ipc
RUN pip3 install adafruit-blinka adafruit-circuitpython-mlx90640
RUN pip3 install --no-cache-dir lgpio

# --- Resolve ROS dependencies safely ---
RUN rosdep update && rosdep install --from-paths /opt/ros/$ROS_DISTRO/share --ignore-src -r -y || true

# --- Set up workspace ---
WORKDIR /robot_ws
COPY ./src /robot_ws/src

# --- Build ROS workspace ---
RUN . /opt/ros/$ROS_DISTRO/setup.sh && colcon build --symlink-install

# --- Default entrypoint ---
CMD ["bash", "-c", "source /opt/ros/$ROS_DISTRO/setup.bash && source /robot_ws/install/setup.bash && exec bash"]



