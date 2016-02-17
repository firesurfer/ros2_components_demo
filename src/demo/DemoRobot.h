#ifndef DEMOROBOT_H
#define DEMOROBOT_H

#include "Robot.h"
#include "DummySensor.h"
using namespace ros2_components;
class DemoRobot : public Robot
{
    Q_OBJECT

public:
    typedef std::shared_ptr<DemoRobot> SharedPtr;
    DemoRobot(int64_t _id, bool _subscribe, std::shared_ptr< rclcpp::node::Node > _parentNode);
    static DemoRobot::SharedPtr RebuildRobotFromId(int64_t id, std::shared_ptr< rclcpp::node::Node >  _parentNode)
    {
        std::cout << "Building Robot from id: " << id <<std::endl;


        auto reqFunc = [&] (int64_t _id, std::shared_ptr<rclcpp::node::Node> _node, std::string basename) -> ros2_components_msg::srv::ListChilds::Response::SharedPtr
        {
            std::string name = basename+std::to_string(_id)+"_srv";
            std::cout << "Looking for service with name: " << name << std::endl;
            auto client = _node->create_client<ros2_components_msg::srv::ListChilds>(name);

            auto request = std::make_shared<ros2_components_msg::srv::ListChilds::Request>();
            auto result = client->async_send_request(request);

            // Wait for the result.

            if (rclcpp::spin_until_future_complete(_node, result) == rclcpp::executor::FutureReturnCode::SUCCESS)
            {
                return result.get();
            }
            else
                throw std::runtime_error("Could not contact robot");


        };
        std::shared_ptr<DemoRobot> robot = std::make_shared<DemoRobot>(id, true,_parentNode);
        auto res = reqFunc(id, _parentNode, "DemoRobot");

        std::cout << "Childs: " << res->listsize << std::endl;
        for(uint64_t i = 0; i< res->childids.size(); i++)
        {

             int64_t compId = res->childids[i];
            if(res->childtypes[i].find("DummySensor") != std::string::npos)
            {
                std::cout << "Created dummy sensor with id:" << compId << std::endl;
                auto sensor = std::make_shared<DummySensor>(compId,true,_parentNode);
                robot->addChild(sensor);
            }
        }
        return robot;
    }
};

#endif // DEMOROBOT_H
