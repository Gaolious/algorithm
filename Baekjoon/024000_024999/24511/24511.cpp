#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

void init(){
}
void process(int Case) {
    int N, n, i ;
    cin >> N;

    vector<int> Type(N);
    deque<int> Q;
    for (auto &n: Type) cin >> n ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> n ;
        if ( !Type[ i ] ) Q.push_back(n);
    }

    cin >> N ;
    while ( N -- ) {
        cin >> n;
        Q.push_front(n);
        cout << Q.back() << ' ';
        Q.pop_back();
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
