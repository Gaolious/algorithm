import random 

N = random.randint(1,100000)
Q = random.randint(1,100000)

D = []
while ( len(D) < N*2 ): 
    D += [str(random.randint(1,2**31-1)) for _ in range(N)]
    D = list(set(D))

A = D[:N]
B = D[N:N*2]
A.sort()
B.sort()

print(N)
print(' '.join(A))
print(' '.join(B))

print(Q)
for _ in range(Q):
    i = random.randint(1,N)
    j = random.randint(1,N)
    k = random.randint(1,i+j)

    print(i, j, k)
