from random import randint as rint
from random import choice as rand
from math import sin
from math import atan2
from math import hypot
from math import cos

def get_coord(xi,yi,zi,dec):
    m = rint(-2,2)
    n = rint(-3,3)
    x = rand([xi-n*dec,xi+m*dec])
    m = rint(-2,2)
    n = rint(-3,3)
    y = rand([yi-n*dec,yi+m*dec])
    m = rint(-2,2)
    n = rint(-3,3)
    z = rand([zi-n*dec,zi+m*dec])
    return [x,y,z]    

def get_coord2(xi,yi,zi,dec):
    x = xi+dec
    y = sin(x)
    z = atan2(hypot(x,y),sin(y))
    return [x,y,z]

def get_coord3(i):
    x = sin(i)*i
    y = i*hypot(x,i)
    z = atan2(hypot(x,y),sin(y))+x**2*y**2+hypot(x,y)
    return [x,y,z]