#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

pii A[128];
int C[128];

int K, N;

void process() {
    int s, r, i;
    char a;
    bool f;

    cin >> K ;
    for ( i = 0 ; i < K ; i ++ ) {
        cin >> a >> s >> r ;
        A[a] = { s , r };
    }
    string str;

    ll ans=0, ret=0;

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> str ;
        memset(C, 0, sizeof(C));
        f = true;
        ret = 0 ;
        for (auto c: str) {
            if ( A[c].second < ++C[c] ) f = false;
            ret += A[c].first;
        }
        if ( f ) {
            ans = max(ans, ret);
        }
    }
    cout << ans << '\n';
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


