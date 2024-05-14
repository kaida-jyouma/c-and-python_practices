# geogebra => https://geogebra.org/classic/myywsnu4]

from math import sin, cos, asin

from math import degrees as deg
from math import radians as rad

import sympy as sp

# a = sp.Symbol("a")
a = 100

pd = (a * sin(rad(20))) / sin(rad(80))
ab = (a * sin(rad(80))) / sin(rad(50))

ae = (ab * sin(rad(30))) / sin(rad(70))

ce = ab - ae
bc = (ab * sin(rad(80))) / sin(rad(50))
dc = bc - a

de = sp.sqrt((dc ** 2 + ce ** 2) - 2 * dc * ce * cos(rad(50)))

print(de)

d = (pd * sin(rad(100))) / de

print(d)

x = deg(asin(d))

print(x)