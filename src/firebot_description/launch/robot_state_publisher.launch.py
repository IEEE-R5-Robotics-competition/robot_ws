#!/usr/bin/env python3
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import Command, LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Declare arguments
    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    use_ros2_control = LaunchConfiguration('use_ros2_control', default='true')
    sim_mode = LaunchConfiguration('sim_mode', default='false')
    
    # Get the urdf file
    pkg_share = get_package_share_directory('firebot_description')
    xacro_file = os.path.join(pkg_share, 'urdf', 'robot.urdf.xacro')
    
    # Process the URDF file
    robot_description_content = Command([
        'xacro ', xacro_file, 
        ' use_ros2_control:=', use_ros2_control,
        ' sim_mode:=', sim_mode
    ])
    
    robot_description = {'robot_description': robot_description_content}
    
    # Create a robot_state_publisher node
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[robot_description, {'use_sim_time': use_sim_time}]
    )
    
    # Joint state publisher for testing
    node_joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        output='screen'
    )
    
    # RViz
    rviz_config_file = os.path.join(pkg_share, 'rviz', 'display.rviz')
    node_rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_file],
        output='screen'
    )
    
    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),
        DeclareLaunchArgument(
            'use_ros2_control',
            default_value='true',
            description='Use ros2_control if true'),
        DeclareLaunchArgument(
            'sim_mode',
            default_value='false',
            description='Use simulation settings if true'),
        
        node_robot_state_publisher,
        node_joint_state_publisher_gui,
        node_rviz
    ])