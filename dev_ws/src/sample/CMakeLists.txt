cmake_minimum_required(VERSION 3.5)
project(sample)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(include)

# Messages
set(MSG_FILES
  "msg/SampleData.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${MSG_FILES}
  DEPENDENCIES std_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  find_package(ament_cmake_gtest REQUIRED)
  # Following skips linters
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  set(ament_cmake_cppcheck_FOUND TRUE)
  set(ament_cmake_flake8_FOUND TRUE)
  set(ament_cmake_pep257_FOUND TRUE)
  set(ament_cmake_xmllint_FOUND TRUE)
  set(ament_cmake_lint_cmake_FOUND TRUE)
  set(ament_cmake_uncrustify_FOUND TRUE)
  # Run all lint tests in package.xml except those listed above
  ament_lint_auto_find_test_dependencies()
  # Append tess files
  set(TESTFILES test/test_sample.cpp)
  # add gtest executables
  ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
  rosidl_target_interfaces(${PROJECT_NAME}_test
    ${PROJECT_NAME}
    "rosidl_typesupport_cpp"
  )
  ament_target_dependencies(${PROJECT_NAME}_test rclcpp std_msgs)
endif()

add_executable(sample_node src/sample_node.cpp src/sample.cpp)
ament_target_dependencies(sample_node rclcpp std_msgs) 

# Link against the interface
# Only if messages are used in the same package 
rosidl_target_interfaces(sample_node 
  ${PROJECT_NAME}
  "rosidl_typesupport_cpp"
)

install(TARGETS 
  sample_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
