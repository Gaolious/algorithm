from utils.help import Prime


def modpow(n, p, m):
    if p <= 1:
        ret = n**p
    elif p % 2 == 0:
        ret = modpow(n, p//2, m) ** 2
    else:
        ret = modpow(n, p-1, m) * n
    return ret % m


def P130():
    MaxN = 200_000
    P = Prime(MaxN)
    P.sieve()

    def An(n):
        k = 1
        L = 1
        while k % n != 0 and L < n:
            k = k * 10 + 1
            L += 1
        return L if k % n == 0 else 0

    cnt = 0
    S = 0
    for n in range(3, MaxN+1):
        if n % 2 == 0 or n % 10 == 0: continue
        if not P._is_set(n): continue

        k = An(n)
        if not k: continue

        k = An(n)

        if (n-1) % k == 0:
            cnt += 1
            S += n
            print(f'{cnt} : {n} / {S}')
            if cnt == 25:
                return S


def P132():
    P = Prime(200000)
    P.sieve()
    t = 0
    ret = 0
    for p in P.number:
        if modpow(10, 10**9, 9*p) == 1:
            print(p)
            t += 1
            if t <= 40:
                ret += p
            else:
                return ret

def P133():
    P = Prime(100000)
    P.sieve()

    S = 0
    for p in P.number:
        if modpow(10, 10**19, 9*p) != 1:
            print(p)
            S += p
    return S


def P134():
    P = Prime(100000)
    P.sieve()

    S = 0
    for p in P.number:
        if modpow(10, 10**19, 9*p) != 1:
            print(p)
            S += p
    return S