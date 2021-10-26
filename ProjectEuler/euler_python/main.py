

# Press the green button in the gutter to run the script.
from P0xx.prob_p06x import *
import timeit

from P0xx.prob_p08x import P83, P82

if __name__ == '__main__':
    start = timeit.default_timer()
    ret = P82()
    stop = timeit.default_timer()

    print('Answer : ', ret)
    print('Estimated Time: ', stop - start)
