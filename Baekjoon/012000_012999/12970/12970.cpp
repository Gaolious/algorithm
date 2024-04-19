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

vector<char> ans ;
int N, K;
char D[50][50][1226];

void Print(int a, int b) {
    while ( a || b ) {
        if ( a > 0 && b <= K ) {
            cout << 'A';
            K-= b;
            a--;
            continue;
        }
        if ( b > 0 ) {
            cout << 'B';
            b--;
            continue;
        }
        break;
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    cin >> N >> K ;

    ans.resize(N);

    for ( int i = 0 ; i <= N ; i ++ ) {
        if ( i * ( N - i) >= K ) {
            Print(i, N-i);
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}


