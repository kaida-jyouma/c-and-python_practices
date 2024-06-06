# 8task21
# for python 3.10~
from statistics import covariance as cov, correlation as cor, mean, pvariance as pav
def tensuu_seisei(i,u1,u2,u3):
	from math import ceil, sin
	if((ceil(u1 * sin(u2 * i)) + 1) % 4 == 0):
		return 90 + ceil(10 * sin(u3 * i) ** 3)
	elif(ceil(u1 * sin(u2 * i)) % 2 == 0):
		return 80 + ceil(20 * sin(u3 * i) ** 3)
	else:
		return 70 + ceil(20 * sin(u3 * i) ** 5)

def tensuu_mat(i):
	return tensuu_seisei(i, 10000, 20000, 30000)
def tensuu_eng(i):
	return tensuu_seisei(i, 20000, 30000, 10000)
def tensuu_phy(i):
	return tensuu_seisei(i, 30000, 10000, 20000)
def tensuu_pro(i):
	return tensuu_seisei(i, 10000, 20000, 40000)

lmat = [tensuu_mat(c) for c in range(0o1, 0o145)]
leng = [tensuu_eng(c) for c in range(1, 0x65)]
lphy = [tensuu_phy(c) for c in range(0x1, 101)]
lpro = [tensuu_pro(c) for c in range(0b1, 0b1100101)]

print(lmat, len(lmat)) # debug
print(leng, len(leng)) # debug
print(lphy, len(lphy)) # debug
print(lpro, len(lpro)) # debug

print(mean(lmat), pav(lmat), len([c for c in lmat if c < 60]))
print(mean(leng), pav(leng), len([c for c in leng if c < 60]))
print(mean(lphy), pav(lphy), len([c for c in lphy if c < 60]))
print(mean(lpro), pav(lpro), len([c for c in lpro if c < 60]))

print(cov(lmat, leng))
print(cov(lmat, lphy))
print(cov(lmat, lpro))
print(cov(leng, lphy))
print(cov(leng, lpro))
print(cov(lphy, lpro))

import numpy as np
import matplotlib.pyplot as plt

# mt and en
plt.scatter(lmat, leng, color="lawngreen", marker=".")
plt.show()

# mt and pro
plt.scatter(lmat, lpro, color="deepskyblue", marker=",")
plt.show()

# draw pie chart
dataList = [
	[c for c in lphy if c < 60],
	[c for c in lphy if c >= 60 and c < 70],
	[c for c in lphy if c >= 70 and c < 80],
	[c for c in lphy if c >= 80 and c < 90],
	[c for c in lphy if c >= 90]
]
labels = [chr(c) for c in [70, 67, 66, 65, 83]]
plt.pie([len(c) for c in dataList], labels=labels)
plt.show()

# 8task22

# Sieve of Eratosthenes
def raiseprimes(mxm):
    from math import sqrt, floor
    sq_f = floor(sqrt(mxm))
    nonprimes = [[c for c in range(2, mxm + 1) if c % d == 0][1:] for d in range(2, sq_f + 1)]
    primes = sorted(list(set(range(2, mxm + 1)) - set(sum(nonprimes, []))))
    return primes

print(raiseprimes(10000))
# print(len(raiseprimes(10000))) # debug
print([c for n, c in enumerate(raiseprimes(10000)) if n % 111 == 110])
print()

# 8task31

# Under Construction...... (error?) => done
from numpy import array as arr
n, m, k = [750, 3500, 1000]
fields = arr([[n], [m], [k]])
for i in range(360):
	fields = fields - ((1/100) * arr([[-4, 4, 0], [-6, 3, 3], [0, -1, 1]])) @ arr([[fields[0, 0] - 1000], [fields[1, 0] - 3000], [fields[2, 0]]])
	plt.plot(i + 1, fields[0, 0], color="lawngreen", marker=",")
	plt.plot(i + 1, fields[1, 0], color="deepskyblue", marker=",")
	plt.plot(i + 1, fields[2, 0], color="darkorange", marker=",")

plt.grid()
plt.xlabel("days")
plt.ylabel("numbers")
plt.legend()
plt.show()

# 8task32

from random import randint as rint
tryCount = 100000

# Unchange
hitU = 0
for i in range(tryCount):
	ans = rint(1, 4)
	first = rint(1, 4)
	
	if ans == first:
		hitU += 1

print(hitU/tryCount)

# Change
hitC = 0
for i in range(tryCount):
	ans = rint(1, 4)
	first = rint(1, 4)
	
	# other = [c for c in [1, 2, 3, 4] if c != ans and c != first]
	# fail = other[rint(0, len(other) - 1)]
	
	# secondls = [c for c in [1, 2, 3, 4] if c != first and c != fail]
	# second = secondls[rint(0, len(secondls) - 1)]
	
	# if ans == second:
	# 	hitC += 1

	if ans != first:
		hitC += 1 # change -> win

print(hitC/tryCount)
