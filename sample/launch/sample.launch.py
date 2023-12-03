from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sample',
            executable='sample_node',
            namespace='/sample',
            name='sample',
            output='screen'
        )
    ])