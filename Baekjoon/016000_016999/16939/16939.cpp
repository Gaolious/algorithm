#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int Color[100];
int Rotate[][8] = {
    {1,2,18,20,12,11,15,13},
    {3,4,17,19,10,9,16,14},
    {1,3,5,7,9,11,24,22},
    {2,4,6,8,10,12,23,21},
    {13, 14, 5, 6, 17, 18, 21, 22},
    {15, 16, 7, 9, 19, 20, 23, 24},
};
bool R(int idx) {
    int C[100];
    int i ;

    for ( i = 0 ; i < 24 ; i ++ ) C[i] = Color[i];

    for ( i = 0 ; i < 8 ; i += 2 ) {
        C[ Rotate[idx][ ( i + 8) % 8 ] - 1 ] = Color[ Rotate[idx][ ( i + 2 + 8) % 8 ] - 1 ];
        C[ Rotate[idx][ ( i + 1 + 8) % 8 ] - 1 ] = Color[ Rotate[idx][ ( i + 3 + 8) % 8 ] - 1 ];
    }
    // for ( i = 0 ; i < 24 ; i ++ ) cout << setw(2) << C[i] << ' ' ;
    // cout << '\n';

    for ( i = 0 ; i < 24 ; i += 4 ) {
        if ( !(C[i] == C[i+1] && C[i] == C[i+2] && C[i] == C[i+3] ))
            return false;
    }
    return true;
}
bool L(int idx) {
    int C[100];
    int i ;

    for ( i = 0 ; i < 24 ; i ++ ) C[i] = Color[i];

    for ( i = 0 ; i < 8 ; i += 2 ) {
        C[ Rotate[idx][ ( i + 8) % 8 ] - 1 ] = Color[ Rotate[idx][ ( i - 2 + 8) % 8 ] - 1 ];
        C[ Rotate[idx][ ( i - 1 + 8) % 8 ] - 1 ] = Color[ Rotate[idx][ ( i - 3 + 8) % 8 ] - 1 ];
    }
    // for ( i = 0 ; i < 24 ; i ++ ) cout << setw(2) << C[i] << ' ' ;
    // cout << '\n';

    for ( i = 0 ; i < 24 ; i += 4 ) {
        if ( !(C[i] == C[i+1] && C[i] == C[i+2] && C[i] == C[i+3] ))
            return false;
    }
    return true;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;
    for ( i = 0 ; i < 24 ; i ++ )
        cin >> Color[i];

    // for ( i = 0 ; i < 24 ; i ++ ) cout << setw(2) << i +1 << ' ' ;
    // cout << '\n';

    for ( i = 0 ; i < 6 ; i ++ )
        if ( R(i) || L(i) ) {
            cout << "1\n";
            return 0;
        }
    cout << "0\n";
    return 0;
}


