cmake_minimum_required(VERSION 3.16)
project(polaris_controller LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
  add_compile_options(-Wall -Wextra)
endif()

# find dependencies
set(THIS_PACKAGE_INCLUDE_DEPENDS
  hardware_interface
  pluginlib
  rclcpp
  rclcpp_lifecycle
  rclcpp_components
  rosidl_default_generators 
  messages
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

## COMPILE
add_library(
  polaris_controller
  SHARED
  hardware/polaris_system.cpp
)
target_compile_features(polaris_controller PUBLIC cxx_std_17)
target_include_directories(polaris_controller PUBLIC
$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/hardware/include>
$<INSTALL_INTERFACE:include/polaris_controller>
)
ament_target_dependencies(
  polaris_controller PUBLIC
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
)

rclcpp_components_register_nodes(${PROJECT_NAME}
  "polaris_controller::HardwareCommandPub")

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(${PROJECT_NAME} PRIVATE "POLARIS_CONTROLLER_BUILDING_DLL")

# Export hardware plugins
pluginlib_export_plugin_description_file(hardware_interface polaris_controller.xml)

# INSTALL
install(
  DIRECTORY hardware/include/
  DESTINATION include/polaris_controller
)
install(
  DIRECTORY description/launch description/ros2_control description/urdf
  DESTINATION share/polaris_controller
)
install(
  DIRECTORY bringup/launch bringup/config
  DESTINATION share/polaris_controller
)
install(TARGETS polaris_controller
  EXPORT export_polaris_controller
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_cmake_pytest REQUIRED)

  ament_add_pytest_test(example_2_urdf_xacro test/test_urdf_xacro.py)
  ament_add_pytest_test(view_example_2_launch test/test_view_robot_launch.py)
endif()

## EXPORTS
ament_export_targets(export_polaris_controller HAS_LIBRARY_TARGET)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
