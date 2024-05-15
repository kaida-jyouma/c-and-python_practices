# play with terminal

# under construction......
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
        fl = ["x" if ri(0, 99) < 15 else "o" for c in range(col)]
        bnum += fl.count("x") # count bomb
        fld.append(fl)
    


    return 



