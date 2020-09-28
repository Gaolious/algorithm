import random

def gen():

    # min diameter : 0.1
    # diameter <= x, y <= 1 - diameter
    diameter = random.randrange(10, 50 + 1)

    x = random.randrange(diameter, 100 - diameter + 1)
    y = random.randrange(diameter, 100 - diameter + 1)
    
    print("0.{0:02d} 0.{1:02d} 0.{2:02d}".format(diameter, x, y) )


random.seed( random.random() )

N = random.randrange(1, 100 + 1)
for i in xrange(0, N):
    gen()

print("0 0 0")