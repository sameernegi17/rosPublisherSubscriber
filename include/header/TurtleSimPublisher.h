#include <TurtleSim.h>
#include <geometry_msgs/Twist.h>
#include <string.h>
#include <ros/rate.h>

class TurtleSimPublisher : public TurtleSim
{
public:
  TurtleSimPublisher(int argc, char **argv, const std::string node_name);
  ~TurtleSimPublisher();
  void CreateMessage();
  void PublishMessage();

private:
  ros::Publisher command_velocity_publisher_;
  geometry_msgs::Twist msg_;
  ros::NodeHandle node_handle_;
  ros::Rate *rate_;
  int CreateRandomLinearVelocity();
  int CreateRandomAngularVelocity();
};
