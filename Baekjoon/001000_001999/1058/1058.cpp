#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[51][51];
int C[51]{};

int main()
{
    int N, i, j, k, ret;
    bool is_friend;
    string s ;
    fastio;
    cin >> N ;

    for ( i = 0 ; i < N ; i ++ ) {
        cin >>s ;
        for ( j = 0 ; j < N ; j ++ ) {
            if ( s[j] == 'Y' ) A[i][j] = 1;
        }
    }
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = i+1 ; j < N ; j ++ ) {
            is_friend = false ;

            if ( A[i][j] )
                is_friend = true ;

            for ( k = 0 ; k < N && !is_friend; k ++ )
                if ( A[i][k] && A[k][j] )
                    is_friend = true;

            if ( is_friend) {
                C[i] ++;
                C[j] ++;
            }
        }
    }
    for ( ret=0, i = 0 ; i < N ; i ++ )
        ret = max(ret, C[i]);
    cout << ret << '\n';
    return 0;
}


