#ifndef DUMMYSENSOR_H
#define DUMMYSENSOR_H
#include "std_msgs/msg/float32.hpp"
#include "ros2_components/Entity.h"
using namespace ros2_components;
class DummySensor : public Entity<std_msgs::msg::Float32>
{
    Q_OBJECT
public:
    typedef std::shared_ptr<DummySensor> SharedPtr;

    DummySensor(int64_t _id, bool _subscribe, std::shared_ptr< rclcpp::node::Node > _parentNode);

    float getValue() const;
    void setValue(float value);
    virtual void  listenerCallback(const std_msgs::msg::Float32::SharedPtr msg);
    virtual bool publish();

private:
    int64_t someVar;
    int64_t someMoreVar;
    float value;
    std_msgs::msg::Float32::SharedPtr localMsg;
};

#endif // DUMMYSENSOR_H
