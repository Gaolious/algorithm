import math

a2, a1, a0, c, n0 = map(int, open(0).read().split() )
def F(x):
    return a2*x*x + a1*x + a0
def G(x):
    return c*x*x

ret = True
A = [n0, ]
d = a1*a1 - 4 * (a2-c) * a0
if d >= 0 and a2-c != 0:
    l = max(n0, (-a1 + math.sqrt(d) ) / (2 * (a2-c) ) )
    r = max(n0, (-a1 - math.sqrt(d) ) / (2 * (a2-c) ) )
    A += [ (l+r)/2, l+1, r+1, l, r ]

for x in A:
    ret = ret and F( max(n0,x) ) <= G( max(n0, x) )

print( 1 if ret else 0 )
