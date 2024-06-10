def p(num, radix):
	if radix > 10:
		return num
	else:
		d = 1 # num's digit
		while True:
			if num % (10 ** d) == num:
				break
			d += 1
		n10 = 0
		for i in range(d):
			n10 += (num % (10 ** (i + 1))) * (radix ** i)
			num -= (num % (10 ** (i + 1)))
		print(d, n10)
		# under construction......

print(p(101, 2))
