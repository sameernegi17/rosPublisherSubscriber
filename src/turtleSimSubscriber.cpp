#include <globalConstants.h>
#include <string.h>
#include <topicNameConstants.h>
#include <ros/ros.h>
#include <TurtleSimSubscriber.h>

long TurtleSimSubscriber::counter_ = 0;

TurtleSimSubscriber::TurtleSimSubscriber(int argc, char **argv, const std::string node_name)
    : TurtleSim::TurtleSim(argc, argv, node_name)
{
}

void TurtleSimSubscriber::Subscribe()
{
    command_velocity_subscriber_ = node_handle_.subscribe(kCommandVelocityTopic,
                                                          kQueueSize,
                                                          &TurtleSimSubscriber::SubscriberCallback,
                                                          this);
    ros::spin();
}
void TurtleSimSubscriber::SubscriberCallback(const geometry_msgs::Twist::ConstPtr &msg)
{
    Print(msg);
    IncrementCounter();
}
void TurtleSimSubscriber::Print(const geometry_msgs::Twist::ConstPtr &msg)
{
    std::cout << "Count : " << TurtleSimSubscriber::counter_ << std::endl;
    std::cout << "  Linear" << std::endl;
    std::cout << "      x: " << msg->linear.x << "  y: "
              << msg->linear.y << "    z: " << msg->linear.z << std::endl;
    std::cout << "  Angular" << std::endl;
    std::cout << "      x: " << msg->angular.x << "  y: "
              << msg->angular.y << "    z: " << msg->angular.z << std::endl;
}

void TurtleSimSubscriber::IncrementCounter()
{
    TurtleSimSubscriber::counter_ = TurtleSimSubscriber::counter_ + 1;
}
TurtleSimSubscriber::~TurtleSimSubscriber()
{
}