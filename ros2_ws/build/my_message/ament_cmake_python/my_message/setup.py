from setuptools import find_packages
from setuptools import setup

setup(
    name='my_message',
    version='0.0.0',
    packages=find_packages(
        include=('my_message', 'my_message.*')),
)
