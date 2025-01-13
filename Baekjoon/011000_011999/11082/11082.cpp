#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
ll P10[18+1];
struct Fraction {
	ll a, b ;
	Fraction(ll v) { a=v, b = 1; }
	Fraction(ll q, ll w) { a=q, b=w; }
	Fraction &simplify() { ll g = gcd(a,b); a /= g, b /= g; if ( b < 0 ) a *= -1, b *= -1; return *this; }
	Fraction operator + (Fraction o) const { ll g = gcd(b, o.b); Fraction ret = {a*o.b/g + b * o.a/g, b / g * o.b}; return ret.simplify(); }
};
ll parseDigit(string &a, int &idx, int &len)
{
	ll ret;
	for( len = ret = 0 ; idx < a.size() && '0' <= a[idx] && a[idx] <= '9' ; idx++, len++)
		ret = ret * 10 + a[idx] - '0';
	return ret;
}
void process(int Case) {
	string s;
	ll a, b, c;
	int lenA=0, lenB=0, lenC=0;
	int idx = 0;
	P10[1]=1;
	for ( int i = 2 ; i <= 18 ; i ++ ) P10[i] = P10[i-1] * 10;
	cin >> s ;
	a = parseDigit(s,idx, lenA);
	if ( idx < s.size() && s[idx] == '.' )
	{
		idx++;
		if ( s[idx] != '(' ) b = parseDigit(s,idx, lenB);
		if ( s[idx] == '(' ) c = parseDigit(s,++idx, lenC);
	}

	Fraction ans = Fraction( a );
	if ( lenB > 0 ) ans = ans + Fraction( b, P10[lenB+1] );
	if ( lenC > 0 ) ans = ans + Fraction( c, (P10[lenC+1]-1)*P10[lenB+1] );
	cout << ans.a << '/' << ans.b << endl;
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
