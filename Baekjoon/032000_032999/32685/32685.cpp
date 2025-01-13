#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
	ll n, ans = 0;
	for (int i = 0 ; i < 3 ; i ++)
	{
		cin >> n;
		ans = (ans << 4 ) | (n & 0xF);
	}
	cout << setw(4) << setfill('0') << ans << '\n';
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
