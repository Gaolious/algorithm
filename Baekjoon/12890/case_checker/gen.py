import random

MaxC1 = 3
MaxC2 = 3
# MaxN = 10**15
MaxN = 10**(MaxC1+MaxC2+1)

N = random.randint(1, MaxN)
d1, c1 = random.randint(0, 9), random.randint(0, MaxC1)
d2, c2 = random.randint(0, 9), random.randint(0, MaxC2)
while d1 == d2:
    d1 = random.randint(0, 9)
print(N, d1, c1, d2, c2)
