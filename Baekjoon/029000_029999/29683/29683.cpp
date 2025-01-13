#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init() {}

void process(int Case) {
    int N, A, a;
    int i, s;
    cin >>  N >> A;

    for ( s = i = 0 ; i < N ; i ++ ) {
        cin >> a;
        s += a/A;
    }
    cout << s << '\n';
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
