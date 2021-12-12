import math
from typing import Tuple, Set

from utils.help import Prime


def P122():
    N = 200
    sol = [10*10] * ( N + 1)

    def find(*data, s):
        if s > N or sol[s] < len(data):
            return

        sol[s] = len(data)

        for n in reversed(data):
            find(*data, s+n, s=s+n)

    find(s=1)

    sol[0] = sol[1] = 0
    return sum(sol)


def P123():
    P = Prime(500000)
    P.sieve()

    limit = 1

    for i in range(0, len(P.number), 2):
        if P.number[i] * P.number[i] < 10 ** 10: continue
        if ( i + 1 ) * P.number[i] < 5000000000: continue

        # n = (P.number[i] - 1) ** (i + 1) + (P.number[i] + 1) ** (i + 1)
        # n %= P.number[i] ** 2
        return i + 1


def P124():
    N = 100_000
    A = [1] * (N+1)

    for i in range(2, N+1):
        if A[i] != 1:
            continue

        k = 2
        A[i] = i
        while k * i <= N:
            A[k * i] *= i
            k += 1

    ret = []
    for i in range(1, N+1):
        ret.append((A[i], i))

    ret = sorted(ret)

    return ret[10000 - 1]


def min_index(S, num, l, r):
    l = 1
    r = len(S) - 1
    while l < r:
        m = (l + r) // 2
        s = S[m] - S[l - 1]
        if s > num:
            r = m - 1
        else:
            return m
    return -1


def P125():
    def pal(num):
        a = list(str(num))
        b = list(str(num))
        a.reverse()
        if b == a:
            return True
        return False

    pal_list = []

    for i in range(100000000):
        if pal(i) == True:
            pal_list.append(i)

    def square_sum(num):
        temp_list = []
        real_list = []
        tmp = 0
        for i in range(num + 1):
            tmp += i ** 2
            temp_list.append(tmp)
        for i in range(num):
            for j in range(i - 1):
                real_list.append(temp_list[i] - temp_list[j])
        return real_list

    a = set(square_sum(10001))
    b = set(pal_list)
    c = a.intersection(b)

    print(sum(c))


def P126():
    def Count(x, y, z, d):
        return 2 * (x * y + y * z + x * z) + 4 * (x + y + z + d - 2) * (d - 1)

    limit = 20000
    C = [0] * ( limit + 1 )

    for x in range(1, limit):
        if Count(x, x, x, 1) > limit:
            break

        for y in range(x, limit):
            if Count(x, y, x, 1) > limit:
                break
            for z in range(y, limit):
                if Count(x, y, z, 1) > limit:
                    break

                for d in range(1, limit):
                    cnt = Count(x, y, z, d)
                    if cnt > limit:
                        break
                    C[cnt] += 1

    for i in range(len(C)):
        print(i, C[i])
        if C[i] == 1000:
            return i