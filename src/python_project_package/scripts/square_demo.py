#!/usr/bin/env python3
# coding=UTF-8
from pylimo import limo
from stokes_limo_functions import DetectDistance, DetectRed, DetectGreen, DetectBlue, Drive, Turn, Strafe
import time
limo=limo.LIMO()
limo.EnableCommand()         # 使能控制s
#-------------------#
# type code in here #

#SetMotionCommand(linear_vel: 0.0, angular_vel: 0.0, lateral_velocity: 0.0, steering_angle: 0.0)
Drive(50, 3)
Strafe(50, 3)
Drive(-50, 3)
Strafe(-50, 3)
#-------------------#
