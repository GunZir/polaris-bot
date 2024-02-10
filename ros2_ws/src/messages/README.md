## Custom message

In this case, we want to define the message type to exchange specific data between ROS2 node and microcontroller. So, the custom message should be the way that we will implement into our project to exchange data with ESP32.

cd into directory firmware/mcu_ws

```plaintext
cd firmware/mcu_ws
```

then create the package for contain `custom message file`.

```plaintext
ros2 pkg create --build-type ament_cmake [pkg_name]
```

example:

```plaintext
ros2 pkg create --build-type ament_cmake my_custom_message
```

cd into [pkg_name] for create directory msg.

```plaintext
cd [pkg_name]
```

example:

```plaintext
cd my_custom_message
```

create `msg` directory.

```plaintext
mkdir msg
```

create file .msg file in directory msg.

```plaintext
nano msg/[msg_name].msg
```

> The msg file name must be `PascalCase`.

example:

```plaintext
nano msg/MyCustomMessage.msg
```

After run command, text editor shold appear.

In our project, the content in file .msg we will create int32 and string message type so we will add the following line to text editor.

```plaintext
uint32 right_motor_speed
uint32 left_motor_speed
```

Then save and exit.

### Edit CMakeLists.txt file

We have to edit `CmakeLists.txt` file, by add IDLs file in the package, because adding IDLs files to ROS2 package is essential for defining the message type witch these message definitions allow for seamless communication between nodes that written in different programming languages by standardized structure that can be translated into code in the desired language.

So, you can follew all step to add IDLs file (.idl), start with :

```plaintext
nano msg/CMakeList.txt
```

add this command below dependencies file

```plaintext
...
find_package(rosidl_default_generators REQUIRED) rosidl_generate_interfaces(${PROJECT_NAME} "msg/[msg name].msg" )
....
```

example:

```plaintext
# find dependenciese
find_package(rosidl_default_generators REQUIRED) rosidl_generate_interfaces(${PROJECT_NAME} "msg/MyCustomMessage.msg" )
```

Edit file `package.xml` with your prefer text editor but in this case we are using nano to edit package file.

```plaintext
nano msg/package.xml
```

Add all following line In `package.xml` file.

```plaintext
<build_depend>rosidl_default_generators</build_depend>
<exec_depend>rosidl_default_runtime</exec_depend>
<member_of_group>rosidl_interface_packages</member_of_group>
```

save and exit.

### Build firmware

change directory to your ROS2 worlspace.

```plaintext
cd ../ros2_ws/src
```

run command to build firmware in workspace

```plaintext
ros2 run micro_ros_setup build_firmware.sh
```

Copy the package to ros2_ws

```plaintext
cp -r firmware/mcu_ws/[pkg_name] .
```

example:

```plaintext
cp -r firmware/mcu_ws/my_custom_massage .
```

Change directory to ros2_ws and build the enviroment.

```plaintext
colcon build
```


//include msg ไปยังไฟล์ที่ต้องการใช้(app.c) ไม่เข้าใจนิดหน่อย แต่งงมากๆ

Include message package in file `app.c`.

```plaintext
#include <[pkg name]/msg/[msg_name].h>
```

  

Header files (.h) that include other files must use snake_case for naming. One reason we use snake_case is because the C and C++ standard libraries often use snake_case for naming header files, and we want to avoid collisions of file names too.

So, to name a message file from `MyCustomMessage`, it should be turned into `my_custom_message` following the snake_case convention.

example:

```plaintext
#include <my_custom_message/msg/my_custom_message.h>
```

Configure the msg type by using  
pkg_name__msg__MsgName msg;  

```plaintext
[pkg_name: snake_case]__msg__[MsgName:PascalCase] [varient]
```

----------

If you **make changes to the .msg file**, adjustments **must be made on both ends** as the data type being transmitted and received must match.

Copy package to `ros2_ws`

```plaintext
cp -r firmware/mcu_ws/[pkg_name] .
```

example:

```plaintext
cp -r firmware/mcu_ws/my_custom_massage .
```

Change directory to `ros2_ws` and build the enviroment by :

```plaintext
colcon build
```
