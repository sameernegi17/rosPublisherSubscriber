#include <TurtleSim.h>
#include <ros/ros.h>
#include <string.h>

TurtleSim::TurtleSim(int argc, char **argv, const std::string node_name)
{
    ros::init(argc, argv, node_name);
}

TurtleSim::~TurtleSim()
{
}