#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

void init(){
}
void process(int Case) {
    string s1, s2;
    ld a1, a2;
    ld mul1;

    cin >> s1 >> a1 >> s2 >> mul1 >> a2;

    ld initialBP = 0.0;
    ld b1 = (initialBP + a1) * mul1;
    ld b2 = initialBP * mul1 + a2;

    // 최적의 순서 결정
    if (abs (b1 - b2) < 1.0e-12 )
        cout << "Whatever" << endl;
    else
        cout << (b1 > b2 ? "Power up, Evolve" : "Evolve, Power up" ) << '\n';
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
