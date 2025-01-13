#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}

char D1[100'010];
char D2[100'010];
bool F(string &s) {
    int i, N ;
    N = s.size();
    memset(D1, 0, sizeof(D1));
    memset(D2, 0, sizeof(D1));


    for ( i = 1 ; i < N ; i ++ )
        D2[i-1] = D1[i] = s[i] != s[i-1];

#ifdef AJAVA_DEBUG
    cout << s << '\n';
    for ( i = 0 ; i < N ; i ++ ) cout << (char)(D1[i]+'0') ; cout << '\n';
    for ( i = 0 ; i < N ; i ++ ) cout << (char)(D2[i]+'0') ; cout << '\n';
#endif

    if(s[0] != s[1] || s[N - 2] != s[N - 1])
        return true;

    for ( i = 0 ; i < N-1 ; i ++ )
        if ( D1[i] && D2[i+1] )
            return true;
    return false;
}

void process(int Case) {
    int N ;
    cin >> N;
    string s ;
    cin >> s ;

    cout << ( s.size()>1 && F(s) ? "TAK" : "NIE") << '\n';
}
int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
