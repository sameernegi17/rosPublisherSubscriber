#include <TurtleSimPublisher.h>
#include <nodesNameConstants.h>

int main(int argc, char **argv)
{
    TurtleSimPublisher *publisher = new TurtleSimPublisher(argc,
                                                           argv,
                                                           kVelocityPublisherNode);
    while (ros::ok())
    {
        publisher->CreateMessage();
        publisher->PublishMessage();
    }
    delete (publisher);
}