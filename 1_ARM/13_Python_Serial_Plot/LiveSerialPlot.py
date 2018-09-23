import serial
import numpy
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style
import time
style.use('fivethirtyeight')
fig =plt.figure()
ax1 = fig.add_subplot(1,1,1)
x = [0]
y = [0]
z = [0]
li, = ax1.plot(x,y, 'ro')
#ax1.relim()
#ax1.autoscale_view(True, True, True)
fig.canvas.draw()
plt.show(block = False)
ser = serial.Serial('COM12', 57600)
def animate(i):
    new = ser.readline()
    news = new.split(',')
    x.append(float(news[0]))
    y.append(float(news[1]))
    ax1.clear()
    ax1.plot(x, y)
ani = animation.FuncAnimation(fig, animate, interval=1000)
plt.show()
#while True:
    #new = ser.readline()
    #news = new.split(',')
    #x.append(float(news[0]))
    #y.append(float(news[1]))
    #z.append(float(news[2]))
    #li.set_ydata(y)
    #li.set_xdata(x)
    #fig.canvas.draw()
#time.sleep(0.01)
#print("done")
    
#####
    
#import numpy as np
#import matplotlib.pyplot as plt
#import matplotlib.animation as animation
#import serial
#
#fig, ax = plt.subplots()
#line, = ax.plot(np.random.rand(10))
#ax.set_ylim(-5000, 5000)
#xdata, ydata = [0]*100, [0]*100
#raw = serial.Serial("COM12",57600)
#raw.open()
#
#def update(data):
#    line.set_ydata(data)
#    return line,
#
#def run(data):
#    t,y = data
#    del xdata[0]
#    del ydata[0]
#    xdata.append(t)
#    ydata.append(y)
#    line.set_data(xdata, ydata)
#    return line,
#
#def data_gen():
#    t = 0
#    while True:
#        t+=0.1
#        try:
#            dat = int(raw.readline())
#        except:
#            dat = 0
#        yield t, dat
#
#ani = animation.FuncAnimation(fig, run, data_gen, interval=0, blit=True)
#plt.show()

