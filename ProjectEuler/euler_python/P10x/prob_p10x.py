from utils.help import Fraction


def P101():

    def U(n: int) -> int:

        ret = 0

        for i in range(0, 10 + 1):
            if i % 2 == 0:
                ret += n ** i
            else:
                ret -= n ** i
        return ret

    def print_matrix(M, size):
        print("\nMatrix")
        for i in range(size):
            s = []
            for j in range(0, size):
                s .append('{0:6s}'.format( str(M[i][j])))
            print("{} : {}".format(' '.join(s), M[i][-1]))

    def addMatrix(M, size, fromIdx, toIdx, multiply):
        for j in range(size+1):
            tmp = M[fromIdx][j] * multiply
            M[toIdx][j] = M[toIdx][j] + tmp

    def solve_equation(size: int):
        M = [[0 for _ in range(size+1)] for _ in range(size)]

        for i in range(size):

            PowN = Fraction((i + 1) ** (size - 1))

            for j in range(size):
                M[i][j] = PowN
                PowN = PowN / (i+1)

            M[i][size] = Fraction(U(i + 1))

        # print_matrix(M, size)

        for i in range(size):
            for j in range(size):
                if i == j:
                    continue
                if M[i][i] == 0:
                    continue

                T = M[j][i] / M[i][i]
                T = Fraction(-1) * T
                addMatrix(M, size, i, j, T)

            if M[i][i] != 0:
                t = M[i][i]
                for j in range(size+1):
                    M[i][j] = M[i][j] / t

        print_matrix(M, size)


        co = [Fraction(0) for _ in range(size)]

        for i in range(size):
            for j in range(size):
                if M[i][j] != 0:
                    co[i] = M[i][size]
                    break

        for i in range(1, 30):
            ret = Fraction(0)
            PowN = Fraction(i ** (size - 1))

            for j in range(size):
                ret += co[j] * PowN
                PowN /= i

            u = U(i)
            if u != ret:
                print("size={0:3d} / n={1:3d} / eq={2:14s} / U({3})={4:14s}".format(
                    size,
                    i,
                    str(ret),
                    i,
                    str(U(i)),
                ))
                return ret

        return Fraction(0)

    ret = Fraction(0)
    for i in range(1, 20):
        ret += solve_equation(i)

    print("ans :                 {}".format(ret))
