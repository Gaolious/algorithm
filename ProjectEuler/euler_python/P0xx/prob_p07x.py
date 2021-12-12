import math

from utils.help import *


def P70():
    N = 10**7

    P = Prime(10000)
    P.sieve()
    ret = 0
    min_phi = -1

    for i in range(0, len(P.number)):
        for j in range(i+1, len(P.number)):
            n = P.number[i] * P.number[j]
            if n >= N:
                break
            phi = ( P.number[i] - 1 ) * ( P.number[j] - 1)

            to_list_1 = number_to_list(n)
            to_list_2 = number_to_list(phi)

            if to_list_1 == to_list_2:
                if min_phi < 0 or n / phi < min_phi:
                    min_phi = n / phi
                    ret = n
                    print("found : n/phi:{}, n={}, phi={}".format(min_phi, n, phi))

    return ret

def P72():
    N = 1_000_000
    P = Prime(N)
    P.sieve()
    phi = [ i for i in range(N+1)]
    ret = 0

    for i in range(2, N+1):
        if phi[i] == i:
            for k in range(i, N+1, i):
                phi[k] = phi[k] * (i - 1) // i

        ret += phi[i]
    return ret

def P73():
    D = 12_000

    cnt = 0
    for d in range(3, D+1):
        l = d // 3
        r = d // 2

        while l * 3 <= d:
            l += 1
        while r * 2 >= d:
            r -= 1

        for i in range(l, r+1):
            m = gcd(i, d)
            if m != 1 : continue

            cnt += 1
        print("d={} / ans={}".format(d, cnt))

    return cnt



def P74():
    FactorialValue = [
        factorial(i) for i in range(0, 10)
    ]
    CACHE = {}

    def F(n: int):
        if n not in CACHE:
            t = n
            ret = 0
            while t > 0:
                ret += FactorialValue[t % 10]
                t //= 10

            CACHE.update({
                n: ret
            })

        return CACHE[n]

    def C(n: int):
        ret = set([])
        while n not in ret:
            ret.add(n)
            n = F(n)
        return len(ret)

    cnt = 0
    for i in range(1, 1_000_000+1):
        if C(i) == 60:
            cnt+=1

    return cnt

def P75():
    """
        a^2 + b^2 = c^2

    :return:
    """

    N = 1_500_000
    max_n = int(math.sqrt(N))
    cnt = [0] * (N+1)

    for m in range(2, max_n+1):
        for n in range(1, m):
            a = m*m - n*n
            b = 2*m*n
            c = m*m + n*n

            if gcd3(a, b, c) != 1:
                continue

            max_k = N // (a+b+c)
            for k in range(1, max_k+1):
                cnt[ (a+b+c) * k ] += 1

    ret = 0
    for v in cnt:
        if v == 1:
            ret += 1

    return ret


def P76():
    N = 100
    # memoization
    # D = [[-1 for _ in range(N+1)] for _ in range(N+1)]
    #
    # def F(a, b):
    #     if b == 1 or a == b:
    #         return 1
    #     elif a < b :
    #         return 0
    #     elif D[a][b] == -1:
    #         new_a = a - b
    #         new_b = min(new_a, b)
    #         ret = 0
    #         for i in range(1, new_b+1):
    #             ret += F(new_a, i)
    #         D[a][b] = ret
    #
    #     return D[a][b]

    D = [0] * (N+1)
    D[0] = 1

    for i in range(1, N):
        for j in range(i, N+1):
            D[j] += D[j - i]

    return D[N]


def P77():
    MaxN = 10_000
    P = Prime(MaxN)
    P.sieve()
    N = len(P.number)

    D = [0] * (MaxN+1)
    D[0] = 1

    check_idx = 0
    for idx in range(0, N):
        n = P.number[idx]

        for j in range(n, MaxN+1):
            D[j] += D[j - n]

        while check_idx < n :
            print("{} : {}".format(check_idx, D[check_idx]))
            if D[check_idx] > 5000:
                return check_idx
            check_idx += 1


def P78():
    D = {}
    """
        𝑝(𝑛)= sum [ (−1)^(𝑘+1) ( 𝑝( 𝑛−𝑘(3𝑘−1)/2 ) + 𝑝( 𝑛 − 𝑘 (3𝑘+1)/2))
        
        p(9) =  1 * [ p(n-1) + p(n-2) ]   // k=1
               -1 * [ p(n-5) + p(n-7) ]   // k=2
                1 * [ p(n-12) + p(n-15) ]   // k=3
    """
    CacheP = [-1] * 50_000
    M = 1_000_000

    def P(n):
        if n < 0:
            return 0
        if CacheP[n] == -1:
            k = 1
            new_p = 0
            while True:
                sign = 1
                if k % 2 == 0:
                    sign = -1

                g1 = k * (3 * k - 1) // 2
                g2 = k * (3 * k + 1) // 2
                if g1 > n and g2 > n:
                    break
                new_p += sign * (P(n-g1) + P(n-g2))

                k += 1
            CacheP[n] = new_p % M

        return CacheP[n]

    CacheP[0] = 1
    CacheP[1] = 1
    i = 1
    while True:
        if P(i) % M == 0:
            print("P({}) = {}".format(i, P(i)))
            return i
        i += 1


def P79():
    A = """
319
680
180
690
129
620
762
689
762
318
368
710
720
710
629
168
160
689
716
731
736
729
316
729
729
710
769
290
719
680
318
389
162
289
162
718
729
319
790
680
890
362
319
760
316
729
380
319
728
716
"""

    check = [True for _ in range(10)]

    F = {}
    B = {}
    for line in A.strip().split('\n'):
        a = int(line[0])
        b = int(line[1])
        c = int(line[2])
        check[a] = check[b] = check[c] = False

        F.setdefault(a, set([])).add(b)
        F.setdefault(b, set([])).add(c)

        B.setdefault(b, set([])).add(a)
        B.setdefault(c, set([])).add(b)

    # backward
    #  {'1': {'7', '3'}, '9': {'8', '2', '6', '7', '1'}, '8': {'6', '3', '2', '1'}, '0': {'8', '9', '2', '6', '1'}, '2': {'6', '7', '1'}, '6': {'7', '3', '1'}, '3': {'7'}}
    # forward
    #  {'3': {'6', '8', '1'}, '1': {'8', '9', '2', '6', '0'}, '6': {'8', '0', '2', '9'}, '8': {'0', '9'}, '9': {'0'}, '2': {'8', '9', '0'}, '7': {'3', '9', '2', '6', '1'}}


    ans = 0

    while B:
        min_key = -1
        for i in range(10):
            if check[i]: continue

            if min_key < 0 or len(B.get(i, [])) < len(B.get(min_key, [])):
                min_key = i

        if min_key >= 0:
            check[min_key] = True
            for i in range(10):
                B.setdefault(i, set([]))
                B[i] -= set([min_key])

            ans = ans * 10 + min_key
        else:
            break

    return ans

