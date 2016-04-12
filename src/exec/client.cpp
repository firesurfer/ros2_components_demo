#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include "DemoRobot.h"
#include "DummySensor.h"
#include "ros2_simple_logger/Logger.h"
rclcpp::node::Node::SharedPtr node;
void spin()
{
    rclcpp::executors::SingleThreadedExecutor exec;
    std::cout << "spinning" << std::endl;
    rclcpp::WallRate loop_rate(20);
    while(rclcpp::ok())
    {
        exec.spin_node_some(node);
        loop_rate.sleep();
    }
}
int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    node = rclcpp::node::Node::make_shared("DemoClient");
    std::thread spinner(&spin);
    INIT_LOGGER(node);
    auto found = Robot::ListKnownRobots(node,"Demo");

    auto robot = DemoRobot::RebuildRobotFromId(100,node);
    auto robot2= DemoRobot::RebuildRobotFromId(101,node);
   // auto found2 = Robot::ListKnownRobots(node,"Demo");
    robot->PrintTree();
    rclcpp::WallRate loop_rate(30);
    std::string input = "";
    while(input != "exit")
    {   std::getline (std::cin,input);

        loop_rate.sleep();
    }

    return 0;

}
