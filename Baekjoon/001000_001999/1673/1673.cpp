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
void process(int Case) {
    int N, K, ans, stamp;
    while ( cin >> N >> K ) {
        ans = 0 ;
        stamp = 0;
        while(N > 0 ) {
            ans += N;
            stamp += N ;
//            cout << "쿠폰 " << N << "장 으로 치킨 " << N << "마리 주문 / 받은 도장 " << stamp << "개, 지금까지 먹은 치킨 = " << ans << '\n';
            N = stamp / K ;
//            if ( stamp / K > 0 ) {
//                cout << "\t도장과 쿠폰 교환 : 도장:" << -N*K << " => 쿠폰: +" << N << '\n';
//            }
            stamp %= K;
//            cout << "\t남은 쿠폰 " << N << "장, 남은 도장 " << stamp << "개\n";
        }
        cout << ans << '\n';
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
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
