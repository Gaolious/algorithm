#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int Y = 6;
const int X = 4;
struct Data {
    char Map[6][4]{};
    int W[6]{};
    int H[4]{};
    int score{};
    int cnt{} ;

    void Put1(int x) {
        int y = Y - 1 - H[x];
        Map[y][x] = '*';
        cnt ++;
        W[y]++;
        H[x]++;
    }
    void Put2(int x) {
        Put1(x);
        Put1(x);
    }
    void Put3(int x) {
        int y = max( H[x], H[x+1] );
        H[x] = H[x+1] = y;
        Put1(x);
        Put1(x+1);
    }
    void check() {
        int k = 0;
        int over_cnt = 0, filled_cnt = 0, i, j ;
        for ( i = Y-1 ; i >= 2 ; i -- )
            if ( W[i] == X ) filled_cnt++;
        for ( i = 1 ; i >= 0 ; i -- )
            if ( W[i] > 0 ) over_cnt++;

        if ( filled_cnt == 0 && over_cnt == 0 )
            return;

        for (i=j=Y-1 ; i>=0 ; i -- ) {
            if ( W[i] == X ) {
                score ++;
                continue;
            }
            if ( filled_cnt < over_cnt ) {
                over_cnt --;
                continue;
            }
            if ( i != j )
                memcpy(Map[j], Map[i], sizeof(Map[i]));
            j--;
        }
        memset(Map, 0, sizeof(char)*2*X);
        memset(H, 0, sizeof(H));
        memset(W, 0, sizeof(W));
        for ( i = 2 ; i < Y; i ++ ) {
            for ( j = 0 ; j < X ; j ++ ) {
                if ( Map[i][j] == '*' ) {
                    W[i] ++;
                    H[j] = max(H[j], Y-i);
                    k++;
                }
            }
        }
        cnt = k;
    }

    void dump() {
        int i, j ;
        for ( i = 0 ; i < Y; i ++ ) {
            cout << i << ' ' ;
            for ( j = 0 ; j < X ; j ++ ) {
                if ( Map[i][j] == '*' )
                    cout << '*';
                else
                    cout << '.';
            }
            cout << '\n';
        }
        cout << '\n';
    }
};

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N ;
    int t, x, y;

    Data H, V;
    cin >> N ;

    while ( N -- ) {
        cin >> t >> x >> y ;
        if ( t == 1 ) {
            H.Put1(3-y);
            V.Put1(x);
        }
        else if ( t == 2 ) {
            H.Put3(2-y);
            V.Put2(x);
        }
        else if ( t == 3 ) {
            H.Put2(3-y);
            V.Put3(x);
        }
        H.check();
        V.check();
        // cout << "가로\n";
        // H.dump();
        // cout << "세로\n";
        // V.dump();
    }
    cout << H.score + V.score << '\n' << H.cnt + V.cnt << '\n';
    return 0;
}


