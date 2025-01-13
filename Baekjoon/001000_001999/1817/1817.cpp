#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, M, b, i;
    vector<int> A;
    cin >> N >> M ;

    for ( i = 0; i < N ; i ++ ) {
        cin >> b ;
        if ( A.empty() || A.back() + b > M ) {
            A.emplace_back(b);
        }
        else A.back() += b;
    }
    cout << A.size();
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
