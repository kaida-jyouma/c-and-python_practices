x, y, z = [c for c in input().split()] # read number from console (format: n1 n2 n3)
print("xの型は", type(x))
print("yの型は", type(y))
print("zの型は", type(z))
x1, y1, z1 = [int(c) for c in [x, y, z]] # convert x,y,z to int
ans1 = x1 / y1 / z1 # update ans1 with x1/y1/z1
ans2 = x1 // y1 // z1 # update ans2 with x1//y1//z1
print("x1/y1/z1 =", ans1)
print("x1//y1//z1 =", ans2)
print("typeof 'x1/y1/z1' =", type(ans1)) # print type of 'ans1'
print("typeof 'x1//y1//z1 ='", type(ans2)) # print type of 'ans2'
