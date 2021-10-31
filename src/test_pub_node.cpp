#include "ros/ros.h"	//Include all necessary header files so it will work with ROS
#include "std_msgs/String.h"	//Include String message from std_msgs package
#include <sstream>

/*
 * This is a simple publisher node to send a message over the ROS system.
 */

int main(int argc, char **argv)	{
	ros::init(argc, argv, "test_pub_node");	//Init ROS node test_pub_node
	ros::NodeHandle n;	//Creates a Handle to process the node
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);	//Tell master we will publish a message of type chatter (master tells nodes listening on chatter that this node si publishing on that topic.  Saves 1000 messages in buffer before throwing away the oldest
	ros::Rate loop_rate(10);	//Frequency for the loop to run at (10 Hz here)

	int count = 0;
	while(ros::ok())	{	//False when Ctrl+C or quit
		std_msgs::String msg;	//Create message from std_msgs of type String and call it msg
		std::stringstream ss;	//Create StringStream object called ss
		ss << "hello world " << count;	//print to String Stream hello world and the current count
		msg.data = ss.str();	//Write to data of msg the concatinated String stream
		ROS_INFO("%s", msg.data.c_str());	//Works like printf or cout
		chatter_pub.publish(msg);
		ros::spinOnce();	//Needed so subscribers will not take over the processor and will let this publisher run from time to time
		loop_rate.sleep();	//Sleep the remaining time until we get to 10 Hz publish rate
		++count; //Increment
	}
	return 0;
}

