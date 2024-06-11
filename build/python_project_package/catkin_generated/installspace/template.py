#!/usr/bin/env python3
# coding=UTF-8
from pylimo import limo
from stokes_sensor_functions import DetectDistance, DetectRed, DetectGreen, DetectBlue
import time
limo=limo.LIMO()
limo.EnableCommand()         # 使能控制s
#-------------------#
# type code in here #
print(DetectRed())
print(DetectGreen())
print(DetectBlue())



#-------------------#
