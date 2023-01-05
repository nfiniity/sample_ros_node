#include "sample/sample.hpp"

#include <chrono>
#include <functional>

using namespace sample;
using namespace std::chrono_literals;

SampleNode::SampleNode() : Node("sample"), count_(0) {
  // Subscription
  subscription_ = this->create_subscription<sample::msg::SampleData>(
      "sample/topic", 10,
      std::bind(&SampleNode::topic_callback, this, std::placeholders::_1));

  // Publisher
  publisher_ =
      this->create_publisher<sample::msg::SampleData>("sample/topic", 10);

  // Periodic timer
  timer_ = this->create_wall_timer(
      500ms, std::bind(&SampleNode::timer_callback, this));
}

void SampleNode::timer_callback() {
  auto message = sample::msg::SampleData();
  message.data = "Hello, world!";
  message.count = count_++;
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
}

void SampleNode::topic_callback(
    const sample::msg::SampleData::SharedPtr msg) const {
  RCLCPP_INFO(this->get_logger(), "I heard: '%s', count: '%i'",
              msg->data.c_str(), msg->count);
}
