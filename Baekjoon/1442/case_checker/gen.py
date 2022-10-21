import random
MaxN = 100000000

A = random.randint(1, MaxN)
B = random.randint(1, MaxN)
if A > B:
    A, B = B, A
print(A, B)    
