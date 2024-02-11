## Data exchange between ROS2 and ESP32

For the Polaris-bot project, we have a need to communicate and exchange data between ROS2 and the ESP32 microcontroller. In our operation, we will utilize micro-ROS as a framework, which enables ROS2 to function with resource-constrained systems such as microcontrollers like ESP32. Additionally, firmware must be employed as middleware to facilitate communication between ROS2 and the microcontroller. The firmware to be used is freeRTOS. The installation of micro-ROS and freeRTOS firmware can be carried out following the instructions provided _here_.

Furthermore, we also aim to send message packages between the microcontroller and ROS2 using custom messages. The creation of custom messages can be done following _these_ instructions.

Table of contents

-   Micro-ROS application on Linux & Firware freeRTOS.
-   Custom message for defind message type.
