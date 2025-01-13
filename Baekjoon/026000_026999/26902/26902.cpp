#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
int D[4][20];
string S;

int F(int nth, int idx) {
    if ( nth>=4 ) {
        return idx == S.size();
    }
    auto &ret = D[nth][idx ];
    if ( ret < 0 ) {
        int val = 0, prev=-1, i;
        ret = 0 ;
        for (i = 0; i < 3 && i + idx < S.size(); i++) {
            val = val * 10 + S[idx + i] - '0';
            if ( val <= prev ) break;
            prev = val;
            if (0 <= val && val <= 255)
                ret += F(nth + 1, idx + i + 1);
        }
    }
    return ret;
}
void process(int Case) {
    memset(D, -1, sizeof(D));
    cin >> S;
    cout << F(0, 0) << '\n';
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
