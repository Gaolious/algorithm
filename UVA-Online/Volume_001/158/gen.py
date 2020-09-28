import random
import string
from datetime import datetime, timedelta

def gen_rand_string():
    N = random.randrange(1, 255+1)
    return ''.join(random.choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(N))

def gen():
    year = random.randrange(1901, 1999 + 1)

    print(year)

    A = random.randrange( 5, 300 )

    for i in xrange(0, A):
        dt = datetime(year=random.randrange(1901, 1999 + 1), month=1, day=1) + timedelta(days=random.randrange(-10000, 10000))

        print("A {} {} {} {}".format(
            dt.day, dt.month, random.randrange(1, 7+1), gen_rand_string()
        ))

    D = random.randrange( 1, 100)

    for i in xrange(0, A):
        dt = datetime(year=random.randrange(1901, 1999 + 1), month=1, day=1) + timedelta(days=random.randrange(-10000, 10000))

        print("D {} {}".format(
            dt.day, dt.month
        ))
    
random.seed( random.random() )
gen()

print("#")