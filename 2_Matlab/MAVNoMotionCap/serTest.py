#serial communication testing

import serial
ser = serial.Serial(
    port='COM3',
    baudrate=57600,\
    timeout=0)
print ser.name
print "connected to: " + ser.portstr

line = []
while True:
    for c in ser.read():
        line.append(c)
        if c=='\n':
            print "Line: " + ''.join(line)
            line = []
            break
ser.close()