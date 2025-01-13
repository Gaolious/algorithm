#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);

void process()
{
    int N ;
    int A[100000+1];
    long long int res, minimum, c;

    int i, j ;
    cin >> N ;
    for ( A[0] = 0, i = 1 ; i < N ; i ++)
        cin >> A[i];

    minimum = 0 ;
    res = 0 ;
    for ( i = 0 ; i < N ; i ++ )
    {
        cin >> c ;
        res += minimum * A[ i ] ;
        if ( minimum <= 0 || minimum > c )
            minimum = c ;
    }
    cout << res ;
}


int main()
{
    fastio;
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin );
    freopen("output.txt", "wt", stdout );
#endif
    process();
    return 0;
}
