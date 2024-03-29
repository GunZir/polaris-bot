

# ROS 2 : Cheat Sheets

for ros2 (Robot Operation System 2) .

```
ros2 (command)
```

for more detail in `ros2` by using

```
ros2 -h
```

>*in this **cheat sheets** of ROS2 command, will use `turtlesim` as an example.
so, for the same result you must run command **`ros2 run turtlesim turtlesim_node`** before.*

ROS2:
- action
- interface
- multicast
- node
- param
- pkg
- run
- service
- topic
- colcon

Commnly used Linux command:

## action

|sub-command  |Description                        
|--           |--                                  
|info         |Print information about an action. 
|list         |Output a list of action names.
|send_goal    |Send an action goal.

### // action list

>**action list** command will show all name of actionavailable action. 

**example:**

```
ros2 action list
```

**output:**

```
/turtle1/rotate_absolute
```

### // action info

```
ros2 action info (action_name)
```

>**action info** command will output and information of action.

**example:**

```
ros2 action info /turtle1/rotate_absolute
```

**output:**

```
Action: /turtle1/rotate_absolute
Action clients: 0
Action servers: 1
```

### // action send_goal

>**send_goal** *not in used*

## interface

|sub-command  |Description                                                  
|--           |--                                                            
|list         |List all interface types available.
|package      |Output a list of available interface types within one package.
|packages     |Output a list of packages that provide interface.
|proto        |Output and interface prototype.
|show         |Output the interface definition.

### // interface list

>**interface list** command will show all available interface in every type of them.

**example:**

```
ros2 interface list
```

**output:**

```
Messages:
	action_msgs/msg/GoalInfo
	action_msgs/msg/GoalStatus
	.
	.
	visualization_msgs/msg/UCVoordinate
Service:
	action_msgs/srv/CancelGoal
	composition_interfaces/srv/ListNodes
	.
	.
	visualization_msgs/srv/GetInteractiveMarkers
Actions:
	action_tutorials_interfaces/action/Fibonacci
	.
	.
	turtlesim/action/RotateAbsolute
```

### //  interface package

```
ros2 interface package (package_name)
```

>**interface package** command is use for show all available interface type in  ***one package***.

**example:**

```
ros2 interface package turtlesim
```

**output:**

>after complie **`ros2 interface package turtlesim`** the output will show every interface that available in **`turtlesim`** package.

```
turtlesim/action/RotateAbsolute
turtlesim/srv/TeleportRelative
.
.
turtlesim/msg/Color
```

### // interface packages

```
ros2 interface packages (attribute)
```

> The **interface packages** command is semilar with **interface package**, but the diffrent of **packages** is will show only one type.


### ///// attribute

|attribute                         |Description  
|--                                |--
|**-m** *or* **--only-msgs**       |Only list packages that generate messages.
|**-s** *or* **--only-srvs**       |Only list packages that generate services.
|**-a** *or* **--only-actions**    |Only list packages that generate action.

**example:**

```
ros2 interface packages --only-action
```

>*attribute **--only-action** can replace with **-a** and still have the same result.*

**output:**
```
action_tutorials_interfaces
example_interfaces
tf2_msgs
turtlesim
```
	
## multicast
> command for check UDP packets if passed between two endpoints.

|sub-command  |Description 
|--           |--
|receive	  |Recive a single UDP multicast packet.
|send		  |Send a single UDP multicast packet.


## node

|sub-command  |Description 
|--           |--
|info		  |Output information about a node.
|list		  |Output a list of available nodes.

### // node info

```
ros2 node info (node_name)
```

> **node info** command will show information of

**example:**

```
ros2 run node info /turtlesim
```

> for ***node_name***, the node needs to be initialized before running.

**output:**

```
/turtlesim
	Subscribers:
		/parameter_events: rcl_interfaces/msg/ParameteEvnet
		/turtle1/cmd_vel: geometry_msgs/msg/Twist
	Publishers:
		/parameter_events: rcl_interfaces/msg/ParameteEvnet
		/rosout: rcl_interfaces/msg/log
		.
		.
		/turtle1/pose: turtlesim/msg/Pose
Service Servers:
		/clear: std_srvs/srv/Empty
		/kill: turtlesim/srv/Kill
		.
		.
		/turtlesim/set_parameters_atomically: rcl_interfaces/src/SetParametersAtomically
	Service Clients:
	
	Action Severs:
		/turtle1/rotate_absolute: turtlesim/action/RotateAbsolute
	Action Clients:
	
```

### // node list

```
ros2 node list
```

>**node list** command will show all available node.

**example:**

```
ros2 node list
```

**output:**

```
/turtlesim
```

## param

|sub-command  |Description 
|--           |--
|delete    	  |Delete parameter.
|describe     |Show descriptive information about declared parameters.
|dump         |Show all of the parameters of a node in a YAML file format.
|get          |Get parameter.
|list         |Output a list of available parameters.
|load         |Load parameter file for a node.
|set          |Set parameter.

### // param delete

> **param delete** command use for delete parameter from selected node.

```
ros2 param delete (/node_name) (parameter_name)
```

### // param describe

> **param describe** command will show information of parameter in selected node.

```
ros2 param describe (/node_name) (parameter_name)
```

**example:**

```
ros2 param describe /turtlesim background_r
```

**output:**

```
Parameter name: background_r
	Type: integer
	Description: Red channel of the background color
	Constraunts: 
		Min value: 0
		Max value: 255
		Step: 1
```

### // param dump

>**param dump** command will show all parameter of selected node in YAML file format.

```
ros2 param dump (/node_name)
```

**example:**

```
ros2 param dump /turtlesim
```

**output:**

```
/turtlesim:
	ros__parameters:
		background_b: 255
		background_g: 86
		background_r: 69
		qos_overrides:
			/parameter_events:
				publisher:
					depth: 1000
					durability: volatile
					history: keep_last
					reliability: reliable
			use_sim_time: false
```

### // param get

>**param get** command will get type and value in spacific parameter from selected node.

```
ros2 param get (/node_name) (parameter_name)
```

**example:**

```
ros2 param get /turtlesim background_g
```

**output:**

```
Interger values: 86
```

### // param list

> **param list** command will show all current available parameter from every active node.

```
ros2 param list
```

**output:**

```
/turtlesim:
	background_b
	background_g
	background_r
	qos_overrides.parameter_event.publisher.depth
	qos_overrides.parameter_event.publisher.durability
	qos_overrides.parameter_event.publisher.history
	qos_overrides.parameter_event.publisher.reliability
	use_sim_time
```

### // param load

> **param load** command will load parameter from spacific file in selected node.

```
ros2 param load (/noad_name) (parameter_file)
```

### // param set

> **param set** command will set an parameter in spacific node.

```
ros2 param set (/node_name) (parameter_name) (value)
```

**example:**

```
ros2 param set /turtlesim background_r 244
```

**output:**

```
Set parameter successful
```

## pkg

|sub-command  |Description                                            
|--           |--                                                       
|create       |Create a new ROS2 package.
|executables  |Output a list of an executable packages.
|list         |Output a list of available package.
|prefix       |Output the prefix path of a package.
|xml          |Output the XML of the package manifest or a specific tag.

### // pkg create

> **pkg create** command will create a new package for ROS2

```
ros2 pkg create (package_name)
```

**example:**

```
ros2 pkg create my_robot_controller
```

> in **pkg create** can add an attribute for more spacific type of package to process the package with	

```
ros2 pkg create my_python_bot --build-type ament_python
```

### // pkg executables

> **pkg executable** command will show all available **executable_name**.

```
ros2 pkg executable
```

**example:**

```
ros2 pkg executable
```

**output:**

```
action_tutorials_cpp fibonacci_action_client
action_tutorials_cpp fibonacci_action_server
.
.
turtlesim turtlesim_node
```

or

```
ros2 pkg executable (/node_name)
```

for show only executable_ name in **spacific node**

**example:**

```
ros2 pkg executable turtlesim
```

**output:**

```
turtlesim draw_square
turtlesim mimic
turtlesim turtle_teleop_key
turtlesim turtlesim_node
```
### // pkg list

> **pkg list** command will show all available package.

```
ros2 pkg list
```

### // pkg prefix

> **pkg prefix** command will show address of package.

```
ros2 pkg prefix (package_name)
```

**example:**

```
ros2 pkg prefix turtlesim
```
**output:**

```
/opt/ros/humble
```

### // pkg xml

> **pkg xml** command will show a **seleted package** in XML format.

```
ros2 pkg xml (package_name)
```

**example:**

```
ros2 pkg xml turtlesim
```
**output:**

```
<package format="3">
	<name>turtlesim</name>
	<version>1.4.2</version>
	<description>
	turtlesim is a tool made for teaching ROS and ROS packages.
	</description>

	<maintainer email="audrow@openrobotics.org">Audrow Nash</maintainer>
	<maintainer email="michael.jeronimo@openrobotics.org">Michael Jeronimo</maintainer>

	<license>BSD</license>

	<url type="website">http://www.ros.org/wiki/turtlesim</url>
	<url type="bugtracker">https://github.com/ros/ros_tutorials/issues</url>
	<url type="repository">https://github.com/ros/ros_tutorials</url>

	<author email="dthomas@osrfoundation.org">Dirk Thomas</author>
	<author>Josh Faust</author>
	<author email="mabel@openrobotics.org">Mabel Zhang</author>
	<author email="sloretz@openrobotics.org">Shane Loretz</author>

	<build_depend>qt5-qmake</build_depend>
	<build_depend>qtbase5-dev</build_depend>
		
	<buildtool_depend>ament_cmake</buildtool_depend>
	<buildtool_depend>rosidl_default_generators</buildtool_depend>

	<exec_depend>libqt5-core</exec_depend>
	<exec_depend>libqt5-gui</exec_depend>
	<exec_depend>rosidl_default_runtime</exec_depend>

	<depend>ament_index_cpp</depend>
	<depend>geometry_msgs</depend>
	<depend>rclcpp</depend>
	<depend>rclcpp_action</depend>
	<depend>std_msgs</depend>
	<depend>std_srvs</depend>

	<member_of_group>rosidl_interface_packages</member_of_group>

	<export>
	<build_type>ament_cmake</build_type>
	</export>
	</package>
```

## run

>**run** is command for execute an executable file from ros package.

```
ros2 run (/node_name) (executable_name)
```

**example:**

```
ros2 run turtlesim turtlesim_node
```

## service

| sub-command |Description
|--           |--
|call         |Call a service.
|find         |Output a list of available services of a given type.
|list         |Output a list of available services.
|type         |Output a service's type.

### // service call

> **service call** command will show

```
ros2 service call (service_name) (service_type)
```

**example:**

```
ros2 service call /turtle1/set_pen turtlesim/srv/SetPen
```

**output:**

```
requester: making request: turtlesim.srv.SetPen_Request(r=0, g=0, b=0, width=0, off=0)

response:
turtlesim.srv.SetPen_Response()
```

### // service find

> **service find** command will show service_name from using service type

```
ros2 service find (service_type)
```

**example:**

```
ros2 service find turtlesim/srv/SetPen
```

**output:**

```
/turtle1/set_pen
```

### // service list

>**service list** will show all of available service.

```
ros2 service list
```


### // service type

>**service type** command will showshow type of service by using service_name.

```
ros2 service type (service_name)
```

**example:**

```
ros2 service type /turtlesim/set_parameters
```

**output:**

```
rcl_interfaces/srv/SetParameters
```

## topic
| sub-command |Description
|--           |--
|bw           |Display bandwidth used by topic.
|delay        |Display delay of topic from timestamp in header.
|echo         |Output message from a topic.
|find         |Output a list of available topics of a given type.
|hz           |Print the average publishing rate to screend.
|info         |Print infomation about topic.
|list         |Output a list of available topics.
|pub          |Publish a message to a topic.
|type         |Print a topic's type.

### // bw

> **topic bw** command will show bandwidth using by topic.

```
ros2 topic bw (topic)
```

**example:**

```
ros2 topic bw /turtle1/pose
```

**output:**

```
1.51 KB/s from 62 messages
		Message size mean: 0.02 KM min: 0.02 KB max: 0.02 KB
1.50 KB/s from 100 messages
		Message size mean: 0.02 KM min: 0.02 KB max: 0.02 KB
1.51 KB/s from 100 messages
		Message size mean: 0.02 KM min: 0.02 KB max: 0.02 KB
.
.
.
```

>**ctrl+c** to break.
	

### // delay

>**topic delay** command will show delay between topic and header.

```
ros2 topic delay (topic)
```

**example:**

```
ros2 topic delay /turtle1/pose
```

### // echo

>**topic echo** command will show messages from topic.

```
ros2 topic echo (topic)
```

**example:**

```
ros2 topic echo /turtle1/pose
```

**output:**

```
x: 5.544444561004639
y: 5.544444561004639
theta: 0.0
linear_velocity: 0.0
angular_velocity: 0.0
```

### // find

>**topic find** command will return the **topic_name** by using **topic_type**

```
ros2 topic find (topic_type)
```

**example:**

```
ros2 topic find turtlesim/msg/Pose
```

**output:**

```
/turtle1/pose
```

### // hz

>** topic hz** command will; show an average publishing rate of topic_name.

```
ros2 topic hz (topic_name)
```

**example:**

```
ros2 topic hz /turtle1/pose
```

**output:**

```
average rate: 62.542
		min: 0.015s max:0.017s std dev: 0.00058s window: 64
average rate: 62.540
		min: 0.015s max:0.017s std dev: 0.00058s window: 127
average rate: 62.517
		min: 0.014s max:0.019s std dev: 0.00063s window: 190
.
.
.
```

>**ctrl+c** to break.


### // info

>**topic info** command will show an information of the topic by using topic_name.

```
ros2 topic info (topic_name)
```

**example:**

```
ros2 topic info /turtle1/pose
```

**outout:**

```
Type: turtlesim/msg/Pose
Publisher count: 1
Subscription count: 0
```

### // list

>**topic list** command will show all of current available topics.

**example:**

```
ros2 topic list
```

### // pub

>**topic pub** command will publish message to topic by choosing topic_name and set message_type for the topic.

```
ros2 topic pub (topic_name) (message_type)
```

**example:**
	
```
	ros2 topic pub /turtle1/pose message_type
```

### // type

>**topic type** command will return the **topic_type** by using **topic_name**

```
	ros2 topic type (topic_name)
```

**example:**

```
	ros2 topic type /turtle1/pose
```

**output:**

```
	turtlesim/msg/Pose
```

## Colcon

Stand for "Colored Console", It's a tool for build package for ROS2.

- **colcon build** use for crate workspace in current directory, 

**example:**

```
	@user:~$ colcon build
```

It's also can add an attribute **--symlink-install** for instead update reccently file.
**example:**

```
	@user:~$ colcon build --symlink-install
```

# ---------------------------------------------------------------

# Commonly  used commands

- ls
- cd
- mkdir
- rm
- cp
- mv
- cat
- nano
- top
- ipconfig
- clear
- history
- ps
- kill
- sudo
- reboot

## ls

>

|command                |Description
|--                     |--
|ls                     |list all of directory and folder in current directory.
|ls -a                  |list all file in current directory including hidden file.
|ls -l     		        |list all directory file in long format.

## cd 

>

|command                  |Description
|--                       |--
|cd                       |Move to home directory.
|cd -                     |Move to previous directory.
|cd ..                    |Move up one directory level.
|cd (directory_name/)     |Move to spacific directory.

>`dirs` , show current directory stack.


## mkdir

> Create new directory or folder

```
mkdir (directory_name) 
```

## rm

> Stand for **remove** command.

|command                  |Description
|--                       |--
|rm (file_name)	          |Remove a selected file.
|rm -r (directory_name)   |Remove a selected directory.
|rm -rf (directory_ma,e)  |Remove a selected directory without requiring confirmation.

## cp

>Stand for **copy** command.

|command                                           |Description
|--                                                |--
|cp (source_file) (destination_file) 			   |Copy content from source file to other file or destination file.
|cp -r (source_directory) (destination_directory)  |Copy directory to another directory.

## mv

>stand for **move** command, use for move/rename files or directories

```
move (source_file) (destination_file)
```

## touch

>**touch** command use for create a new empty file.

```
touch (file_name)
```


## cat

>Stands for **concatenate**. used to display content of one or more files

|command                   |Description
|--                        |--
|cat (file_name)           |Show content of file selected.
|cat (file_1) (file_2)     |Display the combined contents of file_1 and file_2.
|cat (file_1) > > (file_2) |Append file contents to another file.

## nano

>**nano** command is text editor used in Linux command line.

```
nano (file_name)
```
for open selected file with text editor in current directory.

```
nano (...directory address/) (file_name)
```
for open spacific file with text editor from directory location.


## source

>Read file content and execute commands from script or a file in current shell.

```
source (file_name)
```

## top

>provides a real-time, dynamic view of the system's performance. that shows a real-time view of running processes
```
top 	
```
|Command  |Description 
|--           |--
| top -n 10  	  |limits the number of updates displayed
| top -u username   		| Display Specific User Process
| top -h      |Shows top command syntax
| top -b         |Batch Mode
| top -s       | parameters
| top -c       |Command Line
| top -d seconds.tenths         |Delay time


### ipconfig

>The `ipconfig` command is a command-line utility used in Windows operating systems to display the configuration of network interfaces on a computer. It provides information about the IP (Internet Protocol) configuration, including IP address, subnet mask, default gateway, and DNS (Domain Name System) servers. The command is commonly used for troubleshooting network-related issues.

|Command  |Description 
|--           |--
|ipconfig  	  |displays basic information about all network interfaces on the system updates displayed.
|ipconfig /all   		| display detailed information about all network interfaces.
|ipconfig /release       |This command releases the currently assigned IP address for all network interfaces.
|ipconfig /renew         |This command requests a new IP address for all network interfaces from a DHCP server.
|ipconfig /flushdns       | to clear the DNS resolver cache, which may help resolve DNS-related issues.
|ipconfig /displaydns      |shows the contents of the DNS resolver cache, including resolved DNS names and their corresponding IP addresses.

## clear
>  
The `clear` command is used to clear the terminal screen or console window in Unix-like operating systems, including Linux. When you execute the `clear` command, it removes all the previous output from the terminal, providing a clean and empty screen. This can be useful to improve readability or to start a new set of commands without clutter from previous ones.
```
clear
```

## history
>The `history` command in Unix-like operating systems, including Linux, is used to display a list of previously executed commands in the current shell session. It allows users to view and recall their command history, making it easier to re-run or modify commands without retyping them.
>
|Command  |Description 
|--           |--
| history		|This command shows a numbered list of previously executed commands along with their command numbers.
| history 10 		| By specifying a number (in this case, 10), you can limit the display to a certain number of recent commands.
|!n      |Replace "n" with the command number from the history list. This allows you to quickly re-run a specific command.
| !!        |Batch Mode
| This command will re-run the last command executed in the current shell session.      | This command will re-run the last command executed in the current shell session.

* **Search Command History** You can use `grep` to search for specific commands containing a particular keyword in the command history.
```
	history | grep keyword 
```

## ps
>The `ps` command is a powerful and versatile command-line utility in Unix-like operating systems (including Linux) that provides information about currently running processes. It allows users to view details about processes, their resource utilization, and other attributes.
```
ps
```
|Command  |Description 
|--           |--
| ps aux  	  |display a more detailed list of all processes, including information about CPU and memory usage, the user who owns the process, and the command associated with each process.
| ps auxf   		| shows a tree-like view of processes, indicating parent-child relationships.
| ps -e --forest      |displays processes in a hierarchical tree structure, illustrating parent-child relationships.
| ps -p PID         |Replace "PID" with the specific Process ID to display information about a particular process.
| ps aux --sort=-%cpu       |This command sorts processes by CPU usage, showing the most CPU-intensive processes first.

## kill
>The `kill` command is used to terminate or signal processes. It sends a signal to a process, and the default signal is to terminate the process. The command is particularly useful for stopping unresponsive or misbehaving processes.

|Command  |Description 
|--           |--
| kill [process_id]  	  |Terminate a Linux process under agiven ID.
| pkill [process_name]   		| Terminate a process under a specific name.
| killall [label]     |Terminate all processes with a given label.


## sudo
>The `sudo` command in Unix-like operating systems, including Linux, is used to execute commands with elevated privileges. It stands for "superuser do" and allows authorized users to perform administrative tasks or run commands as another user, typically the root user.

|Command  |Description 
|--           |--
| `sudo useradd` `[user_name]`  	  |Create a new user account.
| `sudo adduser` `[user_name]`  		| Terminate a process under a specific name.
| `sudo userdel` `[user_name]`    |Delete a user account.
| `sudo` `[command]`  	  |Temporarily elevate user privileges to superuser or root.

## reboot
>  
The `reboot` command in Unix-like operating systems, including Linux, is used to restart the system. When you execute the `reboot` command, the system will shut down and then immediately restart. This command requires root or administrative privileges, so it is often used with the `sudo` command.
```
sudo reboot
```
## chmod
>The `chmod` command is used to change the permissions of a file or directory. It stands for "change mode." The `chmod` command allows users to modify the read, write, and execute permissions for the owner, group, and others.

|Command  |Description 
|--           |--
| `chmod 777` `[file_name]`  	  |Assign read. write, write, and execute file permission to everyone (rwxrwxrwx)
| `chmod 755` `[file_name]`  		| Give read, write, and execute permission to owner, and read and execute permission to group and others (rwxr-xr-x).
| `chmod 766` `[file_name]`    |Assign full permission to the owner, and read and write permission to the group and others (rwxrw-rw-).
