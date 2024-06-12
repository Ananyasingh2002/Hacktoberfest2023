import time
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

#constants
g = 9.81 #m/s2
M_empty_ship = 10000 #kg
y_0 = 1000

#variables or future variables
y = 0 #y(t)
v_0 = 10 #en futuro sera v(t)

#todo momentum change fuel
#pressure change
#momentum desacoplar
#friction
#earth spin

#start

y = y_0
v = v_0
print("y = %.2f" %y, "m", "\tv = %.2f" %v, "m/s")
print("\n")

while True:
    
    v = v - g
    
    if(v != 0):
        y = y + v
    if(y < 0):
        print("Crash! At %.2f" %v, "m/s")
        break
    
    print("y = %.2f" %y, "m", "\tv = %.2f" %v, "m/s")
    print("\n")
    
    plt.clf()
    plt.plot(0, 0, '.')
    plt.plot(0, 1000, '.')
    plt.plot(0, y, '*')
    plt.show()
    
    time.sleep(0.5)
    
