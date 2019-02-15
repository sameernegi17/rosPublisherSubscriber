#include <TurtleSim.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

class TurtleSimSubscriber : public TurtleSim
{
public:
  TurtleSimSubscriber(int argc, char **argv, const std::string node_name);
  void SubscriberCallback(const geometry_msgs::Twist::ConstPtr &msg);
  void Subscribe();
  ~TurtleSimSubscriber();

private:
  ros::Subscriber command_velocity_subscriber_;
  ros::NodeHandle node_handle_;
  static long counter_;
  void Print(const geometry_msgs::Twist::ConstPtr &msg);
  void IncrementCounter();
};
