#!/usr/bin/env python3
# coding=UTF-8
import rospy
from pylimo import limo
import time
import sensor_msgs.msg
from sensor_msgs.msg import LaserScan
from sensor_msgs.msg import Image
from std_msgs.msg import String

def DetectRed():
	rospy.init_node('color', anonymous=True)

	msg = rospy.wait_for_message("/camera/color/image_raw", Image, timeout=None)
	red = msg.data[500100]
	return red;

def DetectGreen():
	rospy.init_node('color', anonymous=True)

	msg = rospy.wait_for_message("/camera/color/image_raw", Image, timeout=None)
	green = msg.data[500101]
	return green;

def DetectBlue():
	rospy.init_node('color', anonymous=True)

	msg = rospy.wait_for_message("/camera/color/image_raw", Image, timeout=None)
	blue = msg.data[500102]
	return blue;

def DetectDistance():
	rospy.init_node('distance', anonymous=True)

	msg = rospy.wait_for_message("/scan", LaserScan, timeout=None)

	finalDistance = 0
	distancesChecked = 0
	distanceSum = 0
	for x in range(249, 252):
		distance = msg.ranges[x]
		if distance != 0:
			distanceSum += distance
			distancesChecked += 1
	  
	if distanceSum != 0:
		finalDistance = distanceSum / distancesChecked * .75

	return finalDistance;



