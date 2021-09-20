from typing import List

from utils.help import factorial


def P171():
    """
        n이 자연수일 때, f(n)을 n의 10진법 표현에서 모든 자릿수의 제곱의 합이라고 합시다. 즉,

        f(3) = 32 = 9,
        f(25) = 22 + 52 = 4 + 25 = 29,
        f(442) = 42 + 42 + 22 = 16 + 16 + 4 = 36

        0 < n < 10^20일 때, f(n)이 완전 제곱수인 모든 n을 찾아 더하고, 그 합의 마지막 9 자리를 제출하세요.
    """
    MOD = 1_000_000_000
    n = 20

    f = [[0] * (n * 81 + 1) for i in range(n + 1)]
    g = [[0] * (n * 81 + 1) for i in range(n + 1)]

    f[0][0], g[0][0] = 1, 0  # cnt, sum

    for i in range(n):
        for j in range(i * 81 + 1):
            for k in range(10):
                f[i + 1][j + k * k] = ( f[i + 1][j + k * k] + f[i][j] ) % MOD
                g[i + 1][j + k * k] = ( g[i + 1][j + k * k] + g[i][j] + k * 10 ** i * f[i][j] ) % MOD

    ans = 0
    for i in range(n * 9):
        if i * i > n * 9 * 9:
            break
        ans = ( ans + g[n][i * i] ) % MOD
    print(ans)