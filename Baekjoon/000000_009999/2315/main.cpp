#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MaxN 1000
struct DATA {
    int p;
    ll w ;
};

DATA A[MaxN];
int N, M ;
ll D[MaxN][MaxN];

ll F(int l, int r) {

}
int main()
{
    fastio;
    int i ;

    cin >> N >> M ;
    for ( i = 0 ; i < N ; i ++ )
        cin >> A[i].p >> A[i].w ;
    memset( D, -1, sizeof(D) );

    cout << F(0, N-1) << '\n';
    return 0;
}


