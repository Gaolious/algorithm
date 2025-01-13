#include <bits/stdc++.h>
using namespace std;

void init(){}
void process(int Case) {
    int N, S, D, ans=0;
    int d, v;
    cin >> N >> S >> D ;
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> d >> v ; // 거리, 값
        if ( d <= D*S ) ans += v;
    }
    cout << "Data Set " << Case << ":\n" << ans << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ ) {
        if ( i>1) cout << '\n';
        process(i);
    }
    return 0;
}
