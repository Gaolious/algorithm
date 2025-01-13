#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

void init(){
}
bool operator < (pll a, pll b) { return a.first * b.second < a.second * b.first;}
bool operator <= (pll a, pll b) { return a.first * b.second <= a.second * b.first;}
bool operator >= (pll a, pll b) { return a.first * b.second >= a.second * b.first;}
bool operator > (pll a, pll b) { return a.first * b.second > a.second * b.first;}
bool operator == (pll a, pll b) { return a.first * b.second == a.second * b.first;}

void process(int Case) {
    pll A, B, C;
    char a,b, _;
    cin >> A.first >> _ >> A.second;
    cin >> a >> _ >> B.second;
    cin >> C.first >> _ >> C.second;

    B.first = A.first * B.second / A.second;
    while ( A >= B && B < C) B.first ++;
    if ( A < B && B < C )
        cout << B.first << '/' << B.second << '\n';
    else
        cout << "-1\n";
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
