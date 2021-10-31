#include "ros/ros.h"
#include "std_msgs/String.h"

/*
 * This file is the listener node for test_pub_node.cpp.
 */

void chatterCallback(const std_msgs::String::ConstPtr& msg)	{	//Called when new message arrives in chatter topic.
	ROS_INFO("I heard: [%s]", msg->data.c_str());	//Message passed through shared pointer
}

int main(int argc, char** argv)	{
	ros::init(argc, argv, "listener");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);	//Subscribe in master to a topic called chatter. Save 1000 messages in buffer before deleting old messages.  Run above function when a message arrives
	ros::spin();	//enter loop calling message callbacks as much as possible
	
	return 0;
}
