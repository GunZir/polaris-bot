// Copyright 2021 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef POLARIS_CONTROLLER__POLARIS_SYSTEM_HPP_
#define POLARIS_CONTROLLER__POLARIS_SYSTEM_HPP_

#include <memory>
#include <string>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"

#include "polaris_controller/visibility_control.h"

#include <messages/msg/motor_robot_speed.hpp>
#include <messages/msg/encoder_feed_back.hpp>

namespace polaris_controller
{

class PolarisSystemHardware : public hardware_interface::SystemInterface
{

// struct Config
// {
//   std::string left_wheel_name = "";
//   std::string right_wheel_name = "";
//   int enc_counts_per_rev = 0;
// };

public:
  RCLCPP_SHARED_PTR_DEFINITIONS(PolarisSystemHardware);

  POLARIS_CONTROLLER_PUBLIC
  hardware_interface::CallbackReturn on_init(
    const hardware_interface::HardwareInfo & info) override;

  POLARIS_CONTROLLER_PUBLIC
  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

  POLARIS_CONTROLLER_PUBLIC
  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  POLARIS_CONTROLLER_PUBLIC
  hardware_interface::CallbackReturn on_activate(
    const rclcpp_lifecycle::State & previous_state) override;

  POLARIS_CONTROLLER_PUBLIC
  hardware_interface::CallbackReturn on_deactivate(
    const rclcpp_lifecycle::State & previous_state) override;

  POLARIS_CONTROLLER_PUBLIC
  hardware_interface::return_type read(
    const rclcpp::Time & time, const rclcpp::Duration & period) override;

  POLARIS_CONTROLLER_PUBLIC
  hardware_interface::return_type write(
    const rclcpp::Time & time, const rclcpp::Duration & period) override;

private:

  std::vector<double> hw_commands_;
  std::vector<double> hw_positions_;
  std::vector<double> hw_velocities_;

  rclcpp::Subscription<messages::msg::EncoderFeedBack>::SharedPtr enc_feed_back_sub_;
  rclcpp::Publisher<messages::msg::MotorRobotSpeed>::SharedPtr cmd_vel_pub_;
  rclcpp::Node::SharedPtr node_;
  messages::msg::EncoderFeedBack enc_feed_back_;

  std::chrono::time_point<std::chrono::system_clock> time_;

  double counts_per_rev_;

  // Config cfg_;

  // Wheel left_wheel_;
  // Wheel right_wheel_;
};

}  // namespace polaris_controller

#endif  // POLARIS_CONTROLLER__POLARIS_SYSTEM_HPP_
