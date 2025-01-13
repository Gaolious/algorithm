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
struct Data {
    int W, D, P;
    bool operator < (Data &o) {
        return num() < o.num();
    }
    int num() {
        return W*7 + D;
    }
};
void process(int Case) {
    int i, N, M;
    string name;
    cin >> N ;
    unordered_map<string, Data> A;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> name;
        Data d = {};
        cin >> d.W >> d.D >> d.P ;
        A[name] = d;
    }
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> name >> M;
        if ( A.count(name) && A[name].P > M ) A.erase(name);
    }
    int cnt=0, ans=0;
    vector<int> D;
    for (auto &[_, d]: A) D.push_back(d.num());
    std::sort(D.begin(), D.end());
    D.erase(std::unique(D.begin(), D.end()), D.end());

    for ( i = 0 ; i < D.size() ; i ++ ) {
        if ( i == 0 ) cnt = 1;
        else {
            if ( D[i-1] + 1 == D[i] ) cnt ++;
            else cnt = 1;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
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
