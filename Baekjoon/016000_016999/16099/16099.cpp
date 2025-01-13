#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    ll w1, h1, w2, h2, s1, s2;
    cin >> w1 >> h1 >> w2 >> h2 ;
    s1 = w1*h1;
    s2 = w2*h2;
    if ( s1 > s2 ) cout << "TelecomParisTech\n";
    else if ( s1 < s2 ) cout << "Eurecom\n";
    else cout << "Tie\n";
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
