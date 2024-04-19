#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;

void process() {
    ll W, H, a, b ;
    cin >> W >> H ;
    a=W, b=H;
    while ( W%2 == 0 ) W/=2, H*=2;
    while ( b%2 == 0 ) a*=2, b/=2;
    cout << max( W+H, a+b) * 2 << '\n';
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


