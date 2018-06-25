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
    ranks = ['A', 'T', 'J', 'Q', 'K' ] + [ chr(a) for a in xrange( ord('2'), ord('9') + 1 ) ]
    suits = [ 'H', 'D', 'C', 'S']

    cards = [
        '{}{}'.format(s, r) for s in suits for r in ranks
    ]
    random.shuffle(cards)
    
    for i in xrange(0, len(cards)  ):
        print '{}'.format(cards[i]),
        if ( i + 1 ) % 13 == 0 :
            print("")
    
random.seed( random.random() )
N = random.randrange(1, 100)

for i in xrange(0, N):
    gen()

print("#")    
