#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int n, N, P, i;
    cin >> N >> P ;
    vector<int> A(max(N+1, P+1), -1);
    for ( n = N, i=0 ; A[n] < 0 ; n = (n*N)%P) {
        A[n] = i++;
    }
    cout << i - A[n] << '\n';
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
