# play with terminal

# now construction......
def makefield(row, col):
    from math import floor
    from random import randint as ri
    
    # define filed size
    sq = row * col
    
    # make field and set bomb ratio as 15%
    fld = [["x" if ri(0, 99) < 15 else "o" for c in range(col)] for d in range(row)]
