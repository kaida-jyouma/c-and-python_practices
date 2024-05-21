def keta2(n):
    m = 0
    while n>0:
        n = n // 2
        m += 1
    return m

def cubicrt(n):
    k = (keta2(n) - 1) // 3
    m = 2 ** k
    for i in range(0, k):
        if (m + 2 ** (k - 1 - i)) ** 3 <= n:
            m += 2 ** (k - 1 - i)
    return int(m)

def check_cubic(n):
    if cubicrt(n) ** 3 == n:
        return 1
    else:
        return 0

def check_cubic_sum(n):
    l = cubicrt(n // 2)
    times = 0
    j = 0
    for i in range(0, l + 1):
        if check_cubic(n - i ** 3) == 1:
            if times == 0:
                j = i
            times += 1
        
        if times == 2:
            break
    if times == 2:
        return 1
    else:
        return 0
    
i = 0
times = 0
while times <= 29:
    if check_cubic_sum(i) == 1:
        times += 1
        print(i)
    i += 1