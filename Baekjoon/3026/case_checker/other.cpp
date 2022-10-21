#include<cstdio>
#include<cstring>
using ll = long long;
const ll BRANCH = 1e5;
ll X, dp[2][2][13][BRANCH], p10[12] = { 1 };
int N, can[10];
void gv(ll A, int* a) {
    int i, t;
    N = 0;
    while (A) {
        a[N++] = A % 10;
        A /= 10;
    }
}
ll rec(int l, int u, int p, int r, int* a) {
    if (p == -1) return !r;
    ll& ret = dp[l][u][p][r];
    if (ret != -1) return ret;
    ret = 0;
    int i, L = l ? a[p] : 9;
    for (i = 0; i <= L; i++) if (can[i] || (!i && !u && p))
        ret += rec(l && i == L, u || i > 0, p - 1, (r - p10[p] * i % X + X) % X, a);
    return ret;
}
int main() {
    char c[11];
    ll A, B, ans = 0, t, v, f;
    int i, a[12], b[12];
    for (i = 1; i < 12; i++) p10[i] = 10 * p10[i - 1];
    scanf("%lld%lld%lld\n%s", &X, &A, &B, &c);
    for (i = 0; c[i]; i++)
        can[c[i] - '0'] = 1;
    if (X < BRANCH) {
        memset(dp, -1, sizeof dp);
        gv(B, b);
        ans = rec(1, 0, N - 1, 0, b);
        memset(dp, -1, sizeof dp);
        A--;
        gv(A, a);
        ans -= rec(1, 0, N - 1, 0, a);
    }
    else {
        t = X;
        while (t <= B) {
            v = t;
            f = 1;
            while (v) {
                f &= can[v % 10];
                v /= 10;
            }
            ans += f && A <= t;
            t += X;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
