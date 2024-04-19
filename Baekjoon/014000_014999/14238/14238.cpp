#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
char D[51][51][51][3][2];

bool F(int len, int b, int c, int ccc, int bb) {
    int a ;
    if ( b+c > len ) return false;
    if ( len == 0 ) return b+c == 0;

    ccc = max(0, ccc);
    bb = max(0, bb);

    auto &ret = D[len][b][c][ccc][bb];
    if ( ret < 0) {
        a = len - b - c;
        if ( !ccc && c > 0 ) {
            ret = 'C';
            if ( F(len-1, b, c-1, 2, bb-1) )
                return true;
            ret = 0;
        }
        if ( !bb && b > 0 ) {
            ret = 'B';
            if ( F(len-1, b-1, c, ccc-1, 1) )
                return true;
            ret = 0;
        }
        if ( a ) {
            ret = 'A';
            if ( F(len-1, b, c, ccc-1, bb-1) )
                return true ;
            ret = 0;
        }
    }

    return ret >= 'A' ;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int A, B, C;

    string s ;
    cin >> s ;

    A = B = C = 0 ;

    for (auto c: s) {
        if ( c == 'A' ) A++;
        else if ( c == 'B' ) B++;
        else if ( c == 'C' ) C++;
    }
    memset(D, -1, sizeof(D));

    F(A+B+C, B, C, 0, 0);

    int ccc = 0, bb = 0;

    if ( D[A+B+C][B][C][ccc][bb] >= 'A' ) {
        for ( int i = A+B+C ; i > 0 ; i -- ) {
            if ( D[i][B][C][ccc][bb] == 'A' ) {
                cout << 'A'; A--;
            }
            else if ( D[i][B][C][ccc][bb] == 'B' ) {
                cout << 'B'; B--; bb = 2;
            }
            else if ( D[i][B][C][ccc][bb] == 'C' ) {
                cout << 'C'; C--; ccc = 3;
            }
            ccc = max(0, ccc-1);
            bb = max(0, bb-1);
        }
    }
    else {
        cout << "-1\n";
    }
    return 0;
}


