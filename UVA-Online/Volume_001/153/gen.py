import random
import string
from datetime import datetime, timedelta

def gen(n):
    s = [random.choice(string.ascii_lowercase) for _ in range(n)]
    random.shuffle(s)
    
    print( ''.join(s) )

random.seed( random.random() )

for i in range(0, 100):
    gen(random.randrange(1, 8))

print("#")
