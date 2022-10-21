import random
MaxN = 10 ** 5
MaxT = 10 ** 9

N = random.randint(MaxN, MaxN)
K = random.randint(MaxN, MaxN)
T = random.randint(MaxT, MaxT)

print(N, K, T)
A = []
for _ in range(N):
    A.append( str( random.randint(K-1, K-1)))
print(' '.join(A))