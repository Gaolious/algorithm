import random
import string
from datetime import datetime, timedelta

def gen_rand_string():
    N = random.randrange(1, 255+1)
    return ''.join(random.choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(N))

def gen_rand_upper_string():
    N = random.randrange(1, 10 + 1)
    return ''.join(random.choice(string.ascii_uppercase) for _ in range(N))

def gen():
    N = random.randrange(2, 100+1)
    
    for i in xrange(0, N):
        print (random.randrange( 10, 90+1)),
    print("0")
    
random.seed( random.random() )
cases = random.randrange(10, 50)
for i in xrange(0, cases):
    gen()

print("0 0 0")