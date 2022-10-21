import random
MaxN = 500000 
MinA = -1_000_000_000
MaxA = 1_000_000_000

N = random.randint(1, MaxN)
A = [ str(random.randint(MinA, MaxA)) for _ in range(N) ]

print(N)
print(' '.join(A))
