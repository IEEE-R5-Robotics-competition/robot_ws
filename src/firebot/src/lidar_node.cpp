#include <rclcpp/rclcpp.hpp>

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("lidar_node");
  // TODO: Implement motor control logic here.
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
