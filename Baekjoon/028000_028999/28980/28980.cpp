#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void init(){
}
void process(int Case) {
    ll score=0, maxScore=100, n;
    string s;
    cin >> s;
    n=0;
    for (auto c: s) {
        score += 25 - (c - 'A');
        maxScore = min(maxScore, 25ll - (c - 'A')+1);
        n++;
    }
    score = (score * 10/ n + 5)/10;
    score = min(score, maxScore);
    cout << (char)( 'A' + (25-score) )<< '\n';
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
