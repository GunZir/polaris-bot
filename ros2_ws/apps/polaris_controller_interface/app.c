#include <stdio.h>
#include <unistd.h>

#include <rcl/rcl.h>
#include <rcl/error_handling.h>

#include <messages/msg/motor_robot_speed.h>
#include <messages/msg/encoder_feed_back.h>


#include "libs/e12Com.h"

#include <rclc/rclc.h>
#include <rclc/executor.h>

#ifdef ESP_PLATFORM
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#endif

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc);vTaskDelete(NULL);}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}


rcl_publisher_t publisher;
rcl_subscription_t subscriber;

messages__msg__EncoderFeedBack encoder;
messages__msg__MotorRobotSpeed cmd_vel;

typedef struct {
    double left;
    double right;
} MotorPPS;



void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
	
	RCLC_UNUSED(last_call_time);
	if (timer != NULL) {
		encoder.enc_right_wheel = dataSTM2ESP.encoderB;
		encoder.enc_left_wheel = dataSTM2ESP.encoderA;
		RCSOFTCHECK(rcl_publish(&publisher, &encoder, NULL));
		
	}
}

void subscription_callback(const void * msgin)
{
	const messages__msg__MotorRobotSpeed * command = (const messages__msg__MotorRobotSpeed *)msgin;

	dataESP2STM.speedB = command->right_motor_speed;
	dataESP2STM.speedA = command->left_motor_speed;
	
}

void appMain(void * arg)
{
	E12_init();
	dataESP2STM.kp = 2.05;
	dataESP2STM.ki = 9;
	dataESP2STM.kd = 0.0005;
	dataESP2STM.powerOn = 1;

	encoder.enc_right_wheel = dataSTM2ESP.encoderB;
	encoder.enc_left_wheel = dataSTM2ESP.encoderA;

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
		ROSIDL_GET_MSG_TYPE_SUPPORT(messages, msg, EncoderFeedBack),
		"/esp32_uros/encoder_feed_back"));
    
	// create subscriber
    RCCHECK(rclc_subscription_init_best_effort(
		&subscriber,
		&node,
		ROSIDL_GET_MSG_TYPE_SUPPORT(messages, msg, MotorRobotSpeed),
		"/esp32_uros/cmd_vel_to_uros"));

	
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
