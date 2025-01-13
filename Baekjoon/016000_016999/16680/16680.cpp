#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void process(int Case) {
	ll N, digit ;
	cin >> N ;
	for ( digit=9 ; digit < N ; digit = digit*100+99);
	cout << N * digit  << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
