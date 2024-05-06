def loc(a, b=None, c=None, degAB=None):
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
            b = sp.Symbol("b")
            fom = a**2 + b**2 - c**2 - 2*a*b * sp.cos(degAB)
            return sp.solve(fom, b) # need to check

        elif  degAB == None:
            fom = (a**2 + b**2 - c**2) / (2*a*b)
            return mt.degrees(sp.acos(fom))

