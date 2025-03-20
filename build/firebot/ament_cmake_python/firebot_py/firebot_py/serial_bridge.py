#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import serial

class SerialBridge(Node):
    def __init__(self):
        super().__init__('serial_bridge')
        self.port = '/dev/ttyACM0'
        self.baudrate = 57600  # Adjust baud rate to match your Arduino's configuration
        
        # Attempt to open the serial port
        try:
            self.ser = serial.Serial(self.port, self.baudrate, timeout=1)
            self.get_logger().info(f'Opened serial port: {self.port} at {self.baudrate} baud.')
        except Exception as e:
            self.get_logger().error(f'Failed to open serial port {self.port}: {e}')
            self.ser = None

        # Subscribe to a topic to send messages out over serial
        self.subscription = self.create_subscription(
            String,
            'serial_out',
            self.serial_callback,
            10)
        self.subscription  # prevent unused variable warning

        # Create a timer to periodically check for data from the Arduino
        self.timer = self.create_timer(0.1, self.read_from_serial)  # every 0.1 seconds

    def serial_callback(self, msg: String):
        """Callback to send a received ROS message to the Arduino."""
        if self.ser is not None:
            message = msg.data + '\n'  # Append newline to mark end-of-message
            try:
                self.ser.write(message.encode('utf-8'))
                self.get_logger().info(f'Sent: {message.strip()}')
            except Exception as e:
                self.get_logger().error(f'Error writing to serial: {e}')

    def read_from_serial(self):
        """Poll the serial port and log any incoming messages."""
        if self.ser is not None and self.ser.in_waiting > 0:
            try:
                # Read a line from the serial buffer, decode it, and strip whitespace
                line = self.ser.readline().decode('utf-8').strip()
                if line:
                    self.get_logger().info(f'Received: {line}')
            except Exception as e:
                self.get_logger().error(f'Error reading from serial: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = SerialBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
