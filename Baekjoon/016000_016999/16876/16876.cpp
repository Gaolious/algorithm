#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

int D[101][10000];
int N, M ;

bool F(int n, int m) {
    if ( m == 0 ) {
        return (M%2 == 0) ? (n > N) : (n <= N);
    }
    auto &ret = D[m][n];
    if ( ret < 0 ) {
        ret = false ;
        for (auto t: {1, 10, 100, 1000}) {
            auto d = (n / t + 1) % 10 - (n / t) % 10 ;
            ret = ret || !F(n + d*t, m-1);
        }
    }
    return ret;
}
void process() {
    memset(D, -1, sizeof(D));
    cin >> N >> M ;

    if ( F(N, M) ) {
        cout << "koosaga\n";
    }
    else {
        cout << "cubelover\n";
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


