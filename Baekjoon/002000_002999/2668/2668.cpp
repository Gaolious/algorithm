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
int N ;
bool Cycle[100];
bool Visited[100];
vector<int> A;
vector<int> Ans;
bool F(int curr, int s) {
    if ( Visited[curr] ) return curr == s;
    Visited[curr] = true;
    auto ret = F(A[curr], s);
    if ( ret ) Cycle[curr] = true;
    return ret;
}
void process(int Case) {
    int i;
    cin >> N ;
    A.resize(N);
    for (auto &n: A) {
        cin >> n; n --;
    }
    for ( i = 0 ; i < N ; i ++ ) {
        memset(Visited, 0, sizeof(Visited));
        F(i, i);
    }
    vector<int> ans;
    for ( i = 0 ; i < N ; i ++ ) {
        if ( Cycle[i] ) ans.push_back(i+1);
    }
    cout << ans.size() << '\n';
    for (auto n: ans) cout << n << '\n';
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
