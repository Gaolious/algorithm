#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int Y, X, f, no, s, e, i, j, ans;
    cin >> Y >> X ;
    vector<string> A(Y);
    cin.ignore();
    for ( auto &s: A) cin >> s;
    vector<pii> C;

    for (auto &L: A) {
        s = X+1, e = -1, no = -1, f = -1;
        for ( i = 0 ; i < L.size() ; i ++ ) {
            if (L[i] == 'F') f = i;
            if ('0' <= L[i] && L[i] <= '9') {
                s = min(i, s);
                e = max(i, e);
                no = L[i] - '0';
            }
        }
        if ( no > 0 )
            C.emplace_back( min( abs(f-s), abs(f-e) ), no );
    }

    std::sort(C.begin(), C.end());
    vector<int> Rank(10);
    int r = 1;
    Rank[ C[0].second ] = 1;
    for ( i = 1 ; i < 10 ; i ++ ) {
        if ( C[i-1].first != C[i].first ) r++;
        Rank[ C[i].second ] = r ;
    }
    for ( i = 1 ; i < 10 ; i ++ )
        cout << Rank[ i ] << '\n';
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
