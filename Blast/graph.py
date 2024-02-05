import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import pyPLUTO as pypl
import pyPLUTO.pload as pp
import pyPLUTO.Image as img

plutodir = "/home/martin/PLUTO"
wdir = plutodir+'/Blast/'

D0 = pp.pload(0,w_dir=wdir)
D1 = pp.pload(1,w_dir=wdir)
D2 = pp.pload(2,w_dir=wdir)
D3 = pp.pload(3,w_dir=wdir)
D4 = pp.pload(4,w_dir=wdir)
I = img.Image()
#I.pldisplay(D1, D1.rho, x1=D1.x1, x2=D1.x2)
I.multi_disp(D1.rho, D2.rho, D3.rho, D4.rho, x1=D0.x1,x2=D0.x2,Ncols=2, Nrows=2)
#f1 = plt.figure(figsize=[4,12])
#plt.pcolormesh(D1.x1, D1.x2, D1.rho)
#ax1 = f1.add_subplot(131)
plt.show()
