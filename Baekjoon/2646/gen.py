import random

N = 50
t = random.randint( 10, 30)
S = random.randint( 100,1000) 
output = [S for _ in range(t) ]
print(output)

while len(output) < N:
    output = sorted(output)
    v = output[-1]
    a = random.randint(1, v-1)
    b = v - a 
    output[-1] = a
    output.append(b)

print(N)
print(' '.join([str(i) for i in output]))
