# play on terminal

# under construction......
def detect_mine(x, y, fld, rowmax, colmax, mine="o", grd="x"):
	# row = x, col = y
	
	# get situation around target cell
	
	# top side
	if x == 0:
		if y == 0:
			nearby = [fld[0][1], fld[1][0], fld[1][1]]
		elif y == colmax - 1:
			nearby = [fld[0][-2], fld[1][-2], fld[1][-1]]
		else:
			nearby = [fld[0][y-1], fld[0][y+1], fld[1][y-1], fld[1][y], fld[1][y+1]]

	# bottom side
	elif x == rowmax - 1:
		if y == 0:
			nearby = [fld[-2][0], fld[-2][1], fld[-1][1]]
		elif y == colmax - 1:
			nearby = [fld[-2][-2], fld[-2][-1], fld[-1][-2]]
		else:
			nearby = [fld[-2][y-1], fld[-2][y], fld[-2][y+1], fld[-1][y-1], fld[-1][y+1]]

	# other
	else:
		if y == 0:
			nearby = [fld[x-1][y], fld[x-1][y+1], fld[x][y+1], fld[x+1][y], fld[x+1][y+1]]
		elif y == colmax - 1:
			nearby = [fld[x-1][y-1], fld[x-1][y], fld[x][y-1], fld[x+1][y-1], fld[x+1][y]]
		else:
			nearby = [fld[x-1][y-1], fld[x-1][y], fld[x-1][y+1], fld[x][y-1], fld[x][y+1], fld[x+1][y-1], fld[x+1][y], fld[x+1][y+1]]


	# judge bomb number around target cell
	if fld[x][y] == mine:
		return mine
	
	elif fld[x][y] == grd:
		density = nearby.count(mine)
		return density


def makefield(row, col):
    from math import floor
    from random import randint as ri
    
    # define filed size
    sq = row * col
    
    fld = []
    
    # bomb counter
    bnum = 0

    # make field and set bomb ratio as 15%
    for i in range(row):
        fl = ["o" if ri(0, 99) < 15 else "x" for c in range(col)]
        bnum += fl.count("o") # count bomb
        fld.append(fl) 

    return {"bnum": bnum, "fld": fld}


def dig(x, y, field, cover, mine="o", grd="x"):
	# row = x, col = y (start: 0 => n)
	# cover(arr) => change (return)
	# field(arr) => not change

	if field[x][y] == mine:
		# gameover
		return field

	# elif field[x][y] == grd:
		# dig around -> throw away

		"""
		# leftside
		for i in range(y):
			tgt_cell = field[x][y-1-i]
			cover[x][y-1-i] = tgt_cell
			
			if tgt_cell != grd:
				break
		
		# rightside
		for i in range(y):
			tgt_cell = field[x][y+1+i]
			cover[x][y+1+i] = tgt_cell

			if tgt_cell != grd:
				break

		"""


	else:
		# dig only target cell
		cover[x][y] = field[x][y]
		return cover


def game():

	# define field size
    fld_row = 14
    fld_col = 18

	# create field(base)
    fld_data = makefield(fld_row, fld_col)
    fld_b = fld_data["fld"]
    bnum = fld_data["bnum"]
    
    # create coverfield
	plyfld = [["v" for c in range(fld_col)] for d in range(fld_row)]

	# create playfield
    fld = [["x" for c in range(fld_col)] for d in range(fld_row)]
    
	# set flag (number)
    for i in range(fld_row):
        for j in range(fld_col):
            val = detect_mine(i, j)
			fld[i][j] = val
	
