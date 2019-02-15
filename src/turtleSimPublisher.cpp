#include <geometry_msgs/Twist.h>
#include <string.h>
#include <topicNameConstants.h>
#include <globalConstants.h>
#include <TurtleSimPublisher.h>
#include <ros/ros.h>
#include <ros/rate.h>

TurtleSimPublisher::TurtleSimPublisher(int argc, char **argv, const std::string node_name)
    : TurtleSim::TurtleSim(argc, argv, node_name)
{
    command_velocity_publisher_ = node_handle_.advertise<geometry_msgs::Twist>(kCommandVelocityTopic,
                                                                               kQueueSize);
    rate_ = new ros::Rate(1);
}

void TurtleSimPublisher::PublishMessage()
{
    command_velocity_publisher_.publish(msg_);
    rate_->sleep();
}

void TurtleSimPublisher::CreateMessage()
{
    msg_.linear.x = CreateRandomAngularVelocity();
    msg_.angular.z = CreateRandomAngularVelocity();
}

int TurtleSimPublisher::CreateRandomLinearVelocity()
{
    return (rand() % velocity::kMaxLinearVelocity) + velocity::kMinLinearVelocity;
}

int TurtleSimPublisher::CreateRandomAngularVelocity()
{
    return (rand() % velocity::kMaxAngularVelocity) + velocity::kMinAngularVelocity;
}

TurtleSimPublisher::~TurtleSimPublisher()
{
    delete (rate_);
}
