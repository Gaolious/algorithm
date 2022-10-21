import random
MaxN = 10 

N = random.randint(1, MaxN)
K = random.randint(0, N * (N+1) // 6 )
A = [ [0 for _ in range(N+1)] for _ in range(N+1) ]
for _ in range( K ):
    y = random.randint(1, N)
    x = random.randint(1, N)
    A[y][x] = A[x][y] = 1
K = 0
for i in range(1, N+1):
    for j in range(i+1, N+1):
        if A[i][j] > 0:
            K += 1

print(N, K)
for i in range(1, N+1):
    for j in range(i+1, N+1):
        if A[i][j] > 0:
            print(i, j)
