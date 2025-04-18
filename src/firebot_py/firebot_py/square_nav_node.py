# #!/usr/bin/env python3
# import rclpy
# from rclpy.node import Node
# from geometry_msgs.msg import PoseStamped
# from std_msgs.msg import Bool
# import math

# class SquareNavNode(Node):
#     def __init__(self):
#         super().__init__('square_nav_node')
#         self.goal_pub = self.create_publisher(PoseStamped, '/goal_pose', 10)
#         self.timer_period = 30.0  # publish a new goal every 30 seconds
#         self.timer = self.create_timer(self.timer_period, self.timer_callback)

#         # Define square waypoints in meters (8 ft = ~2.44 m)
#         # self.waypoints = [
#         #     (0.5, 0.5, 0.0),           # Bottom-left
#         #     (1.8, 0.5, math.pi/2),     # Bottom-right
#         #     (1.8, 1.8, math.pi),       # Top-right
#         #     (0.5, 1.8, -math.pi/2)     # Top-left
#         # ]
#         self.waypoints = [
#             (0.5, 0.5, 0.0),           # Bottom-left
#             (0.5, 0.5, math.pi/2),     # Bottom-right
#             (0.5, 0.5, math.pi),       # Top-right
#             (0.5, 0.5, -math.pi/2)     # Top-left
#         ]

#         self.current_index = 0
#         self.ishot = False

#         # Subscribe to /ishot to monitor whether the robot should stop
#         self.ishot_sub = self.create_subscription(Bool, '/ishot', self.ishot_callback, 10)

#         self.get_logger().info("Square Navigation node started, publishing a goal every {:.1f} seconds".format(self.timer_period))

#     def ishot_callback(self, msg):
#         if msg.data:
#             self.get_logger().info("🔥 Fire detected! Stopping navigation.")
#             self.ishot = True
#             self.stop_navigation()

#     def stop_navigation(self):
#         # Stop sending goals and optionally shut down
#         self.get_logger().info("Stopping the navigation loop.")
#         self.timer.cancel()  # Cancel the timer to stop publishing goals
#         # If you want to shut down ROS gracefully:
#         rclpy.shutdown()

#     def timer_callback(self):
#         if self.ishot:
#             self.get_logger().info("Navigation stopped due to fire alert.")
#             return  # If fire detected, stop the navigation

#         x, y, yaw = self.waypoints[self.current_index]

#         goal = PoseStamped()
#         goal.header.frame_id = "odom"
#         goal.header.stamp = self.get_clock().now().to_msg()
#         goal.pose.position.x = x
#         goal.pose.position.y = y
#         goal.pose.position.z = 0.0

#         qz = math.sin(yaw / 2.0)
#         qw = math.cos(yaw / 2.0)
#         goal.pose.orientation.x = 0.0
#         goal.pose.orientation.y = 0.0
#         goal.pose.orientation.z = qz
#         goal.pose.orientation.w = qw

#         self.goal_pub.publish(goal)
#         self.get_logger().info("Published goal {}: x={:.2f}, y={:.2f}, yaw={:.2f}".format(
#             self.current_index + 1, x, y, yaw))

#         self.current_index = (self.current_index + 1) % len(self.waypoints)

# def main(args=None):
#     rclpy.init(args=args)
#     node = SquareNavNode()
#     rclpy.spin(node)
#     node.destroy_node()
#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time

class SquareNavNode(Node):
    def __init__(self):
        super().__init__('square_nav_node')
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.state = 'forward'
        self.start_time = self.get_clock().now()
        self.get_logger().info("square_nav_node started")

    def timer_callback(self):
        elapsed = (self.get_clock().now() - self.start_time).nanoseconds / 1e9

        twist = Twist()

        if self.state == 'forward' and elapsed < 5.0:
            twist.linear.x = 0.1
            self.cmd_vel_pub.publish(twist)
            self.get_logger().info("Moving forward...")
        elif self.state == 'forward':
            self.state = 'backward'
            self.start_time = self.get_clock().now()
        elif self.state == 'backward' and elapsed < 5.0:
            twist.linear.x = -0.1
            self.cmd_vel_pub.publish(twist)
            self.get_logger().info("Moving backward...")
        else:
            self.get_logger().info("Stopping and shutting down.")
            self.cmd_vel_pub.publish(Twist())  # Stop movement
            rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = SquareNavNode()
    rclpy.spin(node)

if __name__ == '__main__':
    main()
