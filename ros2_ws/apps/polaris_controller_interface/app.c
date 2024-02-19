#include <stdio.h>
#include <unistd.h>

#include <rcl/rcl.h>
#include <rcl/error_handling.h>

#include <std_msgs/msg/int32.h>
#include <messages/msg/motor_robot_speed.h>
#include <geometry_msgs/msg/twist.h>

#include <sensor_msgs/msg/joint_state.h>

#include "libs/e12Com.h"

#include <rclc/rclc.h>
#include <rclc/executor.h>

#ifdef ESP_PLATFORM
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#endif

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc);vTaskDelete(NULL);}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}

#define WHEEL_BASE 0.125
// #define WHEEL_RADIUS 0.0625
#define GAMMA  2994.6594

rcl_publisher_t publisher;
rcl_subscription_t subscriber;

geometry_msgs__msg__Twist cmd_vel;
messages__msg__MotorRobotSpeed encoder_msg;
// sensor_msgs__msg__JointState joint_stat;

typedef struct {
    double left;
    double right;
} MotorPPS;



void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
	
	RCLC_UNUSED(last_call_time);
	if (timer != NULL) {
		encoder_msg.right_motor_speed = dataSTM2ESP.encoderB;
		encoder_msg.left_motor_speed = dataSTM2ESP.encoderA;
		RCSOFTCHECK(rcl_publish(&publisher, &encoder_msg, NULL));
		
	}
}

void subscription_callback(const void * msgin)
{
	const geometry_msgs__msg__Twist * msg = (const geometry_msgs__msg__Twist *)msgin;

	MotorPPS PPS;

	PPS.left = -(msg->linear.x - msg->angular.z * WHEEL_BASE / 2.0) * GAMMA;  // pulse per sec
    PPS.right = (msg->linear.x + msg->angular.z * WHEEL_BASE / 2.0) * GAMMA;

	dataESP2STM.speedB = PPS.right;
	dataESP2STM.speedA = PPS.left;
	
}

void appMain(void * arg)
{
	E12_init();
	dataESP2STM.kp = 2.05;
	dataESP2STM.ki = 9;
	dataESP2STM.kd = 0.0005;
	dataESP2STM.powerOn = 1;

	encoder_msg.right_motor_speed = dataSTM2ESP.encoderB;
	encoder_msg.left_motor_speed = dataSTM2ESP.encoderA;

	rcl_allocator_t allocator = rcl_get_default_allocator();
	rclc_support_t support;
	

	rcl_node_t node;

	// create init_options
	RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

	// create node
	RCCHECK(rclc_node_init_default(&node, "polaris_controller_interface", "", &support));

	rcl_timer_t timer;
	const unsigned int timer_timeout = 10;
	// create publisher
	RCCHECK(rclc_publisher_init_best_effort(
		&publisher,
		&node,
		ROSIDL_GET_MSG_TYPE_SUPPORT(messages, msg, MotorRobotSpeed),
		"/polaris/encoder"));
    
	// create subscriber
    RCCHECK(rclc_subscription_init_best_effort(
		&subscriber,
		&node,
		ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
		"/diff_cont/cmd_vel_unstamped"));

	
	// create timer,
	RCCHECK(rclc_timer_init_default(
		&timer,
		&support,
		RCL_MS_TO_NS(timer_timeout),
		timer_callback));

	rclc_executor_t executor;
	// create executor
	RCCHECK(rclc_executor_init(&executor, &support.context, 2, &allocator));

    // add timer callback
	RCCHECK(rclc_executor_add_timer(&executor, &timer));

    // add subscriber callback
    RCCHECK(rclc_executor_add_subscription(&executor, &subscriber, &cmd_vel, &subscription_callback, ON_NEW_DATA));
	
	while(1){
		rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1));
		
		if(esp_timer_get_time() - prevMicros > 200000){
            GPIO.out ^= (1<<2);
            prevMicros = esp_timer_get_time();
        }
		E12_transmit();
		usleep(10);
	}

	// free resources
	RCCHECK(rcl_publisher_fini(&publisher, &node))
	RCCHECK(rcl_publisher_fini(&subscriber, &node))
	RCCHECK(rcl_node_fini(&node))

  	vTaskDelete(NULL);
}
