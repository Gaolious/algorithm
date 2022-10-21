import random
MaxQ = 100000 
MaxN = 9999

Q = random.randint(1, MaxQ)
print(Q)
for _ in range(Q):
    c = random.randint(1, 2)
    if c == 1:
        n = random.randint(3, MaxN)
        x = random.randint(1, n)
        y = random.randint(1, n)
        print(c, n, x, y)
    else:
        n = random.randint(1, MaxN)
        z = random.randint(1, n*n)
        print(c, n, z)

