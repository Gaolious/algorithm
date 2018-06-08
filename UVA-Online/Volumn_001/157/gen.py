import random
import string
from datetime import datetime, timedelta


def gen():
    Lines = [ chr(l) for l in xrange( ord('A') , ord('A') + random.randrange( 3, 26 ) ) ]
    stations = {
        l : [
            chr(a) for a in xrange( ord('a') , ord('a') + random.randrange( 2, 26 ) )
        ] for l in Lines
    }
    trans = {
    }

    totals = 0
    for i in stations:
        totals += len(stations[i])

    N = random.randrange( 0, totals / 2)

    for i in xrange(0, N):
        sel = random.sample(Lines, 2)
        l1 = min(sel[0], sel[1])
        l2 = max(sel[0], sel[1])

        
        s1 = random.sample( stations[ l1 ], 1)[0]
        s2 = random.sample( stations[ l2 ], 1)[0]

        # print('l1 : {} / stations : {} / selected : {}'.format(l1, stations[l1], s1))
        # print('l2 : {}'.format(l2))

        if (l2, s2) in trans.get( (l1, s1) , []):
            continue


        if (l1, s1) not in trans:
            trans.update({
                (l1, s1) : [ (l2, s2) ]
            })
        else:
            trans[ (l1, s1) ].append( (l2,s2) )



    #print(stations)
    #print(trans)

    print("{}".format(len(Lines)))

    for l in Lines:
        p = ''

        for s in stations[l]:
            p += s

            for t in trans.get( (l, s) , [] ):
                p += '={}{}'.format(t[0], t[1])

        print("{}:{}".format(l, p) )


    for i in xrange(0, random.randrange( 0, totals / 2)):
        sel = random.sample(Lines, 2)
        l1 = min(sel[0], sel[1])
        l2 = max(sel[0], sel[1])

        s1 = random.sample( stations[ l1 ], 1)[0]
        s2 = random.sample( stations[ l2 ], 1)[0]

        print("{}{}{}{}".format(l1,s1,l2,s2))


random.seed( random.random() )
gen()

print("#")