#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void P(ll n)
{
	if ( n%3 == 0 ) cout << "Fizz";
	if ( n%5 == 0 ) cout << "Buzz";
	if ( n%3 != 0 && n%5 != 0 ) cout<< n ;
}
void process(int Case) {
	string s;
	for ( int i = 0 ; i < 3 ; i ++ )
	{
		cin >> s ;
		if ( '0' <= s[0] && s[0] <= '9' )
		{
			ll n = atoi(s.c_str());
			P(n + (3-i));
			return;
		}
	}
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
