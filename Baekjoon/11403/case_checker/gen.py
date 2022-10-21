import random
MaxN = 3 

N = random.randint(1, MaxN)
A = [ [ str(random.randint(0,1))  for _ in range(N)] for _ in range(N) ]
for i in range(N):
    A[i][i] = '0'

print(N)
for i in range(0, N):
    print(' '.join(A[i]))
