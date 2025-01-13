#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int N;
    cin >> N;
    for ( int i = 1 ; i <= N ; i ++ ) {
        cout << i << ' ';
        if ( i % 6 == 0 )
            cout << "Go! ";
    }
    if ( N % 6 != 0 )
        cout << "Go! ";
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    process();
    return 0;
}


