x, y, z = [c for c in input().split()] # 半角スペース区切りで入力を受け取る
print("xの型は", type(x))
print("yの型は", type(y))
print("zの型は", type(z))
x1, y1, z1 = [int(c) for c in [x, y, z]] # x, y, zをintに型変換
ans1 = x1 / y1 / z1 # x1/y1/z1を変数ans1に格納
ans2 = x1 // y1 // z1 # x1//y1//z1を変数ans2に格納
print("x1/y1/z1 =", ans1)
print("x1//y1//z1 =", ans2)
print("typeof 'x1/y1/z1' =", type(ans1)) # ans1の型を表示
print("typeof 'x1//y1//z1 ='", type(ans2)) # ans2の型を表示
