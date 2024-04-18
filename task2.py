# task2-1
print("".join([chr(c) for c in [22909, 12365, 12394, 39135, 12409, 29289, 12399, 34126, 40614, 12391, 12377, 12290, 10, 22909, 12365, 12394, 25945,31185, 12399, 24773, 22577, 12391, 12377, 12290, 10, 10, 10, 12424, 12429, 12375, 12367, 12362, 39000, 12356, 12375, 12414, 12377, 12290]]))

# task2-2
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
