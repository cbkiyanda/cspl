#!/usr/bin/env python

import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt('goog_cdf.csv')

fig = plt.figure()
ax = fig.add_subplot(111)
ax.plot(sorted(data[:,0]), data[:,1], lw=3, c='k')
ax.set_xlim((400, 650))
ax.fill_between(sorted(data[:,0]), data[:,4], data[:,5],
                color='r', alpha=0.4, label='99% confidence')
# fill_between doesn't label
p = plt.Rectangle((0, 0), 0, 0, color='r', alpha=0.4, label='99% confidence')
ax.add_patch(p)
ax.fill_between(sorted(data[:,0]), data[:,2], data[:,3],
                color='b', alpha=0.4, label='67% confidence')
p = plt.Rectangle((0, 0), 0, 0, color='b', alpha=0.4, label='67% confidence')
ax.add_patch(p)
ax.set_xlabel("GOOG closing price")
ax.set_ylabel("CDF")
ax.legend(loc='upper left')







