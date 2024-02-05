import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import pyPLUTO.pload as pp
import pyPLUTO.Image as img

plutodir = "/home/martin/PLUTO"
wdir = plutodir+'/Rayleigh_Taylor/'

D0 = pp.pload(0,w_dir=wdir)
D1 = pp.pload(1,w_dir=wdir)
D2 = pp.pload(2,w_dir=wdir)
D3 = pp.pload(3,w_dir=wdir)
D4 = pp.pload(4,w_dir=wdir)
D5 = pp.pload(5,w_dir=wdir)

## SMART WAY##
I = img.Image()
I.multi_disp(D2.rho, D3.rho, D4.rho, D5.rho, x1=D0.x1,x2=D0.x2,Ncols=4, Nrows=1 ,
             cbar=(False,'vertical','last'),figsize=[12,7])
plt.show()
