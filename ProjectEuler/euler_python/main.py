import timeit

from P1xx.prob_p15x import P152 as prob

if __name__ == '__main__':
    start = timeit.default_timer()
    ret = prob()
    stop = timeit.default_timer()

    print('Answer : ', ret)
    print('Estimated Time: ', stop - start)
