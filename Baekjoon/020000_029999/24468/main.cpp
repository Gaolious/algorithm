#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int LEFT = 1 ;
const int RIGHT = 2 ;
//
// +----+----+----+----+----+----+----
//      >
// +----+----+----+----+----+----+----
//           <    <    <
//
// +----+----+----+----+----+----+----
//        <
// +----+----+----+----+----+----+----
//         >   <    <
// +----+----+----+----+----+----+----
//      <
// +----+----+----+----+----+----+----
//           <>   <

void process() {
    fastio;
    int L, N, T ;
    int i, j, k;
    char c ;
    int cnt = 0, idx ;
    const int MaxL = 2000;
    int Line[2][MaxL+10]={0,};

    cin >> L >> N >> T ;

    L *= 2 ;
    T *= 2 ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> j >> c ;
        Line[0][ j * 2 ] |= (c == 'L') ? LEFT : RIGHT;
    }

    for ( idx = 0, i = 0 ; i < T ; i ++ ) {
        memset( Line[ 1 - idx ], 0, sizeof(Line[1-idx]));

        for ( j = 0 ; j <= L ; j ++ ) {
            if ( Line[idx][j] & LEFT )
            {
                k = j - 1 ;
                Line[1-idx][k] |= ( k == 0 ) ? RIGHT : LEFT;
            }
            if ( Line[idx][j] & RIGHT )
            {
                k = j + 1 ;
                Line[1-idx][k] |= ( k == L ) ? LEFT : RIGHT;
            }
        }
        idx = 1 - idx;
        for ( j = 0 ; j <= L ; j ++ ) {
            if( Line[idx][j] == (LEFT | RIGHT) ) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


