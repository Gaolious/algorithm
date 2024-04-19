#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }
const int MaxN = 86;

void process() {
    int i, len=0 ;
    ll K;
    cin >> K;

    vector D(2, vector<ll>(MaxN + 1));

    D[0][1] = 1;
    D[1][1] = 1;
    for ( i = 2 ; i <= MaxN  ; i ++ ) {
        D[0][i] = D[0][i-1] + D[1][i-1];
        D[1][i] = D[0][i-1];
    }

    len = 0 ;
    while (D[1][len] < K ) {
        K -= D[1][len++];
    }
    string ans = "1";
    for ( i = 1 ; i < len ; i ++ ) {
        if ( K > D[0][len-i] ) {
            K -= D[0][len-i];
            ans.push_back('1');
        }
        else {
            ans.push_back('0');
        }
    }
    cout << ans ;
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


