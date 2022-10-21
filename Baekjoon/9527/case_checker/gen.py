import random
MinN = 1
MaxN = 10**16

N = random.randint(MinN, MaxN)
K = random.randint(MinN, MaxN)
if K > N:
    N, K = K, N

print(N, K)
