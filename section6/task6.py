def cat_tomorrow(n, m):
    return n - (15/100)*n + (5/100)*m

def rab_tomorrow(n, m):
    return m - (3/100)*n + (1/100)*m

def cat_10days(n, m):
    for i in range(10):
        n1 = cat_tomorrow(n, m)
        m1 = rab_tomorrow(n, m)
        n = n1
        m = m1
    
    return n

def rab_10days(n, m):
    for i in range(10):
        n1 = cat_tomorrow(n, m)
        m1 = rab_tomorrow(n, m)
        n = n1
        m = m1
    return m

print("decide the number of rabbit and cat...")
n = int(input("how many cat: "))
m = int(input("how many rabbit: "))

print("day_num / cat_num / rab_num")

for i in range(1, 36):
    n1 = cat_10days(n, m)
    m1 = rab_10days(n, m)
    print(i, "days, ", int(n1), "/", int(m1))
    n = n1
    m = m1