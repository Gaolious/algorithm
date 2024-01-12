from utils.help import Prime


def P365():
    P = Prime(5000)
    P.sieve()

    # (10^18) C (10^9) % ( p1 * p2 * p3 )

    primes = [ i for i in P.number if 1000 < i < 5000 ]
    print(primes)
    print(len(primes))