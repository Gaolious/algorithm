import random
_ = random.randint

X = _(1, 10**11)
A = _(1, 10**11)
B = _(1, 10**11)
if A > B:
    A, B = B, A

P = [ i for i in range(10) ]
n = _(2,5)
while n > 0:
    n -= 1
    random.shuffle(P)
    del P[-1]
P = sorted(P)    
print(X, A, B)
print(''.join([str(i) for i in P]))
