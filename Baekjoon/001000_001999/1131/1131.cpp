#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T> pair<T,T> minxy(pair<T,T> a, pair<T,T> b) { return { min(a.first, b.first), min(a.second, b.second) }; }
template <typename T> pair<T,T> maxxy(pair<T,T> a, pair<T,T> b) { return { max(a.first, b.first), max(a.second, b.second) }; }
template <typename T> ll DIST2(pair<T,T>  a) {return a.first*a.first + a.second*a.second;}
template <typename T> ll DISTm(pair<T,T>  a) {return abs(a.first) + abs(a.second);}

void init(){
}
ll const MaxN = 3'188'646ll;
ll D[MaxN+1];
bool Visited[MaxN+1];
ll K;
ll P[10];
ll Pow(ll a, ll n) {
    if ( n == 0 ) return 1;
    auto ret = Pow(a, n/2);
    ret = ret * ret;
    if ( n % 2 == 1 ) ret *= a ;
    return ret;
}
ll F(ll N) {
    ll n, k, num;

    auto &ret = D[N];
    if ( ret < 0 ) {
        if ( Visited[N] ) {
            ret = N ;
            for ( ret = num = N, n = -1 ; n != N ; num = n) {
                for (n = 0, k = num; k > 0; k /= 10)
                    n += P[k%10];
                ret = min(ret, n);
            }
        }
        else {
            Visited[N] = true;
            for ( n = 0, k=N ; k > 0 ; k /=10 )
                n += P[k%10];
            ret = min(N, min(n, F(n)));
        }
    }
    return ret;
}

void process(int Case) {
    ll N, M;
    cin >> N >> M >> K ;

    memset(D, -1, sizeof(D));
    ll ans = 0 ;
    for (ll i = 0 ; i <= 9 ; i ++ )
        P[i] = Pow(i, K);

    for (ll i = N ; i <= M ; i ++ )
        ans += F(i);
    cout << ans <<'\n';
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
