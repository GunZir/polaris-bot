# ROS 2 : Cheat Sheets
for ros2 (Robot Operation System 2) .

	ros2 (command)

for more detail in `ros2` by using

	ros2 -h

>*in this **cheat sheets** of ROS2 command, will use `turtlesim` as an example.
so, for the same result you must run command **ros2 run turtlesim turtlesim_node** in background.*

## action

|sub-command  |Description                        
|--           |--                                  
| info        |Print information about an action. 
|list         |Output a list of action names.
|send_goal    |Send an action goal.

### action list

>**action list** command will show all name of actionavailable action. 

**example:**

	ros2 action list

**output:**
```
/turtle1/rotate_absolute
```

### action info

	ros2 action info (action_name)

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
### action send_goal
>**send_goal** *not in used*

## interface

|sub-command  |Description                                                  
|--           |--                                                            
|list         |List all interface types available.
|package      |Output a list of available interface types within one package.
|packages     |Output a list of packages that provide interface.
|proto        |Output and interface prototype.
|show         |Output the interface definition.

### interface list
>**interface list** command will show all available interface in every type of them.

**example:**

	ros2 interface list
**output:**

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
### interface package
	ros2 interface package (package_name)
>**interface package** command is use for show all available interface type in  ***one package***.

**example:**
	
	ros2 interface package turtlesim
**output:**
>after complie **`ros2 interface package turtlesim`** the output will show every interface that available in **`turtlesim`** package.

	turtlesim/action/RotateAbsolute
	turtlesim/srv/TeleportRelative
	.
	.
	turtlesim/msg/Color
### interface packages

	ros2 interface packages (attribute)
> The **interface packages** command is semilar with **interface package**, but the diffrent of **packages** is will show only one type

### attribute

|attribute              |Description  
|--                     |--
|**-m** *or* **--only-msgs**       |Only list packages that generate messages
|**-s** *or* **--only-srvs**       |Only list packages that generate services
|**-a** *or* **--only-actions**    |Only list packages that generate action

**example:**

	ros2 interface packages --only-action

>*attribute **--only-action** can replace with **-a** and still have the same result.*

**output:**

	action_tutorials_interfaces
	example_interfaces
	tf2_msgs
	turtlesim
	--------------------------------------------------------------------------
