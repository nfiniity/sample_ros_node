# Sample ROS2 project [![Build and Test](https://github.com/nfiniity/sample_ros_node/actions/workflows/main.yml/badge.svg)](https://github.com/nfiniity/sample_ros_node/actions/workflows/main.yml)

An simple ROS2 node example with message generation in C++.

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

## Licence

This project is licensed under MIT. See [LICENSE](./LICENSE) file for details.

Copyright © 2023 nfiniity GmbH.
