#!/usr/bin/env python3

import os 
from ament_index_python.packages import get_package_share_directory 
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, PathJoinSubstitution
from launch.actions import RegisterEventHandler
from launch.event_handlers import OnProcessStart

from launch_ros.actions import Node


def generate_launch_description(): # Get package directories 
    package_name = 'firebot_py'
    firebot_hardware_interface_dir = get_package_share_directory('ros2_control_demo_example_2')
    firebot_py_dir = get_package_share_directory(package_name)
    rplidar_ros_dir = get_package_share_directory('rplidar_ros')
    thermal_camera_dir = get_package_share_directory('thermal_camera')
    
    # Include the robot_state_publisher launch (which processes your URDF including the lidar)
    rsp_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(firebot_hardware_interface_dir, 'launch', 'diffbot.launch.py')
        ),
        launch_arguments={
            'use_mock_hardware': 'false'
        }.items()
    )

    lidar_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(rplidar_ros_dir, 'launch', 'rplidar_a1_launch.py')
        ),
        launch_arguments={
            'channel_type': 'serial',
            'serial_port': '/dev/ttyUSB0',
            'serial_baudrate': '115200',
            'frame_id': 'laser_frame',
            'inverted': 'false',
            'angle_compensate': 'true',
            'scan_mode': 'Sensitivity'
        }.items()
    )
    

    # doesn't work properly
    # twist_stamper = Node(
    #     package=package_name,
    #     executable='twist_stamper',
    #     name='twist_stamper',
    #     output='screen'
    # )

    twist_mux_params = os.path.join(get_package_share_directory(package_name),'config','twist_mux.yaml')
    twist_mux = Node(
            package="twist_mux",
            executable="twist_mux",
            parameters=[twist_mux_params],
            remappings=[('/cmd_vel_out', '/cmd_vel')],
        )

    # Launch the slam_toolbox node using our mapping parameters
    slam_params_file = os.path.join(firebot_py_dir, 'mapper_params_online_async.yaml')
    slam_node = Node(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        output='screen',
        parameters=[slam_params_file, {'use_sim_time': False}]
    )

    stamp_converter = Node(
            package=package_name,
            executable='cmd_vel_stamper',
            name='cmd_vel_stamper',
            parameters=[
                {'input_topic': '/cmd_vel'},
                {'output_topic': '/diffbot_base_controller/cmd_vel_stamped'}
            ]
        )
    
    thermal_node = Node(
        package='thermal_camera',
        executable='thermal_node',
        name='thermal_node',
        output='screen'
    )

    # Optionally launch RViz for visualization
    # rviz_config = os.path.join(firebot_py_dir, 'config', 'display.rviz')
    # rviz_node = Node(
    #     package='rviz2',
    #     executable='rviz2',
    #     name='rviz2',
    #     output='screen',
    #     arguments=['-d', rviz_config]
    # )

    

    return LaunchDescription([
        rsp_launch,
        lidar_launch,
        slam_node,
        stamp_converter,
        thermal_node,
        # twist_stamper,
        # twist_mux
        # rviz_node
    ])

