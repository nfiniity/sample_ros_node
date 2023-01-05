#include <gtest/gtest.h>

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sample/msg/sample_data.hpp"

using namespace sample;

class SampleNodeTests : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  virtual void TearDown() {}
};

TEST_F(SampleNodeTests, TestSampleDataMessage_InitValues) {
  auto msg = sample::msg::SampleData();
  constexpr uint32_t is_zero = 0;
  EXPECT_EQ(msg.count, is_zero);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
