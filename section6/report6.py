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
	n = cat_nxt(n, m)
	m = rab_nxt(m, m, k)
	k = grs_nxt(m, k)
	if i % 10 == 0:
		print(" , ".join([str(n), str(m), str(k)]))
	if n < 0 or m < 0 or k < 0:
		print(" , ".join([str(n), str(m), str(k)]))
		print(i, "extinct break")
		break
