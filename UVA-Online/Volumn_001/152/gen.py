import random
from datetime import datetime, timedelta

def gen():
    x = random.randrange(0, 255 + 1)
    y = random.randrange(0, 255 + 1)
    z = random.randrange(0, 255 + 1)
    print( "{} {} {}".format(x, y, z) )


random.seed( random.random() )

N = random.randrange(1, 5000 + 1)
for i in range(0, N):
    gen()

print("0 0 0")
