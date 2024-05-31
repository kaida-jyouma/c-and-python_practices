m, r = map(float, input().split())
coins = {20.0: [1.0, 1], 22.0: [3.75, 5], 23.5: [4.5, 10], 21.0: [4.0, 50], 22.6: [4.8, 100], 26.5: [7.1, 500]}
try:
	values = coins[r]
except:
	print(0)
else:
	if coins[r][0] == m:
		print(coins[r][1])
	else:
		print(0)
