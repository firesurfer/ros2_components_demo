#include "DummySensor.h"
using namespace ros2_components;
DummySensor::DummySensor(int64_t _id, bool _subscribe, std::shared_ptr<rclcpp::node::Node> _parentNode):Entity(_id,_subscribe,_parentNode, "DummySensor")
{
    someVar = 0;
    someMoreVar = 100;
    REFLECT(someVar);
    REFLECT(someMoreVar);

    localMsg= std::make_shared<std_msgs::msg::Float32>();
}

float DummySensor::getValue() const
{
    return value;
}

void DummySensor::setValue(float value)
{
    value = value;
}

void DummySensor::listenerCallback(const std_msgs::msg::Float32::SharedPtr msg)
{
    this->value = msg->data;
}

bool DummySensor::publish()
{
    localMsg->data = value;
    entityPublisher->publish(localMsg);
}
