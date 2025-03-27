from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'firebot_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*.py')),
        (os.path.join('share', package_name), glob('config/*.yaml')),
        (os.path.join('share', package_name), glob('config/*.rviz')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ana',
    maintainer_email='ana.wise06@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'lidar_node = firebot_py.lidar_node:main',
            'slam_mapping = firebot_py.slam_mapping:main',
            'navigation_control = firebot_py.navigation_control:main',
            'thermal_camera = firebot_py.thermal_camera:main',
            'twist_stamper = firebot_py.twist_stamper:main',
            'random_nav_node = firebot_py.random_nav_node:main',
            'cmd_vel_stamper = firebot_py.cmd_vel_stamper:main',
            'square_nav_node = firebot_py.square_nav_node:main',
        ],
    },
)
