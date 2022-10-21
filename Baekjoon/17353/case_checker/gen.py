import random
MaxN = 100_000 
MaxA = 10 ** 6

#MaxA = 10
#MaxN = 10

N = random.randint(1, MaxN)
M = random.randint(1, MaxN )

A = [ str(random.randint(1, MaxA)) for _ in range(N) ]
print(N)
print(' '.join(A))

print(M)

for _ in range( M ):
    c = random.randint(1, 2)
    x = random.randint(1, N)
    y = random.randint(1, N)
    x, y = min(x,y), max(x,y)

    if c == 1:
        print(c, x, y)
    else:
        print(c, x)

