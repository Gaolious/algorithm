#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ld PI = acos(-1);

void init(){
}
void process(int Case) {
    ld A1, P1, R1, P2;
    cin >> A1 >> P1 >> R1 >> P2 ;
    if ( A1/P1 < PI*R1*R1/P2 ) cout << "Whole";
    else cout << "Slice of" ;
    cout << " pizza\n";
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
