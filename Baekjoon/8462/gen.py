import random
MaxN = 10**5
MaxA = 10**6
N = random.randint(1, MaxN)
T = random.randint(1, MaxN)
A = [ str(random.randint(1, MaxA)) for _ in range(N) ]

print( N, T )
print( ' '.join(A) )
for _ in range(T):
  A = [ random.randint(1, N), random.randint(1, N) ]
  x = min(A)
  y = max(A)
  print(x, y)

