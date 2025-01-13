#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ld, ld> pdd;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> T DIST2(pair<T,T>  a) {return a.first*a.first + a.second*a.second;}
const ld EPS = 1.0e-12;
void init(){
}
void process(int Case) {
    int s[2]={0,}, i, j, k, d;
    ld x, y;
    for ( j = 0 ; j < 2 ; j ++ ) {
        for (i = 0; i < 3; i++) {
            cin >> x >> y;
            d = min(5, max(0, (int)ceil( sqrt(x*x+y*y)/3 ) - 1) );
            s[j] += 100 - d*20;
        }
    }
    cout << "SCORE: " << s[0] << " to " << s[1] << ", ";
    if ( s[0] == s[1] ) cout << "TIE.\n";
    else {
        cout << "PLAYER " << ( s[0] > s[1] ? 1 : 2 )  << " WINS.\n";
    }
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
