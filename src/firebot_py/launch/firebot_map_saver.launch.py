#!/usr/bin/env python3
import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():
    # Get package directories
    package_name = 'firebot_py'
    firebot_py_dir = get_package_share_directory(package_name)

    # Include your original firebot.launch.py (hardware, state publisher, slam, etc.)
    firebot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(firebot_py_dir, 'firebot.launch.py')
        )
    )
    
    # Include the Nav2 bringup launch file we just created
    nav2_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(firebot_py_dir, 'firebot_nav2.launch.py')
        )
    )
    
    # Launch the random navigation node
    random_nav = ExecuteProcess(
        cmd=['ros2', 'run', package_name, 'random_nav_node'],
        output='screen'
    )

    square_nav = Node(
        package= package_name,
        executable='square_nav_node',
        name='square_nav_node',
        output='screen'
    )
    
    # After 5 minutes (300 seconds), automatically save the map.
    # This uses nav2_map_server's map_saver_cli to save the current occupancy grid.
    map_saver = TimerAction(
        period=120.0,
        actions=[
            ExecuteProcess(
                cmd=['ros2', 'run', 'nav2_map_server', 'map_saver_cli', '-f', 'my_map'],
                output='screen'
            )
        ]
    )
    
    return LaunchDescription([
        firebot_launch,
        nav2_launch,
        square_nav,
        #random_nav,
        map_saver
    ])
