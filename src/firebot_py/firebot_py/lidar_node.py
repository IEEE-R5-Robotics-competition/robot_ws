#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import math
from rplidar import RPLidar

class LidarNode(Node):
    def __init__(self):
        super().__init__('lidar_node')
        # Declare parameters (could also be loaded from a YAML file)
        self.declare_parameter('port', '/dev/ttyUSB0')
        self.declare_parameter('baudrate', 115200)
        self.declare_parameter('scan_frequency', 10.0)
        
        self.port = self.get_parameter('port').get_parameter_value().string_value
        self.baudrate = self.get_parameter('baudrate').get_parameter_value().integer_value
        self.scan_frequency = self.get_parameter('scan_frequency').get_parameter_value().double_value

        self.get_logger().info(f'Initializing RPLidar on port: {self.port} at {self.baudrate} baud.')

        try:
            self.lidar = RPLidar(self.port, baudrate=self.baudrate)
        except Exception as e:
            self.get_logger().error(f'Failed to initialize RPLidar: {e}')
            self.lidar = None

        self.scan_pub = self.create_publisher(LaserScan, 'scan', 10)
        timer_period = 1.0 / self.scan_frequency  # seconds per scan
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info('Lidar node initialized and publishing on topic "scan".')

    def timer_callback(self):
        if self.lidar is None:
            return

        try:
            # Get one full scan (list of tuples: (quality, angle, distance))
            scan = next(self.lidar.iter_scans())
            # Prepare LaserScan message with fixed 360-degree coverage
            scan_msg = LaserScan()
            scan_msg.header.stamp = self.get_clock().now().to_msg()
            scan_msg.header.frame_id = 'laser_frame'
            scan_msg.angle_min = 0.0
            scan_msg.angle_max = 2 * math.pi
            num_bins = 360
            scan_msg.angle_increment = (scan_msg.angle_max - scan_msg.angle_min) / num_bins
            scan_msg.time_increment = 0.0  # Optional: compute if needed
            scan_msg.scan_time = 1.0 / self.scan_frequency
            scan_msg.range_min = 0.15  # minimum valid range in meters (adjust per sensor spec)
            scan_msg.range_max = 6.0   # maximum valid range in meters (adjust per sensor spec)

            # Initialize bins with "infinite" range and zero intensity
            ranges = [float('inf')] * num_bins
            intensities = [0] * num_bins

            for quality, angle_deg, distance in scan:
                # Convert angle from degrees to radians
                angle_rad = math.radians(angle_deg)
                # Determine bin index (each bin represents one degree)
                index = int(angle_deg) % num_bins
                # Convert distance from millimeters to meters (adjust if your sensor units differ)
                distance_m = distance / 1000.0
                # In case multiple measurements fall in the same bin, keep the minimum distance
                if distance_m < ranges[index]:
                    ranges[index] = distance_m
                    intensities[index] = quality

            scan_msg.ranges = ranges
            scan_msg.intensities = intensities

            self.scan_pub.publish(scan_msg)
        except Exception as e:
            self.get_logger().error(f'Error reading lidar data: {e}')

    def destroy_node(self):
        if self.lidar is not None:
            self.lidar.stop()
            self.lidar.disconnect()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = LidarNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
