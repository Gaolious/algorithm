#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, M;
    cin >> N >> M ;
    vector<int> A(N);
    for (auto &n: A) cin >> n ;
    std::sort(A.begin(), A.end());
    priority_queue<int> Q;
    for (int i = 0 ; i < M ; i ++ ) Q.emplace(0);

    int ans = 0 ;
    for (auto t: A) {
        auto curr = -Q.top();
        Q.pop();
        ans += curr+t;
        Q.emplace(-(curr+t));
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
