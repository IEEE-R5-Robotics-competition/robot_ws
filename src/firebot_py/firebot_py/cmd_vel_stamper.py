import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, TwistStamped
from builtin_interfaces.msg import Time


class CmdVelStamper(Node):
    def __init__(self):
        super().__init__('cmd_vel_stamper')

        self.declare_parameter('input_topic', '/cmd_vel_unstamped')
        self.declare_parameter('output_topic', '/diffbot_base_controller/cmd_vel_stamped')

        input_topic = self.get_parameter('input_topic').get_parameter_value().string_value
        output_topic = self.get_parameter('output_topic').get_parameter_value().string_value

        self.subscriber = self.create_subscription(
            Twist,
            input_topic,
            self.cmd_vel_callback,
            10
        )

        self.publisher = self.create_publisher(
            TwistStamped,
            output_topic,
            10
        )

    def cmd_vel_callback(self, msg: Twist):
        stamped_msg = TwistStamped()
        stamped_msg.header.stamp = self.get_clock().now().to_msg()
        stamped_msg.header.frame_id = 'base_link'
        stamped_msg.twist = msg
        self.publisher.publish(stamped_msg)


def main(args=None):
    rclpy.init(args=args)
    node = CmdVelStamper()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
