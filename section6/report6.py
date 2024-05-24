# decreasing model
def cat_nxt(n, m):
	return n - 0.04*(n - 1000) + 0.04*(m - 3000)

def rab_nxt(n, m, k):
	return m - 0.06*(n - 1000) + 0.03*(m - 3000) + 0.03 * k

def grs_nxt(m, k):
	return k - 0.01*(m - 3000) + 0.01 * k

n, m, k = map(int, input().split())

print(n, m, k)
for i in range(1, 361):
	n1 = cat_nxt(n, m)
	m1 = rab_nxt(m, m, k)
	k1 = grs_nxt(m, k)
	if i % 10 == 0:
		print(" , ".join([str(n1), str(m1), str(k1)]))
	if n < 0 or m < 0 or k < 0:
		print(" , ".join([str(n1), str(m1), str(k1)]))
		print(i, "extinct break")
		break
	n = n1
	m = m1
	k = k1
