#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void process() {
    int y, x;
    int Y, X, N;
    int i, cnt;
    char c;

    cin >> X >> Y >> N ;
    x = y = 0 ;

    cnt = 0;
    if ( abs(x-X) <= 1 && abs(y-Y) <= 1 ) {
        cout << 0 << '\n';
        cnt ++;
    }
    for ( i = 1 ; i <= N ; i ++ ) {
        cin >> c;
        if ( c == 'I' ) x++;
        else if ( c == 'S' ) y++;
        else if ( c == 'Z' ) x--;
        else if ( c == 'J' ) y--;

//        cout << '(' << y << ", " << x << ")\n";
        if ( abs(x-X) <= 1 && abs(y-Y) <= 1 ) {
            cout << i << '\n';
            cnt ++;
        }
    }
    if ( cnt == 0 )
        cout << "-1\n";
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


