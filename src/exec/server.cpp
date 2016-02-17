#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include "DemoRobot.h"
#include "DummySensor.h"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    auto node = rclcpp::node::Node::make_shared("DemoServer");
    DemoRobot::SharedPtr robot = std::make_shared<DemoRobot>(100, false, node);
    DemoRobot::SharedPtr robot2 = std::make_shared<DemoRobot>(101, false, node);
    for(int i = 0; i<50;i++)
    {
        DummySensor::SharedPtr sensor = std::make_shared<DummySensor>(1000+i,false,node);
        robot->addChild(sensor);
        DummySensor::SharedPtr sensor2 = std::make_shared<DummySensor>(2000+i,false,node);
        robot2->addChild(sensor2);
    }

    robot->publishMetaInformation();
    robot2->publishMetaInformation();
    auto func = [](EntityBase::SharedPtr ent)
    {
        ent->publishMetaInformation();
    };
    robot->IterateThroughAllChilds(func);
    robot->PrintTree();
    robot2->IterateThroughAllChilds(func);
    rclcpp::WallRate loop_rate(30);
    while (rclcpp::ok()) {

        auto writeFunc =  [](DummySensor::SharedPtr sensor)
        {
            sensor->setValue(100);
            sensor->publish();
        };
        robot->IterateThroughAllChildsOfType<DummySensor>(writeFunc);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    return 0;

}
