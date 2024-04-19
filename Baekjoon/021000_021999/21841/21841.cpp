#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
void process() {
    ll P, W, N;
    ll p, w, b;
    char c;

    cin >> P >> W >> N ;
    p = w = 0 ;
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> c >> b;
        if ( c == 'P') p ++;
        else if ( c == 'W' ) w++;
    }
    cout << W * w + P * p - w*p;
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


