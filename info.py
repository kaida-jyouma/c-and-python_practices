# q1
a = 1
b = 2

print(a + b)
print(a - b)
print(a * b)
try:
	print(a / b)
except:
	print(0)

# q2
print(sum([int(c) for c in range(1, 101)]))

# q3
print(" ".join([c for c in range(1, 101) if c % 3 == 0]))

#q4
print(" ".join([c for c in range(1, 101) if c % 4 == 0]))

#q5
print(" ".join([c for c in range(1, 101) if c % 12 == 0]))
