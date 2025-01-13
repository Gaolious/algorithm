#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}

const ld kg2pound = 2.2046l;
const ld liter2gallon = 0.2642l;

void process(int Case) {
	ld a;
	string b;
	cin >> a >> b;
	if ( b == "kg" ) cout << fixed << setprecision(4) << a * 2.2046 << " lb\n";
	else if ( b == "lb" ) cout << fixed << setprecision(4) << a * 0.4536 << " kg\n";
	else if ( b == "l" ) cout << fixed << setprecision(4) << a * 0.2642 << " g\n";
	else if ( b == "g" ) cout << fixed << setprecision(4) << a * 3.7854 << " l\n";
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
