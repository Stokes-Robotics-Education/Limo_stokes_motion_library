#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
#include "../include/stokes_motion_functions.h"
#include "../include/stokes_sensor_functions.h"


int main(int argc, char **argv)
{
    // The ROS node is initialized
    ros::init(argc, argv, "program");


    //-------------------//
    // Type code in here //


    for(int i = 0; i < 20; i++){
        int g = DetectGreen();


        if (g > 150){
            Drive(50, 1);
        }
    }



    //-------------------//
	return 0;
}

