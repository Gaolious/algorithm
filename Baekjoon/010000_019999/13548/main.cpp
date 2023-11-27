#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int rt;
int cnt[1000001];
int arr[100001], ans[100001];
int cur;

struct query {
    int l, r, n;
    bool operator<(const query &o) const {
        int x = r / rt;
        int y = o.r / rt;
        return x == y ? l < o.l : x < y;
    }
} q[100001];

void f(int index, bool add)
{
    if (add)
    {
        if (cnt[arr[index]]++ == 0)
            cur++;
    }
    else
    {
        if (--cnt[arr[index]] == 0)
            cur--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, i;
    cin >> n;
    rt = (int)sqrt(n);
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].n = i;
    }
    sort(q, q + m);

    int lo = 1, hi = 0;
    for (i = 0; i < m; i++)
    {
        while (q[i].l < lo)
            f(--lo, true);
        while (q[i].l > lo)
            f(lo++, false);
        while (q[i].r < hi)
            f(hi--, false);
        while (q[i].r > hi)
            f(++hi, true);
        ans[q[i].n] = cur;
    }

    for (i = 0; i < m; i++)
        cout << ans[i] << '\n';
}