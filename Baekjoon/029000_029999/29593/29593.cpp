#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
ll L[46];
ll C[46];

ll F(ll N, ll kth) {
    if ( kth == L[N]) return C[N];
    if ( kth <= L[N-2] )
        return F(N-2, kth);
    else
        return F(N-2, L[N-2]) + F(N-1, kth-L[N-2]);
}
void process(int Case) {
    int i ;
    L[0] = L[1] = 1;
    C[0] = 1, C[1] = 0;
    for(i=2 ; i <= 45 ; i ++ ) {
        L[i] = L[i - 2] + L[i - 1];
        C[i] = C[i - 2] + C[i - 1];
    }

    int N ;
    cin >> N ;
    while ( N -- ) {
        ll n, kth;
        cin >> n >> kth ;
        cout << F(n, kth) << '\n';
    }

}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int T=1;
    init();
    // cin >> T;
    for ( int i=1 ; i <= T ; i ++ )
        process(i);
    return 0;
}
