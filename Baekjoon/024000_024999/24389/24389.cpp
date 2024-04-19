#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    ll N ;
    int i, cnt ;
    cin >> N ;

    N = N ^ (-N);
    for ( cnt = 0, i = 0 ; i <32 ; i ++ ) {
        if ( N & ( 1ll << i ) )
            cnt ++;
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


