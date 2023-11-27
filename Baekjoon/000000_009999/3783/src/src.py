# -*- coding:utf-8 -*-
import decimal
import sys
from decimal import *
import math

getcontext().prec = 1000
E = Decimal('1.0e-9')
def process(fin):
    T = int(fin())
    p = Decimal('1.0') / Decimal('3.0')

    for _ in range(T):
        n = Decimal(fin().strip())
        t = round(Decimal(n ** p), 500)
        ans = Decimal(t).quantize(E, rounding=decimal.ROUND_DOWN)
        print(ans)

if __name__ == '__main__':
    process(sys.stdin.readline)
