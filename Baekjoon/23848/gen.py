import random

a = random.randint(1,10000000)
r = random.randint(3, 1000)
s = 0
T = [ a, a*r, a*r*r ]


while ( sum(T) + T[-1] * r <= 1000000000000 ):
    T.append( T[-1] * r )

print( sum(T))

print(f"a={a}")
print(f"r={r}")
print(T)
