

import numpy as np
import matplotlib.pyplot as plt

from scipy.special import erf

cdat = np.loadtxt('erf_data.txt')

x = np.linspace(-3, 3, 100)

plt.plot(x, erf(x), lw=2, label='scipy')
plt.plot(cdat[:,0], cdat[:,1] , lw=2, label='CSPL')
plt.legend(loc='upper left')






