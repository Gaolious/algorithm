#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
char M[4][5]={
    {"ACAG"},
    {"CGTA"},
    {"ATCG"},
    {"GAGT"}
};
int Idx[127]={0,};
void process(int Case) {

    int N, i;
    string s;
    Idx['A'] = 0, Idx['G']=1, Idx['C']=2, Idx['T']=3;
    cin >> N >> s;
    for ( i = N-2 ; i >= 0 ; i -- ) {
        s[i] = M[ Idx[s[i]] ][ Idx[s[i+1] ] ];
    }
    cout << s[0];
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
