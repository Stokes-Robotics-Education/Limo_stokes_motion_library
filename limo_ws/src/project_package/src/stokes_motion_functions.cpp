#include "../include/stokes_motion_functions.h"
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
using namespace std;
//
void Drive(float velocity, float time){
    // Create a node handle
	ros::NodeHandle n;

	// Create a Publisher and publish a topic called Chatter with a message type geometry_MSgs ::Twist
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

	//Set the frequency of the loop
	ros::Rate loop_rate(10);

   for ( int count = 0; count < time * 10 ; count++ )
   {
   //Set the speed at which you want to publish
    geometry_msgs::Twist twist;
    geometry_msgs::Vector3 linear;
    linear.x= velocity / 100.0;
    linear.y=0;
    linear.z=0;
    geometry_msgs::Vector3 angular;
    angular.x=0;
    angular.y=0;
    angular.z=0;
   
   //Assign the set speed to Twist
    twist.linear=linear;
    twist.angular=angular;

	//Publish the set speed
    chatter_pub.publish(twist);

    // Loop waiting for the callback function
    ros::spinOnce();

    // According to the cycle frequency delay
    loop_rate.sleep();

   }
}

void Strafe(float velocity, float time){
    // Create a node handle
	ros::NodeHandle n;

	// Create a Publisher and publish a topic called Chatter with a message type geometry_MSgs ::Twist
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

	//Set the frequency of the loop
	ros::Rate loop_rate(10);

   for ( int count = 0; count < time * 10 ; count++ )
   {
   //Set the speed at which you want to publish
    geometry_msgs::Twist twist;
    geometry_msgs::Vector3 linear;
    linear.x=0;
    linear.y= velocity / 100.0;
    linear.z=0;
    geometry_msgs::Vector3 angular;
    angular.x=0;
    angular.y=0;
    angular.z=0;
   
   //Assign the set speed to Twist
    twist.linear=linear;
    twist.angular=angular;

	//Publish the set speed
    chatter_pub.publish(twist);

    // Loop waiting for the callback function
    ros::spinOnce();

    // According to the cycle frequency delay
    loop_rate.sleep();

   }
}

void Turn(float velocity, float time){
    // Create a node handle
	ros::NodeHandle n;

	// Create a Publisher and publish a topic called Chatter with a message type geometry_MSgs ::Twist
	ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

	//Set the frequency of the loop
	ros::Rate loop_rate(10);

   for ( int count = 0; count < time * 10 ; count++ )
   {
   //Set the speed at which you want to publish
    geometry_msgs::Twist twist;
    geometry_msgs::Vector3 linear;
    linear.x=0;
    linear.y=0;
    linear.z=0;
    geometry_msgs::Vector3 angular;
    angular.x=0;
    angular.y=0;
    angular.z= velocity / 100.0;
   
   //Assign the set speed to Twist
    twist.linear=linear;
    twist.angular=angular;

	//Publish the set speed
    chatter_pub.publish(twist);

    // Loop waiting for the callback function
    ros::spinOnce();

    // According to the cycle frequency delay
    loop_rate.sleep();

   }
}

