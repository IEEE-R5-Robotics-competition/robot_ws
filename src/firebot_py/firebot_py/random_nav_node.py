#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import random
import math

class RandomNavNode(Node):
    def __init__(self):
        super().__init__('random_nav_node')
        self.goal_pub = self.create_publisher(PoseStamped, '/goal_pose', 10)
        self.timer_period = 10.0  # publish a new goal every 10 seconds
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        # Define arena size based on the 8x8 grid from the rules (assuming meters)
        self.arena_size = 8.0  
        self.get_logger().info("Random Navigation node started, publishing a goal every {:.1f} seconds".format(self.timer_period))

    def timer_callback(self):
        goal = PoseStamped()
        goal.header.frame_id = "map"
        goal.header.stamp = self.get_clock().now().to_msg()
        goal.pose.position.x = random.uniform(0.0, self.arena_size)
        goal.pose.position.y = random.uniform(0.0, self.arena_size)
        goal.pose.position.z = 0.0
        # Create a random yaw angle and convert it to quaternion (2D rotation)
        yaw = random.uniform(-math.pi, math.pi)
        qz = math.sin(yaw / 2.0)
        qw = math.cos(yaw / 2.0)
        goal.pose.orientation.x = 0.0
        goal.pose.orientation.y = 0.0
        goal.pose.orientation.z = qz
        goal.pose.orientation.w = qw

        self.goal_pub.publish(goal)
        self.get_logger().info("Published random goal: x={:.2f}, y={:.2f}, yaw={:.2f}".format(
            goal.pose.position.x, goal.pose.position.y, yaw))

def main(args=None):
    rclpy.init(args=args)
    node = RandomNavNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
