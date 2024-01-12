import random

R = lambda a, b: random.randint(a, b)  # random a ~ b; R(1,10)
S = lambda a: random.shuffle(a)  # shuffle array of a; S(List)

MaxN = 10 

N = R(1, MaxN)
K = R(0, N * (N+1) // 6 )
A = [ R(1,10) for _ in range(10) ]
S(A)
print(A)

