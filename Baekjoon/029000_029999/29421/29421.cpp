#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int N, G, R;
    int i, remain ;
    ll ans;
    cin >> N >> G >> R;
    vector<ll> A(N);
    for (auto &n : A) cin >> n ;

    for (i=ans=0 ; i < N ; )
    {
        for (remain = G; i < N && A[i] <= remain ; i ++ )
        {
            ans += A[i];
            remain -= A[i];
        }
        if (i != N) ans += (remain + R);
    }
    cout << ans << '\n';
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
