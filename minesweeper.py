# play with terminal

# under construction......
def detect_mine(x, y, fld, rowmax, colmax, mine="o", grd="x"):
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
        bnum += fl.count("x") # count bomb
        fld.append(fl) 

    return {"bnum": bnum, "fld": fld}

def game():

    fld_row = 14
    fld_col = 18

    fld = makefield(fld_row, fld_col)["fld"]
    
