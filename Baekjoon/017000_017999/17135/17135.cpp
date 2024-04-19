#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[15][15];
int Y, X, D;
// struct Data {
//     int d;
//     int y, x;
//     Data(int d, int y, int x) : d(d), y(y), x(x){}
//     Data() : d(-1), y(-1), x(-1){}
// };
typedef pair<int, pair<int, int>> Data;

bool cmp (Data a, Data b) {
    return (a.first != b.first) ? a.first < b.first : a.second.second < b.second.second;
}
vector<Data> POS[20][20]; // col, distance

void setup(int currY, int currX, vector<Data> &p) {
    int d;
    int i, j ;
    for ( i = currY - 1 ; i >= 0 ; i -- ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( A[i][j] != 1 )
                continue;
            d = abs(currY - i ) + abs(currX - j) ;
            if ( d <= D)
                p.push_back({d, {i, j}});
        }
    }
    sort(p.begin(), p.end(), cmp);
}

int getScore(int x1, int x2, int x3) {
    int currY, x, y, d , i, j;
    int B[15][15];
    memcpy(B, A, sizeof(A));
    int ret = 0;
    Data Q[3];
    int tail=0;

    for ( currY = Y ; currY > 0 ; currY -- ) {
        tail = 0 ;
        for( auto currX : {x1, x2, x3} ) {
            for ( auto &p : POS[currY][currX] ) {
                if ( p.first > D) continue;
                y = p.second.first;
                x = p.second.second;

                if ( B[y][x] == 1 ) {
                    Q[tail++] = p;
                    break;
                }
            }
        }

        // cout << "Curr Y = " << currY << " : " ;
        for ( i = 0 ; i < tail ; i ++ ) {
            auto &p = Q[i];
            d = p.first;
            y = p.second.first;
            x = p.second.second;
            if ( B[y][x] == 1 ) {
                ret ++;
                B[y][x] = 0;
                // cout << "(" << y << ',' << x << ":" << d << ") ";
            }
        }
        // cout << '\n';
        //
        // for ( i = 0 ; i < Y ; i ++ ) {
        //     for ( j = 0 ; j < X ; j ++ ) {
        //         cout << B[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        //
        // cout << '\n';
    }
    // cout << "x1=" << x1 <<", x2=" << x2 << ", x3=" << x3 << ", ret=" << ret << "\n" << endl;
    return ret;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, k;
    cin >> Y >> X >> D;
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> A[i][j];

    for ( i = Y ; i > 0 ; i -- ) {
        for ( j = 0 ; j < X ; j ++ ) {
            setup(i, j, POS[i][j]);
        }
    }

    int ans = 0;
    for ( i = 0 ; i < X ; i ++ ) {
        for ( j = i + 1 ; j < X ; j ++ ) {
            for ( k = j+1 ; k < X ; k ++ ) {
                ans = max(ans, getScore(i, j, k));
            }
        }
    }
    cout << ans ;
    return 0;
}


