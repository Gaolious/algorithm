#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

int P[24] = {
12345,
23415,
34125,
41235,
104523,
120453,
145203,
152043,
201534,
215304,
230154,
253014,
302541,
325401,
340251,
354021,
403512,
410352,
435102,
451032,
514320,
521430,
532140,
543210,
};
struct Cube {
    int Color[6];
    int minVal( ) {
        int i, j, ret = -1, n, t;
        for ( i = 0 ; i < 24 ; i ++ ) {
            for ( n=0, j = 0, t=P[i] ; j < 6 ; j ++, t/=10) n = n * 10 + Color[ t%10 ];
            if ( ret < 0 || ret > n ) ret = n ;
        }
        return ret;
    }
};
bool Check[1'000'000];
void process() {
    int N, i, j, ans, m ;
    Cube c{} ;
    while ( cin >> N && N ) {
        ans = 0 ;
        memset(Check, 0, sizeof(Check));
        for (i = 0 ; i < N ; i ++ ) {
            for (j = 0; j < 6; j++) cin >> c.Color[j];
            if (!Check[m = c.minVal()]) {
                Check[m] = true;
                ans ++;
            }
        }
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


