#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

void init(){
}
void process(int Case) {
    int N, i;
    ld a, b, c, d, s;
    long long int q, w;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> a >> b >> c >> d;
        q = sqrt(b) + 1;
        w = sqrt(d) + 1;

        b /= q*q;
        d /= w*w;
        s = a-c + q*sqrt(b) - w*sqrt(d);
        if ( abs(s) < 1.0e-18 )
            cout << "Equal\n";
        else if ( s > 0 )
            cout << "Greater\n";
        else
            cout << "Less\n";

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
