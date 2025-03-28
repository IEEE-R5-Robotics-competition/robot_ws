import board
import busio
import adafruit_mlx90640
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool

class ThermalNode(Node):
    def __init__(self):
        super().__init__("thermal_node")
        self.ishot_pub = self.create_publisher(Bool, "/ishot", 10)
        self.i2c = busio.I2C(board.SCL, board.SDA)
        self.mlx = adafruit_mlx90640.MLX90640(self.i2c)
        self.mlx.refresh_rate = adafruit_mlx90640.RefreshRate.REFRESH_4_HZ
        self.frame = [0.0] * 768
        self.timer = self.create_timer(1.0, self.timer_callback)

    def timer_callback(self):
        try:
            self.mlx.getFrame(self.frame)
            average_temp = sum(self.frame) / len(self.frame)
            ishot = average_temp >  35.0  # Changed condition
            msg = Bool()
            msg.data = ishot
            self.ishot_pub.publish(msg)
            self.get_logger().info(f"Avg Temp: {average_temp:.2f}°C, Hot Detected: {ishot}")
        except Exception as e:
            self.get_logger().error(f"Error reading frame: {e}")

def main():
    rclpy.init()
    node = ThermalNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()

