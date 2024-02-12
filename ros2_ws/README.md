## Data exchange between ROS2 and ESP32

For the Polaris-bot project, we have a need to communicate and exchange data between ROS2 and the ESP32 microcontroller. In our operation, we will utilize micro-ROS as a framework, which enables ROS2 to function with resource-constrained systems such as microcontrollers like ESP32. Additionally, firmware must be employed as middleware to facilitate communication between ROS2 and the microcontroller. The firmware to be used is freeRTOS. The installation of micro-ROS and freeRTOS firmware can be carried out following the instructions provided _here_.

Furthermore, we also aim to send message packages between the microcontroller and ROS2 using custom messages. The creation of custom messages can be done following _these_ instructions.

Table of contents

-   Micro-ROS application on Linux & Firware freeRTOS.
-   Custom message for defind message type.

----------


## Micro-ROS application on Linux

Micro-ROS is a framework used to connect large-scale control systems, such as robotic operating systems or ROS, with systems that have limited resources, such as microcontrollers like the ESP32. Micro-ROS is essential for cross-platform operations, with Micro-ROS using ROS as the interface for operations on various microcontrollers, such as the ESP32.

**Table of contents**

[Install micro-ROS](#Install%20micro-ROS )

-   [For create new directory.](#Install%20micro-ROS)
-   [For clone directory from our github.](#Clone%20Polaris-Bot%20Project%20Directory)

[Firmware](#Creating%20a%20new%20firmware%20workspace)

[Update code](#Update%20code)

[Change app](#Change%20app)

## Install micro-ROS

Before we start, you must already install ROS2 Iron/Humble on your Ubuntu computer via Debian packages. If you have't install ROS2 you can install by follow the instruction detailed [here](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html)

After you follow the instruction or already have ROS2 installed on your computer,either Iron or Humble, we will run the command

```plaintext
source /opt/ros/$ROS_DISTRO/setup.bash
```

  
for call optional package application before install micro-ROS.

-create your folder or workspace for micro-ROS

```plaintext
mkdir microros_ws
cd microros_ws
```

Use `git clone ###` command for download the micro-ROS tool from github.

```plaintext
git clone -b $ROS_DISTRO https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup
```

update dependencies by using `rosdep` command.

```plaintext
sudo apt update && rosdep update
rosdep install --from-paths src --ignore-src -y
```

install python3 package.

```plaintext
sudo apt-get install python3-pip
```

Build micro-ROS tools and source them

```plaintext
colcon build
source install/local_setup.bash
```

**Creating the micro-ROS agent**

The micro-ROS app is now ready to be connected to a micro-ROS agent to start talking with the rest of the ROS 2 world. To do that, let’s first of all create a micro-ROS agent:

```plaintext
ros2 run micro_ros_setup create_agent_ws.sh
```

**Building the micro-ROS agent**

Now, let’s build the agent packages and, when this is done, source the installation:

```plaintext
ros2 run micro_ros_setup build_agent.sh
```

```plaintext
source install/local_setup.bash
```

## Clone Polaris-Bot Project Directory

If you don't want to install micro-ROS package by you own , you can use command `git clone` to clone our project from our github and add to your work space.

```plaintext
#if you are still in microros_ws/, you should back to your home directory
cd 

git clone https://github.com/GunZir/polaris-bot.git
```

you must clear cache to set

```plaintext
cd polaris-bot/ros2_ws/
colcon build --cmake-clean-cache
```

## Creating a new firmware workspace

After build system had install, for working on microcontrollers like ESP32, creating middleware for cross-platform operations on our own is challenging. Therefore, we will use firmware specifically developed for operating on ESP32 with ROS, named `freeRTOS`.

create firmware in directory polaris/src

```plaintext
cd polaris_bot/ros2_ws/src
```

Install middleware or firmware, freeRTOS, by running the command below.

```plaintext
ros2 run micro_ros_setup create_firmware_ws.sh freertos esp32
```

Folder named 'firmware' should appear in your directory or workspace after the command has succeeded.

Move app directories into /firmware/freertos_apps/apps

```plaintext
cp -r apps/* firmware/freertos_apps/apps/.
```

  
Configuring the firmware

```plaintext
ros2 run micro_ros_setup configure_firmware.sh [APP] [OPTIONS]
```

-   [APP] is your executable folder in `app` folder from `freesrtos app` folder

For [OPTIONS] you can add an attribute for spacific the method for communication between microcontroller and your OS.

-   `--transport` or `-t` follew by `udp` , `serial` or any hardware-specific transport label
-   `--dev` or `-d`: agent string descriptor in a serial-like transport
-   `--ip` or `-i`: agent IP in a network-like transport
-   `--port` or `-p`: agent port in a network-like transport

example :

```plaintext
ros2 run micro_ros_setup configure_firmware.sh int32_publisher -t serial
```

this command mean that we `configure` the app name `int32_publisher` to communicate with `serial communication` method.

### Building the firmware

When the configuring step ends, we will build the firmware by using command:

```plaintext
ros2 run micro_ros_setup build_firmware.sh
```

### Flashing the firmware

Flashing the firmware into the platform varies across hardware platforms.

```plaintext
ros2 run micro_ros_setup flash_firmware.sh
```

### Running the micro-ROS app

At this point, you have both the client and the agent correctly installed in your host machine.

To give micro-ROS access to the ROS 2 dataspace, run the agent:

```plaintext
ros2 run micro_ros_agent micro_ros_agent serial --dev [device]
```

example :

```plaintext
ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyUSB0
```

`--dev /dev/ttyUSB0` specifies the device to be used for communication, in this case, a device connected via serial and named /dev/ttyUSB0.

***If the run is successful, unplug and plug in again.**

----------

### Update code

-   Building the firmware

```plaintext
ros2 run micro_ros_setup build_firmware.sh
```

-   Flashing the firmware

```plaintext
ros2 run micro_ros_setup flash_firmware.sh
```

-   Running the micro-ROS app

```plaintext
ros2 run micro_ros_agent micro_ros_agent serial --dev [device]
```

### Change app

-   Configuring the firmware

```plaintext
ros2 run micro_ros_setup configure_firmware.sh [APP] [OPTIONS]
```

-   Building the firmware

```plaintext
ros2 run micro_ros_setup build_firmware.sh
```

-   Flashing the firmware

```plaintext
ros2 run micro_ros_setup flash_firmware.sh
```

-   Running the micro-ROS app

```plaintext
ros2 run micro_ros_agent micro_ros_agent serial --dev [device]
```
