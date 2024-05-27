import numpy as np
import matplotlib.pyplot as plt

dx = 10000
x = np.arange(-10, 10, 1 / dx)

y = np.cos(x)

plt.plot(x, y, color="lawngreen", label="y=cos(x)")
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.legend()
plt.show()
