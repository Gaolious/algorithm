import sys


def F():
    prev = ''
    cnt = 0
    ret = {
        0: 0
    }

    for c in sys.stdin.readline():
        if c == '(':
            cnt += 1
            ret.update({
                cnt: 0
            })

        elif c == ')':
            if prev == '(':
                ret[cnt] = 0
                cnt -= 1
                ret[cnt] += 1
            else:
                tmp = ret[cnt] * 2
                ret[cnt] = 0
                cnt -= 1
                ret[cnt] += tmp

        prev = c

    return ret[0]


def sol():
    N = int(sys.stdin.readline())
    while N > 0:
        N -= 1
        v1 = F()
        v2 = F()

        if v1 == v2:
            print("=")
        if v1 > v2:
            print(">")
        if v1 < v2:
            print("<")


if __name__ == '__main__':
    sol()
