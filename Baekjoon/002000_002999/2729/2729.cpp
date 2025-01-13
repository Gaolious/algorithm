#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    string a, b, c;
    int i, j, v;
    bool carry=false;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for ( i = j = 0 ; i < a.size() || j < b.size() || carry ; i++, j++) {
        v = carry ? 1 : 0;
        v += ( i < a.size() ? a[i]-'0' : 0);
        v += ( j < b.size() ? b[i]-'0' : 0);
        carry = v >= 2;
        c.push_back((v % 2) + '0');
    }
    while ( c.size() > 1 && c.back() =='0' ) c.pop_back();

    reverse(c.begin(), c.end());
    cout << c << '\n';
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
