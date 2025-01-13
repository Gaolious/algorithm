#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    string A[3], s;
    int  i, j;
    cin >> s ;
    for (i = 0 ; i < 3 ; i ++ )
        A[i].resize(4*s.size() + 1, '.');

    for (i = 0 ; i < s.size() ; i ++ ) {
        A[0][ i * 4 + 2] = (i+1)%3 == 0 ? '*' : '#';

        A[1][ i * 4 + 1] = (i+1)%3 == 0 ? '*' : '#';
        A[1][ i * 4 + 3] = (i+1)%3 == 0 ? '*' : '#';

        if ( A[2][ i * 4 + 0] == '.' || (i+1)%3 == 0 )
            A[2][ i * 4 + 0] = (i+1)%3 == 0 ? '*' : '#';
        if ( A[2][ i * 4 + 4] == '.' || (i+1)%3 == 0 )
            A[2][ i * 4 + 4] = (i+1)%3 == 0 ? '*' : '#';
        A[2][ i * 4 + 2] = s[i];
    }

    for ( i = -2 ; i <= 2 ; i ++ ) {
        cout << A[2-abs(i)] << '\n';
    }
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
