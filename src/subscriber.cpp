#include <TurtleSimSubscriber.h>
#include <nodesNameConstants.h>

int main(int argc, char **argv)
{
    TurtleSimSubscriber *subscriber = new TurtleSimSubscriber(argc,
                                                              argv,
                                                              kVelocitySuscriberNode);
    subscriber->Subscribe();
    delete (subscriber);
}