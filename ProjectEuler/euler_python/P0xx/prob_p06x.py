from utils.help import ContinuedFraction, Fraction, GetFractionByContinuedListA, Prime, gcd


def P66():
    """
        x^2 – D * y^2 = 1
        x^2 – 1 = D * y^2
        sqrt(D) = sqrt( x^2 – 1 ) / y

    :return:
    """
    max_x = 0
    max_d = 0
    k = 0

    for D in range(1, 1000+1):
        while k * k < D:
            k += 1
        if k * k == D:
            k += 1
            continue

        cf = ContinuedFraction(c=D)

        list_a = []
        for i in range(100):
            a, cf = cf.extract()
            list_a.append(a)

            ret = GetFractionByContinuedListA(list_a)
            x = ret.child
            y = ret.parent

            if x*x - D*y*y == 1:
                if max_x < x:
                    max_x = x
                    max_d = D
                break

    print(max_d)


def P68():

    def is_possible(n1, n2, S):
        if n1 + n2 + 1 <= S <= n1 + n2 + 10:
            return not check[S - (n1 + n2) - 1]
        return False

    def recur(idx, S, check, number, N):
        if idx >= 5:
            if not (0 <= S - number[0] - number[4] - 1 < N): return 0
            if check[S - number[0] - number[4] - 1]: return 0

            ret = [
                [S - number[0] - number[1], number[1], number[0]],
                [S - number[4] - number[0], number[0], number[4]],
                [S - number[3] - number[4], number[4], number[3]],
                [S - number[2] - number[3], number[3], number[2]],
                [S - number[1] - number[2], number[2], number[1]],
            ]
            minV = min([a[0] for a in ret])
            minIdx = -1
            for i in range(len(ret)):
                if ret[i][0] == minV:
                    minIdx = i
                    break

            str_number = []
            for i in range(len(ret)):
                str_number.append(
                    ''.join(
                        [str(a) for a in ret[ (i + minIdx) % len(ret)]]
                    )
                )

            str_n = ''.join(str_number)
            if len(str_n) == 16:
                print("{} : S={} / {} / {}".format(str_n, S, ret, number))
                return int(str_n)
            return 0

        ans = 0
        for i in range(N):
            remain_number = S - number[idx-1] - (i+1)

            if not (1 <= remain_number <= N): continue
            if check[i] or check[remain_number - 1]: continue
            if i == remain_number - 1: continue

            check[i] = True
            check[remain_number - 1] = True

            number[idx] = i + 1
            number[idx+4] = S - number[idx-1] - (i+1)

            r = recur(idx+1, S, check, number, N)
            if r and ans < r:
                ans = r

            check[i] = False
            check[remain_number - 1] = False

            number[idx] = 0
            number[idx+4] = 0

        return ans

    N = 10
    check = [False] * N
    number = [0] * N
    ans = 0

    ans = 0
    for i in range(N):
        for s in range(13, 25):
            check[i] = True
            number[0] = i + 1
            ans = max( ans, recur(1, s, check, number, N))
            check[i] = False
            number[0] = 0

    return ans


def P69():
    P = Prime(10000)
    P.sieve()

    N = 1_000_000
    k = 1
    for p in P.number:
        if k * p > N:
            break
        k *= p
    return k
    #
    # cnt = 0
    # for i in range(2, k):
    #     if gcd(i, k) == 1:
    #         cnt += 1
    #
    # return k / cnt

