#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

#define MaxN (100'000)

const int MOD = 1'000'000'009;
int D[ MaxN + 1][4];

void process() {
    int i, N, n, ans ;

    // 초기값
    D[1][1] = 1; // 마지막 수가 1일 때 정수 1을 표현하는 방법 수
    D[2][2] = 1; // 마지막 수가 2일 때 정수 2을 표현하는 방법 수
    D[3][3] = 1; // 마지막 수가 3일 때 정수 3을 표현하는 방법 수

    for ( i = 1 ; i <= MaxN ; i ++ ) {
        if ( i > 1 ) D[ i ][ 1 ] = ( D[ i - 1 ][ 2 ] + D[ i - 1 ][ 3 ] ) % MOD ;
        if ( i > 2 ) D[ i ][ 2 ] = ( D[ i - 2 ][ 1 ] + D[ i - 2 ][ 3 ] ) % MOD ;
        if ( i > 3 ) D[ i ][ 3 ] = ( D[ i - 3 ][ 1 ] + D[ i - 3 ][ 2 ] ) % MOD ;
    }
    cin >> N ;

    while ( N -- ) {
        cin >> n ;
        for (ans = 0, i = 1 ; i <= 3 ; i ++ )
            ans = (ans + D[ n ][ i ] ) % MOD;
        cout << ans << '\n';
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


