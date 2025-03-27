#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, TwistStamped

class TwistConverter(Node):
    def __init__(self):
        super().__init__('twist_stamper')
        
        # Subscribe to unstamped topic
        self.stamped_sub = self.create_subscription(
            TwistStamped, 
            '/cmd_vel', 
            self.stamped_callback, 
            10
        )
        
        # Publish to unstamped topic
        self.unstamped_pub = self.create_publisher(
            Twist, 
            '/cmd_vel_unstamped', 
            10
        )

    def stamped_callback(self, msg):
        # Convert stamped to unstamped
        unstamped_msg = Twist()
        unstamped_msg.linear = msg.twist.linear
        unstamped_msg.angular = msg.twist.angular
        self.unstamped_pub.publish(unstamped_msg)

def main(args=None):
    rclpy.init(args=args)
    node = TwistConverter()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()