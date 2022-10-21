import sys
m, a, c, x0, n, g = 0, 0, 0, 0, 0, 0
ans = -123

def readInput():
    global m, a, c, x0, n, g, ans
    with open('input.txt', 'rt') as fin:
        m, a, c, x0, n, g = list(map(int, fin.readline().split()))
    print(f"Input m={m}, a={a}, c={c}, x0={x0}, n={n}, g={g}")
    ans = x0
    for i in range(n):
        ans = ( a * ans + c ) % m
    ans = ans % g

def readOutput():
    with open('output.txt', 'rt') as fin:
        K = int(fin.readline())
    assert ans == K, f"your answer={K}. Expected={ans}"

def check():
    pass

if __name__ == "__main__":
    readInput()
    readOutput()
    check()
