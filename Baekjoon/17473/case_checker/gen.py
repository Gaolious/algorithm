import random
MaxN = 200_000
MaxA = 2**20 - 1
MaxM = 200_000

MaxN = 4
MaxA = 0xF
MaxM = 5

N = random.randint(1, MaxN)
A = [str(random.randint(0, MaxA)) for _ in range(N) ]

print(N)
print(' '.join(A))

M = random.randint(1, MaxM)
print(M)
for _ in range(M):
    op = random.randint(1,3)
    L = random.randint(1, N)
    R = random.randint(1, N)
    X = random.randint(0, MaxA)
    L, R = min(L, R), max(L, R)

    if op in [1, 2]:
        print(f'{op} {L} {R} {X}')
    else:
        print(f'{op} {L} {R}')

