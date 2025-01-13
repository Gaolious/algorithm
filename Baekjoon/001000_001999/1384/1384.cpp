#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
bool process(int Case) {
    int N, i, j ;
    char c;
    cin >> N ;
    if ( N == 0 ) return false;

    vector<string> A(N);
    vector<pii> B;

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[ i ] ;
        for ( j = 1 ; j < N ; j ++ ) {
            cin >> c ;
            if ( c == 'N' )
                B.emplace_back( (i - j + N) % N , i );
        }
    }
    if ( Case > 1 ) cout << '\n';
    cout << "Group " << Case << '\n';

    for ( auto [from, to] : B) {
        cout << A[from] << " was nasty about " << A[to] << '\n';
    }
    if ( B.empty() ) {
        cout << "Nobody was nasty\n";
    }
    return true;
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
	for ( int i=1 ; ; i ++ ) {
        if ( !process(i) ) break;
    }
    return 0;
}
