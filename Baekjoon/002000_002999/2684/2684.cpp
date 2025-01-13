#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int i, n, A[8]={0,};
    string s;
    cin >> s ;
    for ( n = i = 0 ; i < s.size() ; i ++ ) {
        n = n%4 * 2 + (s[i] == 'H' ? 1 : 0);
        if ( i>=2 ) A[n]++;
    }
    for ( auto n: A)
        cout << n << ' ';
    cout << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
