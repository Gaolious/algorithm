#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int A[12][12];
int N, K;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string CharDir[] = {"↓", "→", "↑", "←" };
pair<int,int> Parent[12];
int Dir[12];
deque<int> Piece[12][12];
bool Order[12][12];
int pop(int y, int x) {
    int t ;
    if ( Order[y][x] ) {
        t = Piece[y][x].front(); Piece[y][x].pop_front();
    }
    else {
        t = Piece[y][x].back(); Piece[y][x].pop_back();
    }
    return t;
}
void push(int y, int x, int t) {
    if ( Order[y][x] )
        Piece[y][x].push_back(t);
    else
        Piece[y][x].push_front(t);
}
int LowerPiece(int y, int x) {
    if ( Piece[y][x].empty() ) return -1;
    return Order[y][x] ? Piece[y][x].front(): Piece[y][x].back();
}
void dump() {
    int i, j ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {

            if ( Piece[i][j].empty())
                continue;

            cout << i << ' ' << j << " : " ;
            if ( Order[i][j] ) {
                for (auto t = Piece[i][j].begin() ; t != Piece[i][j].end() ; t ++ ) {
                    cout << *t << "(" << CharDir[ Dir[*t] ] << ") ";
                }
            }
            else {
                for (auto t = Piece[i][j].rbegin() ; t != Piece[i][j].rend() ; t ++ ) {
                    cout << *t << "(" << CharDir[ Dir[*t] ] << ") ";
                }
            }
            cout << '\n';
        }
    }
    cout << '\n';

}
void Merge(int y, int x, int ny, int nx, int no) {
    while ( !Piece[y][x].empty() ) {
        int t = pop(y, x);
        push(ny, nx, t);
        Parent[t] = {ny, nx};
    }
}
int move1or2(int y, int x, int ny, int nx, int no) {
    vector<int> tmp ;
    while ( LowerPiece(y, x) != no )
        tmp.emplace_back(pop(y, x));

    if ( A[ny][nx] == 1 ) {
        Order[y][x] = !Order[y][x];
        Merge(y, x, ny, nx, no);
    }
    else if ( A[ny][nx] == 0 ) {
        Merge(y, x, ny, nx, no);
    }

    for ( auto t : tmp ) push(y, x, t);

    return max(Piece[ny][nx].size(), Piece[y][x].size());
}
int Move(int no) {
    auto [y, x] = Parent[no];
    int nx = x + dx[ Dir[no] ];
    int ny = y + dy[ Dir[no] ];

    // out of range
    if ( nx < 0 || ny < 0 || nx >= N || ny >= N || A[ny][nx] == 2 ) {
        Dir[no] = ( Dir[no] + 2 ) % 4;
        nx = x + dx[ Dir[no] ];
        ny = y + dy[ Dir[no] ];
        if ( nx < 0 || ny < 0 || nx >= N || ny >= N || A[ny][nx] == 2 ) {
            return Piece[y][x].size();
        }
    }

    return move1or2(y, x, ny, nx, no);
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, y, x, d, parent ;

    memset(A, -1, sizeof(A));
    cin >> N >> K ;

    for ( i = 0 ; i < N ; i++ )
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> A[ i ][ j ] ;
            Order[i][j] = true;
        }

    for ( i = 0 ; i < K ; i ++ ) {
        cin >> y >> x >> d ;
        y--; x--;

        if ( d == 1 ) Dir[i] = 1;
        else if ( d == 2 ) Dir[i] = 3;
        else if ( d == 3 ) Dir[i] = 2;
        else Dir[i] = 0;
        Piece[y][x].emplace_back(i);
        Parent[i] = { y, x};
    }

    int step;
    // cout << "Init" << '\n';
    // dump();

    for ( step = 1 ; step <= 1000 ; step ++ ) {
        for ( i = 0 ; i < K ; i ++ ) {
            auto [y, x] = Parent[i];
            // cout << "Step : " << step << " / Piece : " << i << '\n';
            if ( Move(i) >= 4 ) {
                // dump();
                cout << step << "\n";
                return 0;
            }
            // dump();
        }
    }

    cout << "-1\n";
    return 0;
}