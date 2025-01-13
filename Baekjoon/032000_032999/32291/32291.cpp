#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){}
void process(int Case) {
	ll x, y;
	cin >> x;
	y = x + 1;
	vector<ll> A;
	auto push = [&x, &A](ll n)
	{
		if ( n <= x ) A.push_back(n);
	};
	for ( ll i = 1 ; i*i <= y ; i++ )
	{
		if ( y % i == 0 ) push(i), push(y/i);
	}
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());

	for (auto n: A)
		if ( x / n != y / n )
			cout << n << ' ';
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
