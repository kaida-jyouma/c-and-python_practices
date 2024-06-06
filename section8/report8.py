# Basic

# experiment
tryCount=10000000
points = 10

def dice(n):
    from random import randint as rint
    pt = rint(0, 99)
    dl = [c + 1 for c in range(6)]
    n = dl.pop(n)
    if pt < 50:
        return n
    elif pt < 60:
        return dl[0]
    elif pt < 70:
        return dl[1]
    elif pt < 80:
        return dl[2]
    elif pt < 90:
        return dl[3]
    else:
        return dl[4]

total = 0
for i in range(tryCount):
    ct = 0
    while True:
        ct += 1
        points -= dice(1)
        if points < 0:
            points = abs(points)
        if points == 0:
            total += ct
            break
print(total / tryCount)


# Drawing graph

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os

savefig_dir = "/ ~ path-to-folder ~ "
sns.set_theme()
for i in range(6):
    fig, ax = plt.subplots(figsize = (10,5))
    # needed preparation: convert data to csv file
    # file name format: "report8-{A~F}.csv"
    df = pd.read_csv('/ ~ path-to-csv-file ~ /report8-' + chr(65 + i) + '.csv')
    dice = "Dice " + chr(65 + i)
    datasize = max(df[dice]) - min(df[dice])
    colorList = ["lightcoral", "darkorange", "gold", "limegreen", "darkturquoise", "royalblue", "mediumorchid", "hotpink"]
    sns.barplot(data=df, x='Map', y=dice, label=dice, color=colorList[i])
    ax.set(xlabel ='Map', ylabel='ClearTime', ylim=(min(df[dice]) - datasize / 2, max(df[dice]) + datasize / 2))
    # ax.grid()
    ax.legend()
    plt.savefig(os.path.join(savefig_dir, "dice" + str(i + 1) + ".png"))
    plt.show()


# Extra

# calculate pi with Monte Carlo method
import math as mt
import random as rdm

# function return the distance of 2 points
def dist(x, y, ox=0, oy=0):
    return (((x - ox) ** 2) + ((y - oy) ** 2))

# the number of tries
pct = 10000000000

# the number of dots in the circle
dct = 0

# dot
for i in range(pct):
    ptx = rdm.random()
    pty = rdm.random()
    if dist(ptx, pty, 0, 0) <= 1:
        dct += 1
    if i % (pct / 50) == 0:
        print((dct / (i + 1)) * 4)


print()
print(pct)
print(dct)
print((dct / pct) * 4)
