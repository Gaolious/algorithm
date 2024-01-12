# -*- coding:utf-8 -*-
import sys
from decimal import Decimal as D, getcontext

getcontext().prec = 100
EPSILON = D('1.0') ** D('-40')

d0 = D('0')
d2 = D('2')
d3 = D('3')
d4 = D('4')
z = D('0.000000000001')

def value(d: D):
    return round(d, 25)

def is_zero(d: D):
    return -z < d < z

class F:
    a: D
    b: D
    c: D
    d: D
    def __init__(self, a, b, c, d) -> None:
        self.a, self.b, self.c, self.d = a, b, c, d
    
    def val(self, x: D) ->D:
        return self.a * x**3 + self.b * x**2 + self.c * x + self.d

    def bsearch(self, left: D, right: D):
        l, r = left, right 
        while ( r - l >= EPSILON ):
            m = (l+r) / d2 
            if self.val(l) * self.val(m) > 0:
                l = m
            else:
                r = m
        return l
    
def process(fin):
    n = int(fin().strip())
    LEFT, RIGHT = D('-10000000'), D('10000000')

    for _ in range(n):
        a, b, c, d = map(D, fin().strip().split())
        f = F(a,b,c,d)
        
        t = b**2 - 3*a*c 
        ranges = [
            LEFT, RIGHT
        ]
        if t >= 0:
            ranges += [(-b - t.sqrt())/(3*a), (-b + t.sqrt())/(3*a)]
        
        ranges = sorted(ranges)
        sol = []
        for i in range(1, len(ranges)):
            l, r = ranges[i-1], ranges[i]
            for _ in range(500):
                m = (l+r)
                if f.val(m) * f.val(l) > 0:
                    l = m
                else:
                    r = m
            if is_zero(f.val(l)):
                sol.append(l)

        ret = sorted([f'{v:.10f}' for v in sol], key=lambda k:D(k))

        print(*ret)

if __name__ == '__main__':
    process(sys.stdin.readline)
