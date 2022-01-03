import random

N = random.randint(1, 200000)

print(N)
for _ in range(N):
  A = [ random.randint(1, 10**9) for _ in range(4) ]
  sorted(A)
  sx,sy,ex,ey =  A
  print(sx,sy,ex,ey)
