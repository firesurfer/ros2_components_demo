#include "DemoRobot.h"


using namespace ros2_components;
DemoRobot::DemoRobot(int64_t _id, bool _subscribe, std::shared_ptr<rclcpp::node::Node> _parentNode):Robot(_id,_subscribe,_parentNode, "DemoRobot")
{

}
