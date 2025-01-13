#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, i;

    cin >> N ;
    vector<int> A(N+1);
    for ( i = 0 ; i < N ; i ++ ) {
        int n;
        cin >> n ;
        A[n]++;
    }
    for ( i = N ; i >= 0 ; i -- ) {
        if ( A[i] == i ) {
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
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
