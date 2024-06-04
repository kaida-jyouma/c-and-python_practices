# Basic
tryCount=10000
points = 10

def dice(n):
    from random import randint as rint
    pt = rint(0, 99)
    dl = [c + 1 for c in range(6)]
    n = dl.pop(n)
    if pt < 50:
        return n
    elif pt < 60:
        return dl[0]
    elif pt < 70:
        return dl[1]
    elif pt < 80:
        return dl[2]
    elif pt < 90:
        return dl[3]
    else:
        return dl[4]

total = 0
for i in range(tryCount):
    ct = 0
    while True:
        ct += 1
        points -= dice(1)
        if points < 0:
            points = abs(points)
        if points == 0:
            total += ct
            break
print(total / tryCount)



# Extra

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
