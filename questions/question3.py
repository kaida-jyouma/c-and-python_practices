def f(x, n):
	return x ** (-1 + (1 / n))

from numpy import e
import numpy as np

dx = (e - 1) / 50000
l = np.arange(1, e-1+dx, dx)
n = e

s = 0
for i in l:
	s += dx * f(i, n)
print(s)
