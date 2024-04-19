#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll D[100][10][10]={0,};
char A[101], B[101];
ll N ;
const ll INF = 100000000;
const int _[] = { 0, 1, 1, 1, 2, 2, 2, 1, 1, 1};
#define R(x) ( (100+(x))%10 )
#define C(x) ( _[R(x)] )

ll F(int nth, int s1, int s2) {
    if ( nth >= N ) return 0;

    ll &ret = D[nth][s1][s2] ;

    if ( ret < 0 ) {
        ret = INF;
        int d1, d2 ;
        for ( d1 = 0 ; d1 < 10 ; d1 ++ ) {
            for (d2 = 0; d2 < 10 ; d2++) {
                ll spin = C(A[nth] + s1 + d1 + d2) + C(d1) + C(d2);
                if (spin > 2) continue;
                ret = min(ret, F(nth + 1, R(s2 + d1 + d2), R(d2) ) + spin);
            }
        }
    }

    return ret;
}
int main()
{
    fastio;
    int i;

    cin >> N >> A >> B ;
    for ( i = 0 ; i < N ; i ++ )
    {
        A[i] -= B[i];
    }

    memset(D, -1, sizeof(D));

    cout << F(0, 0, 0) << '\n';
    return 0;
}


