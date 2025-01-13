#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, A, n;
    cin >> N ;
    priority_queue<int> Q;
    cin >> A ;
    while ( --N ) {
        cin >> n ;
        Q.push(n);
    }
    int cnt = 0;
    while ( !Q.empty() && Q.top() >= A ) {
        int t = Q.top();
        Q.pop();
        Q.push(t-1);
        A++;
        cnt++;
    }
    cout << cnt << '\n';
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
