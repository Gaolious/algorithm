import random
MinN = 4
MaxN = 10
MinM = 4
MaxM = 10
N = random.randint(MinN, MaxN)
M = random.randint(MinM, MaxM)

MinA = 1
MaxA = 9
print(f'{N} {M}')
for i in range(N):
    row = []
    for j in range(M):
        row.append( str(random.randint(MinA, MaxA)) )
    print(' '.join(row))
