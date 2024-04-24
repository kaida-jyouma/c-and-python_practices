# 3task3.py
rice = 1700 # define rice's price
bread = 200 # define bread's price
money = int(input()) # receive money

if money >= rice: # if we can buy rice
    money -= rice # buy one

for i in range(4): # bread_max: 4pcs
    if money >= bread: # if we can buy bread
        money -= bread # buy bread
    else: # if we cannot buy bread
        break # stop purchase

print(money)
