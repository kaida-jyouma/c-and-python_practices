# 5task3

def leibniz_pi(n):
    return sum([( (-1) ** (c - 1) ) / ( 2*c - 1 ) for c in range(1, n + 1)]) * 4

print(leibniz_pi(5))
print(leibniz_pi(20))
print(leibniz_pi(100))



# 5task41

import sys

n, m = map(int, input("input 2 number with space: ").split())

if sys.version_info.minor >= 9:
    from math import lcm
    print(lcm(n, m))

else:
    from math import gcd
    print(n * m / gcd(n, m))
