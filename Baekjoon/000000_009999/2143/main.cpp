#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
ll A[1'001]={0,};
ll B[1'001]={0,};

void process() {
    fastio;
    ll T, t ;
    int N, M ;
    int i, j;
    unordered_map<ll,ll> mA, mB;
    cin >> T ;

    cin >> N ;
    for ( i = 1, t = 0 ; i <= N ; i ++) {
        cin >> A[ i ] ;
        A[ i ] += t ;
        t = A[i];
    }
    cin >> M ;
    for ( i = 1, t = 0 ; i <= M ; i ++ ) {
        cin >> B[ i ] ;
        B[ i ] += t ;
        t = B[i];
    }

    for (i = 1 ; i <= N ; i ++)
        for ( j=1 ; j <= i ; j ++ )
            mA[ A[i] - A[j-1] ] ++;
    for (i = 1 ; i <= M ; i ++)
        for ( j=1 ; j <= i ; j ++ )
            mB[ B[i] - B[j-1] ] ++;

    ll ret = 0 ;
    for ( auto a : mA )
        ret += a.second * mB[ T - a.first ] ;

    cout << ret << endl ;
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


