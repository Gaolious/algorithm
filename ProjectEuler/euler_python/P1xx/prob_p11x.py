import itertools
from typing import List

from utils.help import combination, Prime


def P112():

    def F(n):
        t = []
        while n > 0:
            t.append(n % 10)
            n //= 10
        inc = False
        dec = False

        for i in range(1, len(t)):
            if t[i-1] < t[i]: inc = True
            if t[i-1] > t[i]: dec = True
            if inc and dec:
                return True

        return False

    n = 0
    cnt = 0

    while True:
        n += 1

        if F(n):
            cnt += 1

        if n * 0.99 <= cnt:
            return n

def P113():
    return combination(100+10,10) + combination(100+9, 9) - 10 * 100 - 2


def P114():
    """
    길이가 7인 칸에 빨간 블록들을 놓으려고 합니다.
    빨간 블록의 길이는 최소 3칸, 블록과 블록 사이는 최소 한 칸 이상 떨어져야 합니다
    (빨간 블록의 크기는 달라도 상관없습니다). 이런 경우, 블록을 놓는 방법은 모두 17가지가 있습니다.

    :return:
    """
    N = 50
    MinM = 3

    D = [0 for _ in range(N+1)]

    for block_size in range(MinM, N+1):
        D[block_size] = block_size - (MinM-1)

        for offset in range(MinM+2, block_size - (MinM-1) + 1):
            D[block_size] += D[block_size - offset + 1] * (offset - (MinM+1))

    return sum(D) + 1


def P115():

    N = 50000
    MinM = 50

    D = [0 for _ in range(N+1)]
    S = 0
    for block_size in range(MinM, N+1):
        D[block_size] = block_size - (MinM-1)

        for offset in range(MinM+2, block_size - (MinM-1) + 1):
            D[block_size] += D[block_size - offset + 1] * (offset - (MinM+1))

        S += D[block_size]

        if S + 1 >= 1_000_000:
            return block_size

def P116():
    def F(N, MinM):
        D = [0 for _ in range(N + 1)]

        for block_size in range(MinM, N + 1):
            D[block_size] = block_size - (MinM - 1)

            for offset in range(MinM + 1, block_size - (MinM - 1) + 1):
                D[block_size] += D[block_size - offset + 1]

        print(D)
        return D[-1]

    return F(50, 2) + F(50, 3) + F(50, 4)


def P117():
    a, b, c, d, n = 0, 0, 0, 1, 50
    for _ in range(n):
        a, b, c, d = b, c, d, (a + b + c + d)

    return d


def P118():
    """
        1 2 3 4 5 6 7 8 9
        1 3 7 9

    :return:
    """
    P = Prime(100000)
    P.sieve()

    def is_prime(n):
        if n < P.number[0]:
            return False

        for p in P.number:
            if p*p > n: return True
            if n % p == 0: return False

        while p*p <= n:
            p += 2
            if n % p == 0: return False

        return True

    def generate_prime(numbers, ndigit):
        for num in itertools.permutations(numbers, ndigit):
            p = 0
            for n in num:
                p = p * 10 + n

            if is_prime(p):
                yield p, set(num)

    def Find(nDigits, check, remain_cnt, tmp) -> int:

        ret = 0
        if remain_cnt == 0 :
            return 1

        for nRow in range(nDigits, 10):
            for prime, digit_set in generate_prime(set(range(1,10)) - check, nRow):
                if tmp and tmp[-1] > prime:
                    continue
                ret += Find(nRow, digit_set | check, remain_cnt - nRow, tmp + [prime])

        return ret

    check = set([])

    print(Find(1, check, 9, []))
