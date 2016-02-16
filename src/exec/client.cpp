#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include "DemoRobot.h"
#include "DummySensor.h"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    auto node = rclcpp::node::Node::make_shared("DemoClient");
    auto found = Robot::ListKnownRobots("Demo",node);
    //auto found2 = Robot::ListKnownRobots("Demo",node);
    rclcpp::WallRate loop_rate(30);
    while (rclcpp::ok()) {

        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    return 0;

}
