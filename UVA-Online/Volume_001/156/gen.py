import random
import string
from datetime import datetime, timedelta

def gen_rand_string(N):
    return ''.join(random.choice(string.ascii_uppercase + string.ascii_lowercase) for _ in range(N))

def gen(N):
    line = ''

    for i in xrange(1, N+1):
        n = random.randrange(1, 20+1)
        s = gen_rand_string(n)
        
        if len(line) + len(s) + 1 >= 80:
            print line
            line = s
            continue
        else:
            line = line + ' ' + s 

    if line:
        print line
            
random.seed( random.random() )
N = random.randrange(10,2000+1)
gen(N)

print("#")