#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

const int MaxN = 20'000;
bool Col[ MaxN ];
bool Row[ MaxN ];
bool D1[ MaxN * 2 + 1 ];
bool D2[ MaxN * 2 + 1 ];

void process() {
    int Y, X, N;
    int x, y;
    int i;
    while ( cin >> Y >> X >> N && Y && X ) {
        memset(Col, 0, sizeof(Col));
        memset(Row, 0, sizeof(Row));
        memset(D1, 0, sizeof(D1));
        memset(D2, 0, sizeof(D2));
        while (N--) {
            cin >> y >> x;
            x--;
            y--;
            Col[x] = true;
            Row[y] = true;
            D1[x + y] = true;
            D2[y - x + MaxN] = true;
        }
        vector<int> Xp, Yp;
        for (i = 0; i < Y; i++) if (!Row[i]) Yp.push_back(i);
        for (i = 0; i < X; i++) if (!Col[i]) Xp.push_back(i);

        int ans = 0;
        for (auto y: Yp)
            for (auto x: Xp)
                if ( !D1[x + y] && !D2[y - x + MaxN])
                    ans++;
        cout << ans << '\n';
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


