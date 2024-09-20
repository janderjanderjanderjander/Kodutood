from turtle import *
import math
#input raadius ja number
r = float(50)
nr = 5

h = math.sqrt(0.5 * r * 0.5 * r + 100 * 100 )
LK = 0.5 * r
cosa = LK / h
a = math.cos(cosa)
print(a)

#raadius on 50
#lehtede arv on 5
#tan a = 200 / (raadius/2)