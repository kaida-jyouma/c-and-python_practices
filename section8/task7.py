# 8task21
# for python 3.10~
from statistics import covariance as cov, correlation as cor, mean, pvariance as pav
def tensuu_seisei(i,u1,u2,u3):
	from math import ceil, sin
	if((ceil(u1 * sin(u2 * i)) + 1) % 4 == 0):
		return 90 + ceil(10 * sin(u3 * i) ** 3)
	elif(ceil(u1 * sin(u2 * i)) % 2 == 0):
		return 80 + ceil(20 * sin(u3 * i) ** 3)
	else:
		return 70 + ceil(20 * sin(u3 * i) ** 5)

def tensuu_mat(i):
	return tensuu_seisei(i, 10000, 20000, 30000)
def tensuu_eng(i):
	return tensuu_seisei(i, 20000, 30000, 10000)
def tensuu_phy(i):
	return tensuu_seisei(i, 30000, 10000, 20000)
def tensuu_pro(i):
	return tensuu_seisei(i, 10000, 20000, 40000)



lmat = [tensuu_mat(c) for c in range(0o1, 0o145)]
leng = [tensuu_eng(c) for c in range(1, 0x65)]
lphy = [tensuu_phy(c) for c in range(0x1, 101)]
lpro = [tensuu_pro(c) for c in range(0b1, 0b1100101)]

print(lmat, len(lmat)) # debug
print(leng, len(leng)) # debug
print(lphy, len(lphy)) # debug
print(lpro, len(lpro)) # debug

print(mean(lmat), pav(lmat), len([c for c in lmat if c < 60]))
print(mean(leng), pav(leng), len([c for c in leng if c < 60]))
print(mean(lphy), pav(lphy), len([c for c in lphy if c < 60]))
print(mean(lpro), pav(lpro), len([c for c in lpro if c < 60]))

print(cov(lmat, leng))
print(cov(lmat, lphy))
print(cov(lmat, lpro))
print(cov(leng, lphy))
print(cov(leng, lpro))
print(cov(lphy, lpro))


# 8task22

# Sieve of Eratosthenes
def raiseprimes(mxm):
    from math import sqrt, floor
    sq_f = floor(sqrt(mxm))
    nonprimes = [[c for c in range(2, mxm + 1) if c % d == 0][1:] for d in range(2, sq_f + 1)]
    primes = sorted(list(set(range(2, mxm + 1)) - set(sum(nonprimes, []))))
    return primes

print(raiseprimes(10000))
# print(len(raiseprimes(10000))) # debug
print([c for n, c in enumerate(raiseprimes(10000)) if n % 111 == 1 and n > 111])
