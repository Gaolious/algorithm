import random
import string
from datetime import datetime, timedelta

def gen():
    k = random.randrange(1, 512 + 1 )
    x = random.randrange(1, 2048 + 1 )
    y = random.randrange(1, 2048 + 1 )

    print("{} {} {}".format(x, y, k))

random.seed( random.random() )

N = random.randrange(100,1000+1)

for i in range(0, N):
    gen()

print("0 0 0")