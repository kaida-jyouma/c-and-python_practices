def leibniz_pi(n):
    return sum([( (-1) ** (c - 1) ) / ( 2*c - 1 ) for c in range(1, n + 1)]) * 4

print(leibniz_pi(5))
print(leibniz_pi(20))
print(leibniz_pi(100))