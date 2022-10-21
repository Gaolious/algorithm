import random
MaxN = 100_000

N = MaxN #random.randint(1, MaxN)
A = [str(random.randint(1, MaxN)) for _ in range(N)]
M = MaxN#random.randint(1, MaxN)

print(N)
print(' '.join(A))
print(M)
for _ in range( M ):
    op = random.randint(1, 3)
    L = random.randint(1, N)
    R = random.randint(1, N)
    X = random.randint(1, MaxN)
    L, R = min(L,R), max(L,R)
    if op == 1:
        print(op, L, R, X)
    elif op in [2,3]:
        print(op, L, R)
