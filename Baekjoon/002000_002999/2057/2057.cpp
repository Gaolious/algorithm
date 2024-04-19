#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);
using namespace std;
typedef long long int ll;

void process() {
    vector<ll> A(20);
    ll n, i, s, N;

    A[0] = A[1] = 1;
    for ( i = 2 ; i < 20 ; i ++ ) A[i] = A[i-1]*i;

    cin >> N ;
    if ( N > 0  ) {
        for ( s = 0, n = A.size(), i = n-1 ; i >= 0 ; i -- ) {
            if ( N >= A[i]  )
                N -= A[i];
        }
        if ( N == 0 ) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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


