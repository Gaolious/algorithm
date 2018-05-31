import random
from datetime import datetime, timedelta

def gen():
    print( random.randrange(13, 100))

random.seed( random.random() )

N = random.randrange(1, 100 + 1)
for i in range(0, N):
    gen()

print("0")
