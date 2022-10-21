import random
MaxN = 10 

T = random.randint(1, 1)
print(T)

for _ in range( T ):
    N = random.randint(1, 20000)
    C = random.randint(1, 10**9)
    print(N, C)

    print(' '.join([ str( random.randint(1,20000) ) for _ in range(N) ]))

