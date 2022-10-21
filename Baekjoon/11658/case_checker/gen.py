import random
MaxN = 4
MaxM = 4
MaxC = 10

N = random.randint(1, MaxN)
M = random.randint(1, MaxM)

A = [ [ str(random.randint(1, MaxC)) for _ in range(N)] for _ in range(N) ]

print(N, M)
for i in range(N):
    print(' '.join(A[i]))

for i in range(M):
    w = random.randint(0, 1)
    if w == 1:
        x2, y2 = random.randint(1,N), random.randint(1,N)
        x1, y1 = random.randint(1,N), random.randint(1,N)
        if x1 > x2: 
            x1, x2 = x2, x1
        if y1 > y2:
            y1, y2 = y2, y1
        print(w, x1, y1, x2, y2)
    else:
        x, y = random.randint(1,N), random.randint(1,N)
        c = random.randint(1,MaxC)
        print(w, x, y, c)

