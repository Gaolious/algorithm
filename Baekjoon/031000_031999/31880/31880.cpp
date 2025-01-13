#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int N, M, n;
    ll s=0, m=1;
    cin >> N >> M ;
    while (N-- && cin >> n ) s += n;
    while (M-- && cin >> n ) m *= max(1,n) ;
    cout << s * m ;
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
