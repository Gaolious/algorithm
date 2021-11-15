import timeit

from P0xx.prob_p09x import P98 as prob

if __name__ == '__main__':
    start = timeit.default_timer()
    ret = prob()
    stop = timeit.default_timer()

    print('Answer : ', ret)
    print('Estimated Time: ', stop - start)
