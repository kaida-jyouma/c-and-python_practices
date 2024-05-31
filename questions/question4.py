def f(n):
	from math import log
	return log((n + 1) * (n + 2) / (n * (n + 3)))

sn = 0

for i in range(10000):
	sn += f(i+1)

print(sn)
