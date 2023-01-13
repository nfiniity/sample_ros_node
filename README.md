# Sample ROS2 project [![Build and Test](https://github.com/nfiniity/sample_ros_node/actions/workflows/main.yml/badge.svg)](https://github.com/nfiniity/sample_ros_node/actions/workflows/main.yml)

An simple ROS2 node example with message generation in C++. Following topics are covered in this project:
- Node implementation in C++ with publisher/subscriber
- Message generation
- Use of own message within the project
- Unit testing with gtest
- Github action for building and testing the project

## Build and run

In the root of your workspace, dev_ws, build your new package:

`colcon build --packages-select sample`

Now run the sample node:

`ros2 run sample sample_node`

Or run the provided launch file:

`ros2 launch sample sample.launch.py`

## Run tests

Still in the root of your workspace, dev_ws, run the tests:

`colcon test --packages-select sample --event-handlers console_direct+`

## Create ROS-Messages

### CMakeLists.txt
`find_package(rosidl_default_generators REQUIRED)`

`rosidl_generate_interfaces(${PROJECT_NAME} "msg/MyMessage.msg" "srv/MyService.srv")`

### package.xml
`<build_depend>rosidl_default_generators</build_depend>`

`<exec_depend>rosidl_default_runtime</exec_depend>`

`<member_of_group>rosidl_interface_packages</member_of_group>`


## Create components

### Source file

Add to the source files the following:

`#include "rclcpp_components/register_node_macro.hpp"`

`RCLCPP_COMPONENTS_REGISTER_NODE(MyNamespace::MyClassNode)`

### CMakeLists.txt

`find_package(rclcpp REQUIRED)`

`find_package(rclcpp_components REQUIRED)`

`set(node_plugins "")`

`add_library(MyComponent SHARED src/my_component.cpp)`

`rclcpp_components_register_nodes(MyComponent "MyNamespace::MyClassNode")`

`target_compile_definitions(MyComponent PRIVATE "COMPOSITION_BUILDING_DLL")`

`ament_target_dependencies(MyComponent "rclcpp" "rclcpp_components")`

`set(node_plugins "${node_plugins}MyNamespace::MyClassNode;$<TARGET_FILE:MyComponent>\n")`

`install(TARGETS MyComponent ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)`

### package.xml

`<depend>rclcpp</depend>`

`<depend>rclcpp_components</depend>`

### Usage

Start component container on a terminal:

`ros2 run rclcpp_components components_container`

Next, load on a second terminal:

`ros2 component load /ComponentManager MyNodeName MyNamespace::MyClassNode`

## Licence

This project is licensed under MIT. See [LICENSE](./LICENSE) file for details.

Copyright © 2023 nfiniity GmbH.
