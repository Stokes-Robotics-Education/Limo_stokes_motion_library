#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
#include "../include/stokes_motion_functions.h"



int main(int argc, char **argv)
{
    	// The ROS node is initialized
    	ros::init(argc, argv, "square_demo");


	Drive(50, 1);
	Strafe(50, 1);
	Drive(-50, 1);
	Strafe(-50, 1);

	return 0;

}

