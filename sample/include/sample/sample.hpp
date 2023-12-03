#pragma once

#include "rclcpp/rclcpp.hpp"
#include "sample/msg/sample_data.hpp"

namespace sample {

class SampleNode : public rclcpp::Node {
 public:
  SampleNode();

 private:
  // Methods
  void timer_callback();
  void topic_callback(const sample::msg::SampleData::SharedPtr msg) const;
  // Members
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sample::msg::SampleData>::SharedPtr publisher_;
  rclcpp::Subscription<sample::msg::SampleData>::SharedPtr subscription_;
  size_t count_;
};
}  // namespace sample
