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

    N = random.randrange(10, 100)
    for i in xrange(0, N):
        print("{} {} {} {}".format(
            gen_rand_upper_string(), gen_rand_upper_string(), gen_rand_upper_string(), gen_rand_upper_string()
        ))
    
    
random.seed( random.random() )
gen()

print("#")