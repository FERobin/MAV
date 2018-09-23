#Serial Data Collection
#Collect data from Optical Flow over Zigbee serial communication
#Not yet tested as of 6/23/2018
#Or 7/20/2018
#Or 8/7/2018

import serial
from time import sleep

#Get position of quadrotor in x,y,z
def pos():
    x = []
    y = []
    z = []    
    #ser = serial.Serial('COM0', 57600)
    ser = serial.Serial(\
    port="/dev/ttyUSB0",\
  	baudrate=57600,\
	timeout=1)
    #ser.port = "/dev/ttyUSB0"
    #ser.baudrate = 57600
    
    new = ser.readline()
    news = new.split(',')
    try:
    	x.append(news[0])
    	y.append(news[1])
    	z.append(news[2])
    except ValueError:
        print 'Data looks like this:', news
	break
    return [x, y, z]

#Get angle of quadrotor in roll,pitch,yaw
#less confident about this working
def ang():
    r = [] #roll
    p = [] #pitch
    y = [] #yaw
    ser = serial.Serial(\
	port="/dev/ttyUSB1",\
	baudrate=57600,\
	timeout=1)
    #ser = serial.Serial('COM0', 57600)
    #ser.open()
    #sleep(1)
    new = ser.readline()
    news = new.split(',')
    #ser.close()
    try:
    	r.append(news[3])
    	p.append(news[4])
    	y.append(news[5])
    except:
        print 'Data looks like this', news
	break
    return [r, p, y]

def testDat():
    x = []
    y = []
    z = []
    ser = serial.Serial(\
	port="/dev/ttyUSB1",\
	baudrate=57600,\
	timeout=1)
    new = ser.readline()
    news = new.split(',')
    return news
