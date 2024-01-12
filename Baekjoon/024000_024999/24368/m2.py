import math

a2, a1, a0, c1, c2, n0 = map(int, open(0).read().split() )
def F(x):
    return a2*x*x + a1*x + a0
def G(x, c):
    return c*x*x

def E(a,b,c):
    d = b*b - 4*a*c
    ret = []
    if d >= 0 and a != 0:
        l = (-b - math.sqrt(d) ) / (2*a)
        r = (-b + math.sqrt(d) ) / (2*a)
        ret += [(l+r)/2, l+1, r+1, l, r ]
    return ret

ret = True
A = [n0, 10000 ]
A += E(a2-c1, a1, a0)
A += E(a2-c2, a1, a0)

for x in A:
    x = max(n0, x)
    ret = ret and G(x, c1) <= F(x) <= G(x,c2)

print( 1 if ret else 0 )
