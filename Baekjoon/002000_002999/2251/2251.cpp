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

vector<vector<int>> D;
int A, B, C;
int ans[201]{};

void F(int a, int b) {
    int c = C - a - b;
    int remain[] = { A-a, B-b, C-c};
    if ( D[a][b] < 0 ) {
        D[a][b] = c;
        if ( a == 0 )
            ans[c] = 1;
        for ( int i = 0 ; i < 3 ; i ++ )
            for ( int j = 0 ; j < 3 ; j ++ ) {
                if ( i == j ) continue;
                int cap[]= {a, b, c};
                int t = min(cap[i], remain[j]);
                cap[i] -= t;
                cap[j] += t;
                F(cap[0], cap[1]);
            }
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    cin >> A >> B >> C;
    D.resize(A+1, vector<int>(B+1, -1));
    F(0, 0);
    for ( int i = 0 ; i <= 200 ; i ++ )
        if ( ans[i] > 0 )
            cout << i << ' ';
    return 0;
}


