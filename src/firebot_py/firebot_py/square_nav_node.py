#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Bool
import math

class SquareNavNode(Node):
    def __init__(self):
        super().__init__('square_nav_node')
        self.goal_pub = self.create_publisher(PoseStamped, '/goal_pose', 10)
        self.timer_period = 30.0  # publish a new goal every 30 seconds
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        # Define square waypoints in meters (8 ft = ~2.44 m)
        self.waypoints = [
            (0.5, 0.5, 0.0),           # Bottom-left
            (2.0, 0.5, math.pi/2),     # Bottom-right
            (2.0, 2.0, math.pi),       # Top-right
            (0.5, 2.0, -math.pi/2)     # Top-left
        ]
        self.current_index = 0
        self.ishot = False

        # Subscribe to /ishot to monitor whether the robot should stop
        self.ishot_sub = self.create_subscription(Bool, '/ishot', self.ishot_callback, 10)

        self.get_logger().info("Square Navigation node started, publishing a goal every {:.1f} seconds".format(self.timer_period))

    def ishot_callback(self, msg):
        if msg.data:
            self.get_logger().info("🔥 Fire detected! Stopping navigation.")
            self.ishot = True
            self.stop_navigation()

    def stop_navigation(self):
        # Stop sending goals and optionally shut down
        self.get_logger().info("Stopping the navigation loop.")
        self.timer.cancel()  # Cancel the timer to stop publishing goals
        # If you want to shut down ROS gracefully:
        rclpy.shutdown()

    def timer_callback(self):
        if self.ishot:
            self.get_logger().info("Navigation stopped due to fire alert.")
            return  # If fire detected, stop the navigation

        x, y, yaw = self.waypoints[self.current_index]

        goal = PoseStamped()
        goal.header.frame_id = "map"
        goal.header.stamp = self.get_clock().now().to_msg()
        goal.pose.position.x = x
        goal.pose.position.y = y
        goal.pose.position.z = 0.0

        qz = math.sin(yaw / 2.0)
        qw = math.cos(yaw / 2.0)
        goal.pose.orientation.x = 0.0
        goal.pose.orientation.y = 0.0
        goal.pose.orientation.z = qz
        goal.pose.orientation.w = qw

        self.goal_pub.publish(goal)
        self.get_logger().info("Published goal {}: x={:.2f}, y={:.2f}, yaw={:.2f}".format(
            self.current_index + 1, x, y, yaw))

        self.current_index = (self.current_index + 1) % len(self.waypoints)

def main(args=None):
    rclpy.init(args=args)
    node = SquareNavNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
