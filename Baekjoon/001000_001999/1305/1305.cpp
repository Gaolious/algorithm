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


int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N ;
    string s ;
    int i, j;

    cin >> N ;
    cin >> s ;
    vector <int> table(N);

    for ( j = 0, i = j + 1 ; i < N ; i ++ ) {
        while ( j>0 && s[i] != s[j] ) j = table[j-1];
        if ( s[i] == s[j] ) table[i] = ++j;
    }
    cout << N - table[N-1] << '\n';
    return 0;
}
