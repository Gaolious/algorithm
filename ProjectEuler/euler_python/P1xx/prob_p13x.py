from utils.help import Prime


def modpow(n, p, m):
    if p <= 1:
        ret = n**p
    elif p % 2 == 0:
        ret = modpow(n, p//2, m) ** 2
    else:
        ret = modpow(n, p-1, m) * n
    return ret % m


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