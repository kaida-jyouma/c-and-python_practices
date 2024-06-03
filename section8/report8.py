# calculate pi with Monte Carlo method
import math as mt
import random as rdm

# function return the distance of 2 points
def dist(x, y, ox=0, oy=0):
    return (((x - ox) ** 2) + ((y - oy) ** 2))

# the number of tries
pct = 10000000000

# the number of dots in the circle
dct = 0

# dot
for i in range(pct):
    ptx = rdm.random()
    pty = rdm.random()
    if dist(ptx, pty, 0, 0) <= 1:
        dct += 1
    if i % (pct / 50) == 0:
        print((dct / (i + 1)) * 4)


print()
print(pct)
print(dct)
print((dct / pct) * 4)
