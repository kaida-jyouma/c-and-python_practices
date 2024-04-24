# 3task3.py
rice = 1700
bread = 200
money = int(input())

if money >= rice:
    money -= rice
for i in range(4):
    if money >= bread:
        money -= bread
    else:
        break
print(money)