# geogebra => https://geogebra.org/classic/myywsnu4]

from math import sin, cos, asin

from math import degrees as deg
from math import radians as rad

import sympy as sp

def loc(a, b=None, c=None, degAB=None):
    # you have to install sympy before...
    import sympy as sp
    import math as mt
    if [a, b, c, degAB].count(None) > 1:
        return -1

    else:
        if c == None:
            # deg => rad
            degAB = mt.radians(degAB)

            # calculate
            sq = a**2 + b**2 - 2*a*b * sp.cos(degAB)

            return mt.sqrt(sq)

        elif b == None:
            # deg => rad
            degAB = mt.radians(degAB)

            # calculate
            b = sp.Symbol("b") # replace b(None) to symbol "b"(char)
            fom = a**2 + b**2 - c**2 - 2*a*b * sp.cos(degAB)
            return sp.solve(fom, b) # need to check -> ok

        elif  degAB == None:
            fom = (a**2 + b**2 - c**2) / (2*a*b)
            return mt.degrees(sp.acos(fom))
        
        else:
            # maybe unnecessary... -> necessary !
            return -2
            
def los(a=None, degA=None, r_2r=None):
    from math import sin, asin, radians
    if [a, degA, r_2r].count(None) > 1:
        return -1
        
    else:
        if r_2r == None:
            return a / sin(radians(degA))

        elif degA == None:
            return asin(a / r_2r)

        elif a == None:
            return r_2r * sin(radians(degA))

        else:
            return -2

a = sp.Symbol("a")

pd = (a * sin(rad(20))) / sin(rad(80))
ab = (a * sin(rad(80))) / sin(rad(50))

ae = (ab * sin(rad(30))) / sin(rad(70))

ce = ab - ae
bc = (ab * sin(rad(80))) / sin(rad(50))
dc = bc - a

de = loc(dc, ce, degAB=50)

x = asin((pd * sin(rad(100))) / de)

print(x)