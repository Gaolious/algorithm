#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Data {
    int a, b, c;
};
vector<Data> A;
bool chk[1000];
int B[3][3];
int C[3][3];
void SetToC(int i, int j) {
    C[i][0] = A[j].a;
    C[i][1] = A[j].b;
    C[i][2] = A[j].c;
}
int COL(int i, int len) {
    int j, ret = 0;
    for ( j = 0 ; j < len ; j ++ )
        ret = ret * 10 + C[j][i];
    return ret;
}
int DR(int len) {
    int j, ret = 0;
    for ( j = 0 ; j < len ; j ++ )
        ret = ret * 10 + C[j][j];
    return ret;
}
int DL(int len) {
    int j, ret = 0;
    for ( j = 0 ; j < len ; j ++ )
        ret = ret * 10 + C[j][2-j];
    return ret;
}

void dump() {
    int i, j;
    for ( i = 0 ; i < 3 ; i ++) {
        for ( j = 0 ; j < 3 ; j ++ ) {
            cout << C[ i ][ j ] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int GetScore() {
    int i, j, ret = 0;
    for ( i = 0 ; i < 3 ; i ++) {
        for ( j = 0 ; j < 3 ; j ++ ) {
            ret += abs( B[i][j] - C[i][j] );
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
    int i, j, k;
    for ( i = 0 ; i < 3 ; i ++ )
        for ( j = 0 ; j < 3 ; j ++ )
            cin >> B[i][j];

    for ( i = 1 ; i <= 9 ; i ++ )
        for ( j = 1 ; j <= 9 ; j ++ )
            for ( k = 1 ; k <= 9 ; k ++ )
                if ( i+j+k == 15 && i != j && i != k && j != k ) {
                    chk[i*10 + j] = true;
                    chk[i*100 + j*10 + k] = true;
                    A.push_back({i, j, k});
                }

    int best = 100;

    for ( i = 0 ; i < A.size() ; i ++ ) {
        SetToC(0, i);
        for ( j = 0 ; j < A.size() ; j ++ ) {
            SetToC(1, j);
            if ( !chk[ COL(0, 2)] || !chk[ COL(1, 2)] || !chk[ COL(2, 2)] ) continue;
            if ( !chk[ DR(2) ] || !chk[ DL(2) ] ) continue;

            for ( k = 0 ; k < A.size() ; k ++ ) {
                SetToC(2, k);
                if ( !chk[ COL(0, 3)] || !chk[ COL(1, 3)] || !chk[ COL(2, 3)] ) continue;
                if ( !chk[ DR(3) ] || !chk[ DL(3) ] ) continue;
                best = min(best, GetScore());
            }
        }
    }
    cout << best << '\n';
    return 0;
}


