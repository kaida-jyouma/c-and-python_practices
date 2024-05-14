from math import sin, cos, pi

from math import degrees as deg
from math import radians as rad

# def convert_d_r(n):
#     return n * (1/360) * 2 * pi

# def convert_r_d(theta):
#     return theta * (1/(2 * pi)) * 360
    
    
AB = 1

def koushiki_seigen1(a, C, A):
    return (a*sin(C))/sin(A)
    
BD = koushiki_seigen1(AB, rad(50), rad(80))
BE = koushiki_seigen1(AB, rad(80), rad(70))
AD = koushiki_seigen1(AB, rad(50), rad(80))
AP = koushiki_seigen1(AB, rad(30), rad(100))

PD = AD - AP

EPD = 100 # degree

def koushiki_yogen1(a, c, B):
    return (a**2+c**2-2*a*c*cos(B))**(1/2)
    
DE = koushiki_yogen1(BD, BE, rad(20))

def koushiki_seigen2(a, c, C):
    return (a/c)*sin(C)
    
BED = deg(koushiki_seigen2(PD, DE, rad(EPD)))

print(BED)
