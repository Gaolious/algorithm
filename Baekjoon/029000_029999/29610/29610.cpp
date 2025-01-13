#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init() {}
void process(int Case) {
    int N, K, A, B, i, j;
    cin >> N >> K ;

    vector<pair<int,int>> D(N);
    for(auto &[x,y]: D) {
        cin >> x ;
        y = 1;
    }
    std::sort(D.begin(), D.end());
    cin >> A >> B;

    for ( i = 0, j = 1 ; j < N ; j ++ ) {
        if ( D[i].first == D[j].first ) D[i].second++;
        else D[++i] = D[j];
    }
    D.resize(i+1);

//    for (auto [x, y]: D) cout << x/**/ << ' ' << y << '\n';

    vector<int> ans(B-A+1);

    for ( auto [n, cnt]: D)
        for ( i = ( A % n == 0 ? A : (A/n+1)*n) ; i <= B ; i += n )
            ans[ i - A ] += cnt;

    int answer = 0 ;
    for ( i = 0 ; i < ans.size() ; i ++ ) {
        if ( ans[i] == K ) answer++;
    }

    cout << answer << '\n';
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
