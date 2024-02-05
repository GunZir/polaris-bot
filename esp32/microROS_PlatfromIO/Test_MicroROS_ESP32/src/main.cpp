#include <Arduino.h> //Call function in Arduino like "digitalWrite", "analogWrite"
#include <micro_ros_platformio.h> // for compatibation between Micro-ROS and platfromIO

// For ROS2 environment
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

// For message type
#include <std_msgs/msg/int32.h>
#include <std_msgs/msg/string.h>

// This checks whether the macro MICRO_ROS_TRANSPORT_ARDUINO_SERIAL is not defined. 
// If it's not defined, the code within the conditional block will be included during compilation.
#if !defined(MICRO_ROS_TRANSPORT_ARDUINO_SERIAL)
#error This example is only avaliable for Arduino framework with serial transport.
#endif

// Declare the subscriber variable
rcl_publisher_t publisher_int;
rcl_publisher_t publisher_string;
rcl_subscription_t subscriber;

// Declare message variables
std_msgs__msg__Int32 msg_int;
std_msgs__msg__String msg_string;

rclc_executor_t executor; //it will be used to control the execution of tasks within the ROS 2 system.
rclc_support_t support; //holds the support configuration for the node.
rcl_allocator_t allocator; //this will be used for memory allocation within the ROS 2 system.
rcl_node_t node; //it represents the ROS 2 node in the provided code.
rcl_timer_t timer; //it represents a ROS 2 timer in the provided code. 

//This macro gonna check the return value of a function (fn), if return value is not equal to RCL_RET_OK, it call error_loop()
// RCL_RET_OK is represents a successful or "OK" return status from a ROS 2 function.
#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

// Error handle loop
void error_loop() {
  while(1) {
    delay(100);
  }
}


void timer_callback(rcl_timer_t * timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    
    //Publisher String
    RCSOFTCHECK(rcl_publish(&publisher_string, &msg_string, NULL));
    msg_string.data.data = "heyy";
    msg_string.data.size = strlen(msg_string.data.data);

    ////Publisher Int32
    RCSOFTCHECK(rcl_publish(&publisher_int, &msg_int, NULL));
    msg_int.data++;
  }
}
  // int64_t last_call_time and RCLC_UNUSED(last_call_time) must have i don't know why but if you delete create timer function isn't gonna complie :) 

void setup() {
  // Configure serial transport
  Serial.begin(115200);
  set_microros_serial_transports(Serial);
  delay(2000);

  allocator = rcl_get_default_allocator();

  //create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "micro_ros_platformio_node", "", &support));

  // create publisher
  RCCHECK(rclc_publisher_init_default(
    &publisher_int,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "micro_ros_platformio_node_publisher"));

  // create timer,
  const unsigned int timer_timeout = 1000;
  RCCHECK(rclc_timer_init_default(
    &timer,
    &support,
    RCL_MS_TO_NS(timer_timeout),
    timer_callback));

  // create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor, &timer));

  msg_int.data = 0;
}

void loop() {
  delay(100);
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
}