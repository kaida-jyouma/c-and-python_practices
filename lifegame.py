import random as rdm

# make life game

def update_cell(x, y, fld, rowmax, colmax, lv=1, dd=0):
	# row = x, col = y
	
	# get situation around target cell
	if x == 0:
		if y == 0:
			nearby = [fld[0][1], fld[1][0], fld[1][1]]
		elif y == colmax - 1:
			nearby = [fld[0][-2], fld[1][-2], fld[1][-1]]
		else:
			nearby = [fld[0][y-1], fld[0][y+1], fld[1][y-1], fld[1][y], fld[1][y+1]]

	elif x == rowmax - 1:
		if y == 0:
			nearby = [fld[-2][0], fld[-2][1], fld[-1][1]]
		elif y == colmax - 1:
			nearby = [fld[-2][-2], fld[-2][-1], fld[-1][-2]]
		else:
			nearby = [fld[-2][y-1], fld[-2][y], fld[-2][y+1], fld[-1][y-1], fld[-1][y+1]]

	else:
		if y == 0:
			nearby = [fld[x-1][y], fld[x-1][y+1], fld[x][y+1], fld[x+1][y], fld[x+1][y+1]]
		elif y == colmax - 1:
			nearby = [fld[x-1][y-1], fld[x-1][y], fld[x][y-1], fld[x+1][y-1], fld[x+1][y]]
		else:
			nearby = [fld[x-1][y-1], fld[x-1][y], fld[x-1][y+1], fld[x][y-1], fld[x][y+1], fld[x+1][y-1], fld[x+1][y], fld[x+1][y+1]]


	# judge next generation
	if fld[x][y] == lv:
		density = nearby.count(lv)
		if density > 3:
			# overcrowding
			return dd

		elif density < 2:
			# depopulation
			return dd
		
		else:
			# other (still live)
			return lv
	
	elif fld[x][y] == dd:
		density = nearby.count(lv)
		if density == 3:
			# born
			return lv

		else:
			# other (still dead)
			return dd



# field = 10 x 10
field = [[rdm.randint(0, 1) for c in range(10)] for d in range(10)]

# generatioins: 100
for g in range(100):
	print("\n".join(list(map(str, field))))
	print()
	next_gen = [[0 for c in range(10)] for d in range(10)]
	for i in range(len(field)):
		for j in range(len(field[i])):
			next_gen[i][j] = update_cell(i, j, field, 10, 10, 1, 0)
	field = next_gen
	
