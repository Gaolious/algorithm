#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int N, W, H ;
    cin >> N >> W >> H ;
    vector<string> A((N+1)*H);
    for (auto &s: A) cin >> s ;
    int ans = -1, maxC=-1, c;
    int i, j, k;
    for ( i = 0 ; i < N ; i ++ ) {
        c = 0;
        for ( j = 0 ; j < H ; j ++ )
            for ( k = 0 ; k < W ; k ++ )
                if ( A[i*H+j][k] == A[N*H+j][k]) c++;
        if ( maxC < c ) {
            maxC = c ;
            ans = i + 1 ;
        }
    }
    cout << ans << '\n';
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
