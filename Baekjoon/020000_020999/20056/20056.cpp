#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Fireball {
    int y, x;
    int m, s, d;
    int oddCnt{}, evenCnt{} ;

    bool operator < (Fireball &o) const {
        return ( y == o.y ) ? x < o.x : y < o.y ;
    }
    bool equalPos(Fireball &o) const {
        return y == o.y && x == o.x;
    }
    void dump() {
        cout << "(" << y << "," << x <<"), m=" <<m << ", s="<<s <<", d=" << d << '\n';
    }
};
vector<Fireball> A[2];
int N, Y, X, K;
void Move(int turn) {
    for (auto &f : A[ turn ] ) {
        f.y = ( f.y + dy[ f.d ] * f.s ) % Y ;
        f.x = ( f.x + dx[ f.d ] * f.s ) % X ;
        f.y = ( f.y + Y ) % Y;
        f.x = ( f.x + X ) % X;
    }
}
int MergeAndSplit(int from, int to) {
    int i, d, newIdx, s, m, y, x;
    int ret;
    newIdx = 0;
    sort(A[from].begin(), A[from].end());

    for ( newIdx = -1, i = 0 ; i < A[from].size() ; i ++ ) {
        if ( i == 0 || !A[from][newIdx].equalPos( A[from][i]) ) {
            newIdx++;
            A[from][newIdx] = A[from][i];
            A[from][newIdx].oddCnt = A[from][newIdx].evenCnt = 0 ;
        }
        else {
            A[from][newIdx].m += A[from][i].m ;
            A[from][newIdx].s += A[from][i].s ;
        }
        (A[from][i].d % 2 == 0 ? A[from][newIdx].evenCnt :  A[from][newIdx].oddCnt )++;
    }

    A[to].clear();

    ret = 0 ;
    for (i = 0 ; i <= newIdx ; i ++ ) {
        if ( A[from][i].evenCnt +  A[from][i].oddCnt < 2 ) {
            A[to].push_back(A[from][i]);
            ret += A[from][i].m;
            continue;
        }
        y = A[from][i].y, x = A[from][i].x ;
        d = ( A[from][i].evenCnt * A[from][i].oddCnt == 0 ) ? 0 : 1;
        m = A[from][i].m / 5 ;
        s = A[from][i].s / ( A[from][i].evenCnt + A[from][i].oddCnt );
        if ( m < 1 ) continue;

        for ( ; d < 8 ; d += 2 ) {
            A[to].push_back({y, x, m, s, d});
            ret += m;
        }
    }
    return ret;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i ;
    int y, x, m, s, d, ret=0;
    cin >> Y >> N >> K ;
    X = Y ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> y >> x >> m >> s >> d ;
        y--; x--;
        A[0].push_back({y, x, m, s, d});
        ret += m;
    }
    for ( i = 0 ; i < K ; i ++ ) {
        Move(i % 2);
        ret = MergeAndSplit(i % 2, 1 - (i%2) );
    }
    cout << ret << '\n';
    return 0;
}


