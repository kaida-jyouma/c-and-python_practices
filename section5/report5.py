# Basic

c = 1
def leibniz_pi(n):
    return sum([( (-1) ** (c - 1) ) / ( 2*c - 1 ) for c in range(1, n + 1)]) * 4
while True:
    n = leibniz_pi(c)
    if n > 3.141 and n < 3.142:
        print(c)
        break
    else:
        c += 1


# extra

# 01: detect now time (1/100sec)

from time import time
ct = 0
while True:
    dt = input("detect now time (input 2-digit number): ")
    t = str(time()).split(".")[1][:2]
    if dt == t or ct > 10:
        print("Success!")
        break
    else:
        ct += 1