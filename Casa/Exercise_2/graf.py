import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

x, h, forward, central, exact, ferr, cerr, rferr, rcerr = np.loadtxt("derivatives.txt", unpack=True,skiprows=1)

fig, ax = plt.subplots()
ax.plot(h, ferr, '-o', label='error forward')
ax.plot(h, cerr, '-s', label='error central')
ax.plot(h, rferr, '-*', label='error richardson forward')
ax.plot(h, rcerr, '-*', label='error richardson central')
ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('$h$')
ax.set_ylabel('error')
ax.legend()
fig.savefig('deriv.pdf')