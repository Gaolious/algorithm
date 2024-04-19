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
int N, K;
vector<vector<int>> A;

vector<int> choice[3] ;
const int JIWOO = 0 ;
const int KYEONGHEE = 1 ;
const int MINHO = 2 ;

bool F(bool debug) {
    int i;
    int win[3]{};
    int p1, p2;
    vector<int>::iterator p[3];
    for ( i = 0 ; i < 3 ; i ++ )
        p[i] = choice[i].begin();

    p1 = JIWOO, p2 = KYEONGHEE;

    while ( true ) {
        if ( p1 > p2 ) swap(p1, p2);

        if ( p[0] == choice[0].end() || p[1] == choice[1].end() || p[2] == choice[2].end() )
            break;
        if ( A[ *p[p1]++ ][ *p[p2]++ ] != 2 ) swap(p1, p2);
        if ( ++win[p1] == K ) return p1 == 0 ;
        p2 = 3 - (p1+p2);
    }
    if ( win[0] >= K ) return true;
    return false;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, n;

    cin >> N >> K ;
    A.resize(N+1, vector<int>(N+1));
    for ( i = 1 ; i <= N ; i ++ )
        for ( j = 1 ; j <= N ; j ++ )
            cin >> A[ i ][ j ] ;

    for ( j = 1 ; j <= N ; j ++ ) choice[0].push_back(j);
    for ( j = 0 ; j < 20 ; j ++ ) { cin >> n; choice[1].push_back(n) ; }
    for ( j = 0 ; j < 20 ; j ++ ) { cin >> n; choice[2].push_back(n) ; }
    do {
        if ( F(false) ) {
            cout << "1\n";
            return 0;
        }
    } while ( next_permutation(choice[0].begin(), choice[0].end()) );

    cout << "0\n";
    return 0;
}


