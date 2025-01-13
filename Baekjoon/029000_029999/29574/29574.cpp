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
struct Data{
    string s;
    int idx, order;
};
void process(int Case) {
    vector<Data> A(10);
    int i;
    for ( i = 0 ; i < 10 ; i ++ ) {
        cin >> A[i].s;
        A[i].idx = A[i].order = i ;
    }

    std::sort(A.begin(), A.end(), [](Data &a, Data &b) { return a.s < b.s ;});
    for ( i = 0 ; i < 10 ; i ++ )
        A[i].order = i ;
    std::sort(A.begin(), A.end(), [](Data &a, Data &b) { return a.idx < b.idx ;});

    int N, idx ;
    string s;
    cin >> N ;
    while ( N -- ) {
        cin >> s;
        idx = -1 ;
        for (i = 0 ; i < s.size() ; i ++ )
            if ( idx < 0 || A[idx].order < A[ s[i]-'0' ].order) idx = s[i]-'0';
        cout << A[idx].s << '\n';
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
