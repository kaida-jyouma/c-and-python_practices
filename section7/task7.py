# task7

"""

# 7task3.py

def checkSign(ls):
	ct = 0
	for i in range(len(ls) - 1):
		for j in range(len(ls) - i - 1):
			if ls[i] > ls[i+j+1]:
				ct += 1
	if ct % 2 == 0:
		return 1
	else:
		return -1



for i in range(4):
	for j in range(4):
		for k in range(4):
			for l in range(4):
				if len(list(set([i, j, k, l]))) != 4:
					continue
				else:
					print(i+1, j+1, k+1, l+1, ",", checkSign([i, j, k, l]))

"""

# 7task4.py

from math import sqrt as sq

def v_s(n):
	if n == 0:
		return 2
	else:
		return sq(v_s(n - 1) * v_t(n - 1))

def v_t(n):
	if n == 0:
		return 4
	else:
		return (2 * (v_s(n) / v_t(n - 1))) / (1 + v_s(n) / v_t(n - 1)) * v_t(n - 1)

for i in range(13):
	print(v_s(i), v_t(i))

