from setuptools import find_packages
from setuptools import setup

setup(
    name='firebot',
    version='0.0.1',
    packages=find_packages(
        include=('firebot', 'firebot.*')),
)
