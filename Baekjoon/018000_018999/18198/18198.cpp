#include <bits/stdc++.h>
using namespace std;

void init(){}
bool isWin(int a, int b){
    if ( a >= 11 && b < 10 ) return true;
    if ( a-2 >= b && b >= 10 ) return true;
    return false;
}
void process(int Case) {
    string s;
    int A, B, i;
    cin >> s;
    for (i = A=B=0 ; i < s.size() ; i += 2 ) {
        ( s[i] == 'A' ? A : B ) += s[i+1]-'0';
        if (isWin(A, B) ) cout << 'A' ;
        else if (isWin(B, A) ) cout << 'B';
        else continue;
        break;
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
