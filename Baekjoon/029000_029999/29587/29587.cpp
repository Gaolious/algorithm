#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int N;
    int i;
    cin >> N ;
    vector<int> A(N);
    for (auto &n: A) cin >> n ;
    bool f = false;
    for ( i = 0; i < N-1  ; i ++ )
        f = f || (A[i] >= A[i+1]);
    if ( f ) {
        cout << N << '\n';
        for ( i = 0; i < N ; i ++ ) cout << i + 1 << ' ';
    }
    else
        cout << 0;
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
