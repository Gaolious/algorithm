#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int i, M, N;
    ll P; // M 프로젝트 수, N 보조금 지급일 수, P 보조금
    cin >> M >> N >> P ;
    vector<ll> S(M), R(N), T(M);
    for (auto &n: S) cin >> n; // 하루에 사용 가능한 보조금, ceil( P/si) 일 동안 사용 가능
    for (auto &n: R) cin >> n; // 보조금 Ri에 지급
    for ( i = 0 ; i < M ; i ++ )
        T[ i ] = P / S[i] + ( P%S[i] == 0 ? 0 : 1);
    std::sort(R.begin(), R.end());
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
