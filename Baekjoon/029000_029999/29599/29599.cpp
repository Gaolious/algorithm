#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, ld> pld;
template <typename A, typename B> istream &operator >>(istream &in, pair<A,B> &a) {in >> a.first >> a.second; return in;}

void init(){
}
void process(int Case) {
    int N, M;
    int from, to, K;
    cin >> N;
    vector<pld> A(N); // 부피, 농도
    for (auto &a: A)
        cin >> a;

    cin >> M;
    while ( M -- ) {
        cin >> from >> to >> K ;
        from--; to--;
        A[to] = { A[to].first + K, (K * A[from].second  + A[to].first*A[to].second)/ (A[to].first + K) };
        A[from].first -= K;
        if ( A[from].first == 0 ) A[from].second = 0;
    }
    cout << A.size() << '\n';
    for (auto [x,y]: A)
        cout << x << ' ' << setprecision(12) << fixed << y << '\n';
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
