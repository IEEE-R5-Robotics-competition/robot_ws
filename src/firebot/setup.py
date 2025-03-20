#!/usr/bin/env python3
import os
from glob import glob
from setuptools import setup

package_name = 'firebot_py'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        # Install package.xml and launch files
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        #(os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Ana Wise',
    maintainer_email='ana.wise06@gmail.com',
    description='Firebot package for the IEEE R5 robotics competition',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'serial_bridge = firebot_py.serial_bridge:main',
            'thermal_camera = firebot_py.thermal_camera:main',
            'lidar_processing = firebot_py.lidar_processing:main',
            'navigation_control = firebot_py.navigation_control:main'
        ],
    },
)
