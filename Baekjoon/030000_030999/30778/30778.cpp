#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

void init(){
}
void process(int Case) {
    int W, H;
    cin >> W >> H ;
    pii A, B;
    cin >> A.first >> A.second >> B.first >> B.second;

    int ans = -1;
    for ( auto x: {-W, 0, W})
        for (auto y: {-H, 0, H})
            if ( ans < 0 || ans > abs(A.first+x - B.first) + abs(A.second+y-B.second) )
                ans = abs(A.first+x - B.first) + abs(A.second+y-B.second);
    cout << (ans+1)/2 << '\n';
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
