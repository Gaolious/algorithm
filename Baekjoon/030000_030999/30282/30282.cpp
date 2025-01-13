#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
struct Data {
    int no, s, e;
    bool operator < (Data &o) {
        return s != o.s ? s < o.s : e < o.e ;
    }
};
void process(int Case) {
    vector<Data> A[5];
    int i, j, n, sh, sm, eh, em, ans ;
    ans = 0 ;

    for ( i = 0 ; i < 10 ; i ++ ) {
        cin >> n >> sh >> sm >> eh >> em ;
        A[n-1].push_back({i+1, sh*60 + sm, eh*60 + em});
        ans += (eh*60 + em) - (sh*60 + sm);
    }

    pii wrong = {100, 100};

    for ( i = 0 ; i < 5 ; i ++ ) {
        std::sort(A[i].begin(), A[i].end());
        for ( j = 1 ; j < A[i].size() ; j ++ ) {
            if ( A[i][j-1].e > A[i][j].s ) {
                wrong = min(wrong, { min(A[i][j-1].no, A[i][j].no), max(A[i][j-1].no, A[i][j].no) });
            }
        }
    }
    if ( wrong.first != 100 ) {
        cout << "NE\n";
        cout << wrong.first << ' ' << wrong.second << '\n';
        return;
    }
    cout << "TAIP\n";
    cout << ans / 60 << ' ' << ans % 60 << '\n';
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
