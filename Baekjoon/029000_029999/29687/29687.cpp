#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
struct Data {
    ll g, x, y;
};

Data eGCD(ll a, ll b) {
    if ( a == 0 ) return { b, 0, 1 };
    auto ret = eGCD(b%a, a);
    return { ret.g, ret.y - b/a * ret.x , ret.x };
}
ll invMod(ll a, ll m) {
    auto ret = eGCD(a, m);
    if ( ret.g != 1 ) {
        // not exist.
    }
    return (ret.x%m + m) % m;
}
void process(int Case) {
    // a=3 m=7
    // a * b % m = 1
    ll a, m;
    cin >> a >> m ;
    cout << invMod(a, m);
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
