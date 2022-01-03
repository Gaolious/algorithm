import random
a = random.randint(1, 100000000)
c = random.randint(1, 100000000)
seed = random.randint(1, 100000000)
m = random.choice(
    [73,	79,	83,	89,	97,	101,	103,	107,	109,	113,	127,	131,	137,	139,	149,	151,	157,	163,	167,	173]
    )

x1 = ( a * seed + c ) % m 
x2 = ( a * x1 + c ) % m
print(m, seed, x1, x2)

