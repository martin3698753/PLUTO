import os
import sys
import numpy as np
import matplotlib.pyplot as plt
import pyPLUTO as pypl
import pyPLUTO.pload as pp
import pyPLUTO.Image as img

plutodir = "/home/martin/PLUTO"
wdir = plutodir+'/Jet/'

D0 = pp.pload(0,w_dir=wdir)
D1 = pp.pload(1,w_dir=wdir)
D2 = pp.pload(2,w_dir=wdir)
D3 = pp.pload(3,w_dir=wdir)
I = img.Image()
#I.pldisplay(D2, D2.rho[:,0,:], x1=D0.x1, x2=D0.x3)
I.multi_disp(D1.rho[:,0,:], D2.rho[:,0,:], D3.rho[:,0,:], x1=D0.x1, x2=D0.x3,
             Ncols=3, cbar=(True, 'vertical', 'last'))
#f1 = plt.figure(figsize=[4,12])
#plt.pcolormesh(D3.x1, D3.x3, D3.rho[:,0,:].T)
#ax1 = f1.add_subplot(131)
plt.show()
