#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
int C[10'001];
struct Data {
    string s;
    int x;
    int idx;
    bool operator <(Data &o) {
        if ( C[x] != C[o.x] ) return C[x] < C[o.x];
        if ( x != o.x ) return x < o.x ;
        return idx < o.idx ;
    }
};
void process(int Case) {
    int U, N, i ;
    cin >> U >> N;
    vector<Data> A(N);
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[i].s >> A[i].x ;
        A[i].idx = i;
        C[ A[i].x ] ++;
    }
    std::sort(A.begin(), A.end());
    cout << A[0].s << ' ' << A[0].x << '\n';
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
