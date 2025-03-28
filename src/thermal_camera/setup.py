from setuptools import setup

package_name = 'thermal_camera'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'adafruit-circuitpython-mlx90640', 'adafruit-blinka'],
    zip_safe=True,
    maintainer='utdr5',
    maintainer_email='utdr5@todo.todo',
    description='Thermal camera detection package',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'thermal_node = thermal_camera.thermal_node:main',
        ],
    },
)
