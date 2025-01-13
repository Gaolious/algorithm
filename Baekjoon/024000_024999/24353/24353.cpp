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
    // 첫 번째 책 N1의 번호는 해당 월의 숫자 (1, 2, ..., 12)에 10을 더한 값입니다.
    //두 번째 책 N2의 번호는 라초가 생각한 숫자 s입니다.
    //세 번째 책 N3의 번호는 나머지 책 중에서 선택되며, 이 번호는 한 자리 수가 아니어야 하고 어떤 월의 숫자에 10을 더한 값이어서는 안 됩니다.
    //N1, N2, N3의 숫자를 연속해서 적어 만든 다섯 자리 수가 N1, N2, N3 중 두 수의 합으로 나누어져야 합니다.
    ll N, S, M ;
    ll N1, N2, N3;
    ll month;
    ll ans = -1;

    cin >> N >> S >> M ;

    vector<ll> Month(13, 0);
    for ( month = 1 ; month<=12 ; month ++ ) {
        N1 = month + 10;
        N2 = S;
        for ( N3 = 10 ; N3 <= N ; N3 ++ ) {
            if ( 11 <= N3 && N3 <= 22 ) continue;
            if ( N3 == N1 || N3 == N2 ) continue;

            ll s = N1 * 1000 + N2*100 + (N3%100) ;
            if ( s % (N1 + N2) == 0 || s % (N1 + N3) == 0 || s % (N2+N3) == 0 ) {
                Month[month]++;
                if ( M == month ) {
                    if (ans < 0 || ans > N3)
                        ans = N3;
                }
            }
        }
    }
    for ( month = 1 ; month <= 12 ; month ++ )
        cout << Month[month] << '\n';

    if ( ans < 0 )
        cout << "0 0 0\n";
    else
        cout << M+10 << ' ' << S << ' ' << ans << '\n';
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
