import random
MaxN = 4 
MaxM = 4

N = random.randint(2, MaxN)
M = random.randint(1, MaxM)

A = [ i for i in range(2, N+1) ]
random.shuffle(A)
B = [0, 1] + A

print(N)
for i in range(2, N+1):
    print("{} {}".format( B[i//2], B[i]) )

print(M)
for i in range(M):
    a = random.randint(1, MaxN)
    b = random.randint(1, MaxN)
    print("{} {}".format(a, b))
