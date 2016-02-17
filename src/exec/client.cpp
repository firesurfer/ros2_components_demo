#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include "DemoRobot.h"
#include "DummySensor.h"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);


    auto node = rclcpp::node::Node::make_shared("DemoClient");
    auto found = Robot::ListKnownRobots(node,"Demo");

    auto robot = DemoRobot::RebuildRobotFromId(100,node);
    auto robot2= DemoRobot::RebuildRobotFromId(101,node);
    auto found2 = Robot::ListKnownRobots(node,"Demo",);
    robot->PrintTree();
    rclcpp::WallRate loop_rate(30);
    while (rclcpp::ok()) {

        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    return 0;

}
