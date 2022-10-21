import random
MaxT = 1
MaxN = 100
MaxM = 100

T = random.randint(1, MaxT)
print(T)
for _ in range(T):
    N = random.randint(1, MaxN)
    M = random.randint(1, MaxM)
    A = [ str(random.randint(1, N)) for _ in range(N) ]
    print(N, M)
    print(' '.join(A))
