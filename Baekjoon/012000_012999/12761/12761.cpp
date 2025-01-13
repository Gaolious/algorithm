#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    ll A, B, N, M;
    cin >> A >> B >> N >> M ;
    vector<ll> D(100'000+1, -1);
    queue<ll> Q;

    D[N] = 0;
    Q.push(N);
    while ( !Q.empty() ) {
        auto curr = Q.front();
        Q.pop();
        for ( auto t : {-1ll, 1ll, A, B, -A, -B, curr*A-curr, curr*B-curr} ) {
            if ( t + curr < 0 || t + curr > 100'000 ) continue;
            if ( D[t+curr] < 0 || D[t+curr] > D[curr] + 1 ) {
                D[t+curr] = D[curr] + 1;
                Q.push(t+curr);
            }
        }
    }
    cout << D[M] << '\n';
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
