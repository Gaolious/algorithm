import random
from datetime import datetime, timedelta

def gen():

    # min diameter : 0.1
    # diameter <= x, y <= 1 - diameter
    y = random.randrange(1600, 2099+1)
    m = 1
    d = 1
    max_dt = datetime(2099,12,31,23,59,59)

    dt = datetime( y, m, d )

    while dt < max_dt :
        print (dt.strftime('%A %d %B %Y'))
        dt += timedelta(days = random.randrange(1,1000))


random.seed( random.random() )

N = random.randrange(1, 100 + 1)
for i in range(0, N):
    gen()

print("#")
