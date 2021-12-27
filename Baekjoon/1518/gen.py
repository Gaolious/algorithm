import random

A = [ i for i in range(1, 25+1) ]
B = []
random.shuffle(A)
for i in range(5):
    B.append( sorted(A[i*5:i*5+5]))

for i in range(5):
    idx = random.randint(0,10)
    for j in range(5):
        if j != idx:
            B[i][j] = 0

    print(' '.join([ str(a) for a in B[i] ]))
