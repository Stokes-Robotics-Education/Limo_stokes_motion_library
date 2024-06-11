#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/LaserScan.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "../include/stokes_sensor_functions.h"

uint32_t finalRed = 0;
uint32_t finalGreen = 0;
uint32_t finalBlue = 0;
float finalDistance = 0;

void colorCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  uint32_t red = msg->data[500100];
  uint32_t green = msg->data[500101];
  uint32_t blue = msg->data[500102];

  finalRed = red;
  finalGreen = green;
  finalBlue = blue;
}

void distanceCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
	float distancesChecked = 0;
	float distanceSum = 0;
	for(int i = 249; i < 252; i++){
	  float distance = msg->ranges[i];
	  if(distance != 0){
	    distanceSum += distance;
	    distancesChecked ++;
	  }
	}

	if(distanceSum != 0){
	  finalDistance = distanceSum / distancesChecked * .75;
	}
}

uint32_t DetectRed()
{

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/camera/color/image_raw", 1000, colorCallback);

  ros::Rate rate(10.0);

  for (int i = 0; i < 20; i++){
    ros::spinOnce();
    rate.sleep();
  }

  return finalRed;
}

uint32_t DetectGreen()
{
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/camera/color/image_raw", 1000, colorCallback);

  ros::Rate rate(10.0);

  for (int i = 0; i < 20; i++){
    ros::spinOnce();

    rate.sleep();
  }

  return finalGreen;
}

uint32_t DetectBlue()
{
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/camera/color/image_raw", 1000, colorCallback);

  ros::Rate rate(10.0);

  for (int i = 0; i < 20; i++){
    ros::spinOnce();

    rate.sleep();
  }

  return finalBlue;
}

float DetectDistance()
{

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/scan", 1000, distanceCallback);

  ros::Rate rate(10.0);

  for (int i = 0; i < 20; i++){
    ros::spinOnce();
    rate.sleep();
  }

  return finalDistance;
}
