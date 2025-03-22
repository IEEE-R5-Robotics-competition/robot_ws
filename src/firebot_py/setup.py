from setuptools import find_packages, setup

package_name = 'firebot_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
            'serial_bridge = firebot_py.serial_bridge:main',
            'thermal_camera = firebot_py.thermal_camera:main',
            'lidar_processing = firebot_py.lidar_processing:main',
            'navigation_control = firebot_py.navigation_control:main',
            'lidar_node = firebot_py.lidar_node:main',
        ],
    },
)
