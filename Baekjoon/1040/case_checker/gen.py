import random
import sys

def gen(*args):
    MaxN = 10**18
    MaxK = 10
    N = random.randint(1, MaxN)
    K = random.randint(1, MaxK)
    if args:
        K = (int(args[0]) % 10) + 1

    print(N, K)

if __name__ == '__main__':
    args = sys.argv

    del args[0]
    gen(*args)
