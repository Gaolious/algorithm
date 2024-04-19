#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int Y, X;

void OperR(int src[100][100], int dest[100][100]) {
    int i, j;
    int MaxCol = 0;

    memset(dest, 0, sizeof(int)*100*100);

    for ( i = 0 ; i < Y ; i ++ ) {
        int Cnt[101]={0,};
        vector<int> A;
        vector<pair<int, int>> B;

        for ( j = 0 ; j < X ; j ++ ) {
            if ( src[i][j] <= 0 ) continue;
            if ( Cnt[ src[i][j] ] <= 0 )
                A.push_back(src[i][j]);
            Cnt[ src[i][j] ] ++;
        }
        for (auto a: A)
            B.emplace_back(Cnt[a], a);
        sort(B.begin(), B.end());

        j = 0 ;
        for (auto [b, a]: B) {
            if ( j < 100 ) dest[i][j++] = a ;
            if ( j < 100 ) dest[i][j++] = b;
        }
        MaxCol = max( MaxCol, j);
    }
    X = MaxCol;
}

void OperC(int src[100][100], int dest[100][100]) {
    int i, j;
    int MaxRow = 0;
    memset(dest, 0, sizeof(int)*100*100);

    for ( j = 0 ; j < X ; j ++ ) {
        int Cnt[101]={0,};
        vector<int> A;
        vector<pair<int, int>> B;

        for ( i = 0 ; i < Y ; i ++ ) {
            if ( src[i][j] <= 0 ) continue;

            if ( Cnt[ src[i][j] ] <= 0 )
                A.push_back(src[i][j]);
            Cnt[ src[i][j] ] ++;
        }

        for (auto a: A)
            B.emplace_back(Cnt[a], a);
        sort(B.begin(), B.end());

        i = 0 ;
        for (auto [b, a]: B) {
            if ( i < 100 ) dest[i++][j] = a ;
            if ( i < 100 ) dest[i++][j] = b;
        }
        MaxRow = max( MaxRow, i);
    }
    Y = MaxRow;
}

void dump(int T[100][100]) {
    int i, j;
    int width = 1;

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cout << setw(width) << T[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int T[2][100][100];
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;
    int y, x, k;
    cin >> y >> x >> k ;
    y --; x --;

    Y = X = 3;
    for ( i = 0 ; i < 3 ; i ++ ) {
        for ( j = 0 ; j < 3 ; j ++ )
            cin >> T[0][i][j];
    }

    for ( i = 0 ; i <= 100 ; i ++ ) {
        if ( T[i%2][y][x] == k ) {
            cout << i << '\n';
            return 0;
        }
        memset(T[ 1 - (i%2) ], 0, sizeof(T[0]));
        ( Y >= X ) ? OperR(T[i%2], T[1 - (i%2)]) : OperC(T[i%2] , T[1 - (i%2)]);
    }
    cout << "-1\n";
    return 0;
}


