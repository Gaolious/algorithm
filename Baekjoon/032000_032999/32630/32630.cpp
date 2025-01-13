#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){}

const ll INF = 2e18;
void process(int Case) {
	int N, i;
	ll S=0, n;
	cin >> N;
	ll a1 = -INF, a2=-INF, b1=INF, b2=INF;
	for ( i = 0 ; i < N ; i ++ )
	{
		cin >> n ;
		S += n;
		if ( a1 < n ) a2=a1, a1=n;
		else if ( a2 < n ) a2=n;
		if ( b1 > n ) b2 = b1, b1=n;
		else if ( b2 > n ) b2 = n;
	}
	ll ans = max(0ll, max(a1*a2*2-a1-a2, b1*b2*2-b1-b2) );
	cout << S + ans << '\n';
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
