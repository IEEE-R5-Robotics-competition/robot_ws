from setuptools import find_packages
from setuptools import setup

setup(
    name='firebot_py',
    version='0.0.1',
    packages=find_packages(
        include=('firebot_py', 'firebot_py.*')),
)
