import random
import string
from datetime import datetime, timedelta

def gen():
    # o/P,y/N,b/G,g/A,r/S
    key = ['o', 'y', 'b', 'g', 'r']
    val = ['P', 'N', 'G', 'A', 'S']
    random.shuffle(key)
    random.shuffle(val)

    s = []

    for i in range(len(key)):
        s.append( '{}/{}'.format(key[i], val[i]))

    print( ','.join(s) )

random.seed( random.random() )

N = random.randrange(10,100+1)
N2 = random.randrange(10,100+1)

for i in range(0, N):
    for j in range(0, N2):
        gen()

    e = "e{}".format(
        ''.join(
            [
                random.choice(string.ascii_lowercase) 
                for _ in range(random.randrange(0,1000))
            ]
        )
    )
    print(e)

print("#")