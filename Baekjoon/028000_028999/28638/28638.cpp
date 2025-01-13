#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int N, ans, t;
    int i, h, m, probNo;
    char c;
    string prob, resp;
    cin >> N ;
    vector<bool> solved(26);
    vector<int> retry(26);
    ans = t = 0 ;

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> h >> c >> m >> prob >> resp;
        m += h*60;
        probNo = prob[0] - 'A';
        if ( solved[probNo] ) continue;
        else if ( resp == "CE" ) continue;
        else if ( resp == "OK" ) {
            ans++;
            t += m + retry[probNo] * 20;
            solved[probNo] = true;
        }
        else {
            retry[probNo] ++;
        }
    }
    cout << ans << ' ' << t << '\n';
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
