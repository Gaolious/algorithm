#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}

void init(){
}
void process(int Case) {
    int i;
    ld X, Y, D, T, remain;
    ld ans = -1, t;
    cin >> X >> Y >> D >> T;
    ld d = sqrt(X*X+Y*Y);
    for (i = 0 ; i <= 1 ; i ++ )
        if ( ans < 0 || abs(D*i-d) + T*i < ans )
            ans = abs(D*i-d) + T*i;

    for (i = 2 ; i <= 1420 ; i ++ ) {
        remain = max(0.0l, d-D*i);
        ans = min(ans, i*T + remain);
        if ( remain <= 0 ) break;
    }
    cout << setprecision(18) << fixed << ans ;

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
