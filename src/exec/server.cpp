#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include "DemoRobot.h"
#include "DummySensor.h"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    auto node = rclcpp::node::Node::make_shared("DemoServer");
    DemoRobot::SharedPtr robot = std::make_shared<DemoRobot>(100, true, node);

    for(int i = 0; i<3;i++)
    {
        DummySensor::SharedPtr sensor = std::make_shared<DummySensor>(1000+i,false,node);
        robot->addChild(sensor);
    }

    robot->publishMetaInformation();
    auto func = [](EntityBase::SharedPtr ent)
    {
        ent->publishMetaInformation();
    };
    robot->IterateThroughAllChilds(func);
    robot->PrintTree();
    rclcpp::WallRate loop_rate(30);
    while (rclcpp::ok()) {

        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    return 0;

}
