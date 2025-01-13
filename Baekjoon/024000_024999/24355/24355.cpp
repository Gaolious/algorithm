#include <bits/stdc++.h>
using namespace std;

void init(){
}
const int MaxN=500002;
int S[2*MaxN+2];

void process(int Case) {
    int i, j, N, N2;

    string s1, s2;
    cin >> s1 ;
    N = s1.size();
    s2=s1;
    std::reverse(s2.begin(), s2.end());
    s1 += "$" + s2;

    N2 = s1.size();
    for ( j=0, i=1 ; i < N2 ; i ++ )
    {
        while ( j > 0 && s1[j] != s1[i] ) j = S[j-1];
        if ( s1[j] == s1[i]) j ++;
        S[i] = j;
    }
    cout << 2 * N - S[N2-1] << '\n';
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
