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
//ll Pow(ll a, ll n, ll m) {
//    if ( n == 0 ) return 1%m;
//    auto ret = Pow(a,n/2, m);
//    ret = (ret*ret)%m;
//    if (n%2) ret=(ret*a)%m;
//    return ret;
//}
//bool is(ll n){
//    ll a = 1;
//    for ( int i = 2 ; i <= 6 ; i ++ )
//        a += Pow(i, n, n) % n;
//    return a%n == 0;
//}
int A[] = {1,3,7,9,21,27,49,63,77,81,147,189,243,297,343,369,441,567,729,903,1029,1323,1617,1631,1701,2009,2037,2043,2187,2401,2597,2709,3087,3969,5103,6237,6321,6561,7203,8001,8127,9261,10209,11907,13203,15309,15477,16659,16807,18963,19341,19683,21609,24003,24057,24381,27783,29889,33957,35721,37931,38829,39447,39609,44247,44247};
void process(int Case) {
    int N;
    cin >> N ;
    cout << A[N-1];
//    N = 65;
//    for ( int i = 1 ; ; i ++ ) {
//        if ( is(i) ) {
//            cout << i << ",";
//            if ( ++cnt == N ) {
//                cout << i << '\n';
//                return;
//            }
//        }
//    }
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
