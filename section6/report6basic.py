#Model of cats, rabbits, grasses
#絶滅しない程でお願いします
#見たかんじ全てどの値も振動してました

#次の日の猫の数
def cat_tomorrow(n,m,k):
	return n-(4/100)*(n-1000)+(4/100)*(m-3000)

#次の日の兎の数	
def rabbit_tomorrow(n,m,k):
	return m-(6/100)*(n-1000)+(3/100)*(m-3000)+(3/100)*k
	
#次の日の兎が食べる草の面積
def kusa_tomorrow(n,m,k):
	return k-(1/100)*(m-3000)+(1/100)*k

#10日後の猫の数
def cat_10days(n,m,k):
	for i in range(10):
		n1=cat_tomorrow(n,m,k)
		m1=rabbit_tomorrow(n,m,k)
		k1=kusa_tomorrow(n,m,k)
		n=n1
		m=m1
		k=k1
	return n
	
#10日後の兎の数
def rabbit_10days(n,m,k):
	for i in range(10):
		n1=cat_tomorrow(n,m,k)
		m1=rabbit_tomorrow(n,m,k)
		k1=kusa_tomorrow(n,m,k)
		n=n1
		m=m1
		k=k1
	return m

#10日後の草の面積
def kusa_10days(n,m,k):
    for i in range(10):
        n1=cat_tomorrow(n,m,k)
        m1=rabbit_tomorrow(n,m,k)
        k1=kusa_tomorrow(n,m,k)
        n=n1
        m=m1
        k=k1
    return k

#猫n匹、兎m羽、草k平方メートル

n=int(input("Number of cats "))
m=int(input("Number of rabbits "))
k=int(input("Area of grass "))


"""

#10日ごとの猫、兎の数、草の面積（360日まで）
for i in range(1,37):
    n1=cat_10days(n,m,k)
    m1=rabbit_10days(n,m,k)
    k1=kusa_10days(n,m,k)
    print("{}0 {} {} {}". format(i, int(n1), int(m1), int(k1)))
    n=n1
    m=m1
    k=k1

"""

print(n, m, k)
for i in range(1, 11):
    n = cat_tomorrow(n,m,k)
    m = rabbit_tomorrow(n,m,k)
    k = kusa_tomorrow(n,m,k)
    if i % 1 == 0:
        print(" , ".join([str(n), str(m), str(k)]))
    
    
