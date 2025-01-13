#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, d, carry, v;
    char c;
    string s;
    cin >> N >> c >> s >> d;
    while ( s.size() < d ) s.push_back('0');

    carry = 0;
    if ( s.size() > d ) {
        carry = s[d] >= '5';
        s.resize(d);
    }
    for ( d--; d >= 0 && carry ; d -- ) {
        v = s[d]-'0' + carry ;
        carry = v/10;
        s[d] = '0' + v%10;
    }
    N += carry;

    cout << N << '.' << s << '\n';
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
