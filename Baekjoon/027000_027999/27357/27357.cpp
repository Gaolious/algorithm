#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> pll;

ll ParseDollar(string &s){
    ll ret = 0 ;
    int i;
    for ( i = 0 ; i < s.size()  ; i ++ )
        if ( isdigit(s[i]) )
            ret = ret * 10 + (s[i]-'0');
    return ret;
}
pll getTax(ll tax, ll S) {
    ll ret = S * tax ;
    ll remain = ret % 100 ;
    if ( remain == 0 )
        return {S + ret/100, S+ret/100};
    else
        return {S + ret/100, S+ret/100+1};
}
ll lowerBound(ll S, ll X) {
    ll l = 0, r = 10000, m;
    ll ans;
    X *= 100l;
    while ( l <= r ) {
        m = ( l + r ) / 2 ;
        if ( getTax(m, S).second < X ) l = m  + 1;
        else r = m - 1, ans = m;
    }
    return ans;
}
ll upperBound(ll S, ll X) {
    ll l = 0, r = 10000, m;
    ll ans;
    X = (X+1) * 100;
    while ( l <= r ) {
        m = ( l + r ) / 2 ;
        if ( getTax(m, S).first < X ) l = m  + 1, ans = m;
        else r = m - 1;
    }
    return ans;
}
void process() {
    int T, i;
    ll N, X;
    char c;
    string s;
    ll S=0, l, r;
#define CD(a) (a)/100 << '.' << setw(2) << setfill('0') << (a)%100

    cin >> T ;
    while ( T -- ) {
        cin >> N >> X ;
        for (S=0, i = 0 ; i < N ; i ++ ) {
            cin >> s ;
            S += ParseDollar(s);
        }
        cout << lowerBound(S, X) << " " << upperBound(S, X) << '\n';
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


