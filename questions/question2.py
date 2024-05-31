def a(n):
	return 3 * n - 2
k = 1
bn = 0
while True:
	bn += a(k)
	if (bn > 1000):
		print(k)
		break
	k += 1
