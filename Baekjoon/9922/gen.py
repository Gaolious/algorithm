import random

N = random.randint(2,5)
K = random.randint(1,N*(N-1))

num = list(range(1,N*N+1))
random.shuffle(num)
data = [ ( (i//N)+1, (i%N)+1, num[i] ) for i in range(N*N) ] 
random.shuffle(data)

print(N, K)
for row in data[:K]:
    print(row[0], row[1], row[2])
