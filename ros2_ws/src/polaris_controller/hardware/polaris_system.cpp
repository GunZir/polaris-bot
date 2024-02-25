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

#include "polaris_controller/polaris_system.hpp"

#include <chrono>
#include <cmath>
#include <limits>
#include <memory>
#include <vector>

#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "rclcpp/rclcpp.hpp"

#include <rclcpp_components/register_node_macro.hpp>

#include <messages/msg/motor_robot_speed.hpp>
#include <messages/msg/encoder_feed_back.hpp>

namespace polaris_controller
{

hardware_interface::CallbackReturn PolarisSystemHardware::on_init(
  const hardware_interface::HardwareInfo & info)
{
  if (
    hardware_interface::SystemInterface::on_init(info) !=
    hardware_interface::CallbackReturn::SUCCESS)
  {
    return hardware_interface::CallbackReturn::ERROR;
  }

  hw_positions_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());
  hw_velocities_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());
  hw_commands_.resize(info_.joints.size(), std::numeric_limits<double>::quiet_NaN());

  // cfg_.left_wheel_name = info_.hardware_parameters["left_wheel_name"];
  // cfg_.right_wheel_name = info_.hardware_parameters["right_wheel_name"];
  // cfg_.enc_counts_per_rev = std::stoi(info_.hardware_parameters["enc_counts_per_rev"]);

  // // Set up the wheels
  // left_wheel_.setup(cfg_.left_wheel_name, cfg_.enc_counts_per_rev);
  // right_wheel_.setup(cfg_.right_wheel_name, cfg_.enc_counts_per_rev);

  node_ = rclcpp::Node::make_shared("hardware_interface");

  cmd_vel_pub_ = node_->create_publisher<messages::msg::MotorRobotSpeed>(
      "/esp32_uros/cmd_vel_to_uros", rclcpp::QoS(1));
  enc_feed_back_sub_ = node_->create_subscription<messages::msg::EncoderFeedBack>(
      "/esp32_uros/encoder_feed_back", rclcpp::SensorDataQoS(),
      [this](const messages::msg::EncoderFeedBack::SharedPtr enc) { enc_feed_back_ = *enc; });

  time_ = std::chrono::system_clock::now();

  counts_per_rev_ = 1708;

  for (const hardware_interface::ComponentInfo & joint : info_.joints)
  {
    // DiffBotSystem has exactly two states and one command interface on each joint
    if (joint.command_interfaces.size() != 1)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("PolarisSystemHardware"),
        "Joint '%s' has %zu command interfaces found. 1 expected.", joint.name.c_str(),
        joint.command_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.command_interfaces[0].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("PolarisSystemHardware"),
        "Joint '%s' have %s command interfaces found. '%s' expected.", joint.name.c_str(),
        joint.command_interfaces[0].name.c_str(), hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces.size() != 2)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("PolarisSystemHardware"),
        "Joint '%s' has %zu state interface. 2 expected.", joint.name.c_str(),
        joint.state_interfaces.size());
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces[0].name != hardware_interface::HW_IF_POSITION)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("PolarisSystemHardware"),
        "Joint '%s' have '%s' as first state interface. '%s' expected.", joint.name.c_str(),
        joint.state_interfaces[0].name.c_str(), hardware_interface::HW_IF_POSITION);
      return hardware_interface::CallbackReturn::ERROR;
    }

    if (joint.state_interfaces[1].name != hardware_interface::HW_IF_VELOCITY)
    {
      RCLCPP_FATAL(
        rclcpp::get_logger("PolarisSystemHardware"),
        "Joint '%s' have '%s' as second state interface. '%s' expected.", joint.name.c_str(),
        joint.state_interfaces[1].name.c_str(), hardware_interface::HW_IF_VELOCITY);
      return hardware_interface::CallbackReturn::ERROR;
    }
  }

  return hardware_interface::CallbackReturn::SUCCESS;
}

std::vector<hardware_interface::StateInterface> PolarisSystemHardware::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> state_interfaces;

  for (auto i = 0u; i < info_.joints.size(); i++)
  {
    state_interfaces.emplace_back(hardware_interface::StateInterface(
      info_.joints[i].name, hardware_interface::HW_IF_POSITION, &hw_positions_[i]));
    state_interfaces.emplace_back(hardware_interface::StateInterface(
      info_.joints[i].name, hardware_interface::HW_IF_VELOCITY, &hw_velocities_[i]));
  }


  return state_interfaces;
}

std::vector<hardware_interface::CommandInterface> PolarisSystemHardware::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> command_interfaces;
  
  // command_interfaces.emplace_back(hardware_interface::CommandInterface(left_wheel_.name, hardware_interface::HW_IF_VELOCITY, &left_wheel_.cmd));
  // command_interfaces.emplace_back(hardware_interface::CommandInterface(right_wheel_.name, hardware_interface::HW_IF_VELOCITY, &right_wheel_.cmd));
  for (auto i = 0u; i < info_.joints.size(); i++)
  {
    command_interfaces.emplace_back(hardware_interface::CommandInterface(
      info_.joints[i].name, hardware_interface::HW_IF_VELOCITY, &hw_commands_[i]));
  }

  return command_interfaces;
}

hardware_interface::CallbackReturn PolarisSystemHardware::on_activate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  RCLCPP_INFO(rclcpp::get_logger("PolarisSystemHardware"), "Activating ...please wait...");


  RCLCPP_INFO(rclcpp::get_logger("PolarisSystemHardware"), "Successfully activated!");

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::CallbackReturn PolarisSystemHardware::on_deactivate(
  const rclcpp_lifecycle::State & /*previous_state*/)
{
  // BEGIN: This part here is for exemplary purposes - Please do not copy to your production code
  RCLCPP_INFO(rclcpp::get_logger("PolarisSystemHardware"), "Deactivating ...please wait...");


  // END: This part here is for exemplary purposes - Please do not copy to your production code

  RCLCPP_INFO(rclcpp::get_logger("PolarisSystemHardware"), "Successfully deactivated!");

  return hardware_interface::CallbackReturn::SUCCESS;
}

hardware_interface::return_type PolarisSystemHardware::read(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  RCLCPP_INFO(rclcpp::get_logger("PolarisSystemHardware"), "Reading ...");
  if (rclcpp::ok())
  {
    rclcpp::spin_some(node_);
  }

  auto new_time = std::chrono::system_clock::now();
  std::chrono::duration<double> diff = new_time - time_;
  double deltaSeconds = diff.count();
  time_ = new_time;

  double pos_prev = hw_positions_[0];
  hw_positions_[0] = 2 * M_PI / counts_per_rev_;
  hw_velocities_[0] = (hw_positions_[0] - pos_prev) / deltaSeconds;

  pos_prev = hw_positions_[1];
  hw_positions_[1] = 2 * M_PI / counts_per_rev_;
  hw_velocities_[1] = (hw_positions_[1] - pos_prev) / deltaSeconds;

  return hardware_interface::return_type::OK;
}

hardware_interface::return_type polaris_controller ::PolarisSystemHardware::write(
  const rclcpp::Time & /*time*/, const rclcpp::Duration & /*period*/)
{
  RCLCPP_INFO(rclcpp::get_logger("PolarisSystemHardware"), "Writing...");

  auto command = messages::msg::MotorRobotSpeed();
  command.left_motor_speed = -1 * (hw_commands_[0] / (2 * M_PI) * counts_per_rev_);
  command.right_motor_speed = hw_commands_[1] / (2 * M_PI) * counts_per_rev_; 
  cmd_vel_pub_->publish(command);

  RCLCPP_INFO(rclcpp::get_logger("PolarisSystemHardware"), "Joints successfully written!");

  return hardware_interface::return_type::OK;
}

}  // namespace polaris_controller

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(
  polaris_controller::PolarisSystemHardware, hardware_interface::SystemInterface)
