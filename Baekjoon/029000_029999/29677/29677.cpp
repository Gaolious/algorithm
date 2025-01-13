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
const ld EPS = 1.0e-18;
int R( int ra, int rb, int score) {
    if ( score == 1 ) score = 2;
    else if ( score == 2 ) score = 0;
    else score = 1;
    ld ea = 1.0 / ( 1.0 + pow(10, (rb-ra) / 400.0) );
    ld ret = ra + 15.0 * ( score/2.0 - ea );
    if ( ret < 0 ) ret = 0;
    return (int)( ret + EPS);
}
struct Data {
    string s;
    int r;
};
void process(int Case) {
    int N ;
    int r, w, ra, rb;
    vector<Data> A;
    unordered_map<string, int> Idx;
    string s, d;
    int i, idxa, idxb;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        auto &data = A.emplace_back();
        cin >> data.r >> data.s ;
        Idx[data.s] = i;
    }

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> s >> d >> w ;
        idxa = Idx[s];
        idxb = Idx[d];
        ra = R( A[idxa].r, A[idxb].r, w );
        if ( w != 0 ) w = 3 - w;
        rb = R( A[idxb].r, A[idxa].r, w);
        A[idxa].r = ra;
        A[idxb].r = rb;
    }
    std::sort(A.begin(), A.end(), [](Data &a, Data &b){
        return a.r != b.r ? a.r > b.r : a.s < b.s;
    });
    for (auto &a: A) {
        cout << a.r << ' ' << a.s << '\n';
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
