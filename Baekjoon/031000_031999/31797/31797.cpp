#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}

void init() {}
void process(int Case) {
    int N, M, i, h1, h2;
    cin >> N >> M ;
    vector<pii> D;
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> h1 >> h2 ;
        D.emplace_back(h1, i+1);
        D.emplace_back(h2, i+1);
    }
    std::sort(D.begin(), D.end(), less<>());
#ifdef AJAVA_DEBUG
    for (auto [x,y]: D) cout << x << ' ' << y << '\n';
#endif
    M*=2;
    N = (N-1) % M ;
    cout << D[N].second;
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
