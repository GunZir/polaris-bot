# ROS2 humble installation 

This is installation based on this [ref.](https://docs.ros.org/en/humble/Installation/Alternatives/Ubuntu-Development-Setup.html) I'm not sure why but, when i started follow this instruction i got some output different so this is a summary of **our experience** about install ros2 humble **to remind us** if you found this repo and have some suggestion that would be great. In this instruction we use 

# System requirements

**Ubuntu Linux - Jammy (22.04) 64-bit.**

# System setup

## Set locale
Make sure you have a locale which supports `UTF-8` by this command on your CLI.

    locale
That should be shown like this, but if not it okay.

```
LANG=en_US.UTF-8
LANGUAGE=
LC_CTYPE="en_US.UTF-8"
LC_NUMERIC=en_US.UTF-8
LC_TIME=en_US.UTF-8
LC_COLLATE="en_US.UTF-8"
LC_MONETARY=en_US.UTF-8
LC_MESSAGES="en_US.UTF-8"
LC_PAPER=en_US.UTF-8
LC_NAME=en_US.UTF-8
LC_ADDRESS=en_US.UTF-8
LC_TELEPHONE=en_US.UTF-8
LC_MEASUREMENT=en_US.UTF-8
LC_IDENTIFICATION=en_US.UTF-8
LC_ALL=
```
now let setting it by this command
```
sudo  apt  update  &&  sudo  apt  install  locales
sudo  locale-gen  en_US  en_US.UTF-8
sudo  update-locale  LC_ALL=en_US.UTF-8  LANG=en_US.UTF-8
export LANG=en_US.UTF-8
export LC_ALL=en_US.UTF-8
locale
```
That should be like this.
```
LANG=en_US.UTF-8
LANGUAGE=
LC_CTYPE="en_US.UTF-8"
LC_NUMERIC="en_US.UTF-8"
LC_TIME="en_US.UTF-8"
LC_COLLATE="en_US.UTF-8"
LC_MONETARY="en_US.UTF-8"
LC_MESSAGES="en_US.UTF-8"
LC_PAPER="en_US.UTF-8"
LC_NAME="en_US.UTF-8"
LC_ADDRESS="en_US.UTF-8"
LC_TELEPHONE="en_US.UTF-8"
LC_MEASUREMENT="en_US.UTF-8"
LC_IDENTIFICATION="en_US.UTF-8"
LC_ALL=en_US.UTF-8
```
 
## Setup Sources

You will need to add the ROS 2 apt repository to your system.

First ensure that the  [Ubuntu Universe repository](https://help.ubuntu.com/community/Repositories/Ubuntu)  is enabled.
```
sudo apt install software-properties-common
sudo add-apt-repository universe
```
Now add the ROS 2 GPG key with apt.

```
sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```
Then add the repository to your sources list.
```
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```
## Install development tools and ROS tools

Install common packages.
```
sudo apt update && sudo apt install -y \
  python3-flake8-docstrings \
  python3-pip \
  python3-pytest-cov \
  ros-dev-tools
```
For  **Ubuntu Linux - Jammy (22.04) 64-bit.**
```
sudo apt install -y \
   python3-flake8-blind-except \
   python3-flake8-builtins \
   python3-flake8-class-newline \
   python3-flake8-comprehensions \
   python3-flake8-deprecated \
   python3-flake8-import-order \
   python3-flake8-quotes \
   python3-pytest-repeat \
   python3-pytest-rerunfailures
```
Now you have all common packages that needed

## Install ROS2 packages
Update and upgrade your systems and packages first by this command.
```
sudo  apt  update
sudo apt upgrade
```
and then install ros2 humble by
```
sudo apt install ros-humble-desktop
```

## Install dependencies using rosdep
ROS 2 packages are built on frequently updated Ubuntu systems. It is always recommended that you ensure your system is up to date before installing new packages.
```
sudo apt upgrade
```
now Install dependencies rosdep
```
sudo rosdep init
rosdep update
rosdep install --from-paths src --ignore-src -y --skip-keys "fastcdr rti-connext-dds-6.0.1 urdfdom_headers"
```
## Environment setup
use your editor to edit `~/.bashrc`. In This case we use nano
```
nano ~/.bashrc
```
Then scroll down to the bottom and paste this line.
```
source  /opt/ros/humble/setup.bash
```
Save and close it.


## Build and create
Create a workspace. you can name your workspace whatever you want in this case we name it `workspace` 
```
mkdir  -p  ~/workspace/src
cd workspace/
```
then build your workspace by
```
colcon  build
```
now everything goal.

## Try some example
If you installed  `ros-humble-desktop`  above you can try some examples.

In one terminal, source the setup file and then run a C++  `talker`:

```
source /opt/ros/humble/setup.bash
ros2 run demo_nodes_cpp talker
```
In another terminal source the setup file and then run a Python `listener`:
```
source  /opt/ros/humble/setup.bash
ros2  run  demo_nodes_py  listener
```
You should see the `talker` saying that it’s `Publishing` messages and the `listener` saying `I  heard` those messages. This verifies both the C++ and Python APIs are working properly. Hooray!

