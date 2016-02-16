#ifndef DEMOROBOT_H
#define DEMOROBOT_H

#include "Robot.h"
using namespace ros2_components;
class DemoRobot : public Robot
{
    Q_OBJECT

public:
     typedef std::shared_ptr<DemoRobot> SharedPtr;
     DemoRobot(int64_t _id, bool _subscribe, std::shared_ptr< rclcpp::node::Node > _parentNode);
     static DemoRobot::SharedPtr RebuildRobotFromId(int64_t id, std::shared_ptr< rclcpp::node::Node >  node)
     {

     }
};

#endif // DEMOROBOT_H
