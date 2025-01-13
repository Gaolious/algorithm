#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
vector<bool> ok(11, true);
vector<bool> has(11, false);
int N, S, R;
int F(int idx) {
    if ( idx > N )
        return 0;

    int ret = 0 ;

    ret = max(ret, F(idx+1) + ok[idx]);

    for ( int i = -1 ; i <= 1 ; i ++ ) {
        if ( idx + i > N || idx + i < 1 || !has[idx+i]) continue;
        has[idx+i] = false;
        ret = max(ret, F(idx+1) + 1);
        has[idx+i] = true;
    }
//    cout << idx << " : " << ret << '\n';
    return ret;
}
void process(int Case) {
    int n, i;

    cin >> N >> S >> R ;
    ok.resize(N+1, true);
    has.resize(N+1, false);
    for (i = 0 ; i < S ; i ++ ) {
        cin >> n ;
        ok[n] = false;
    }
    for (i = 0 ; i < R ; i ++ ) {
        cin >> n ;
        has[n] = true;
        if ( ok[n] == false ) {
            has[n] = false;
            ok[n] = true;
        }
    }
    cout << N - F(1) << '\n';
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
