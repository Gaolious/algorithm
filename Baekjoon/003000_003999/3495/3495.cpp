#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

void init(){
}
void process(int Case) {
    int H, W, area, i, j;
    bool in;
    string s;
    cin >> H >> W ;
    cin.ignore();
    for (area=0; H-- ;) {
        getline(cin, s);
        in = false;
        for (auto c: s ) {
            if ( c != '.' ) in=!in, area++;
            else if ( in ) area+=2;
        }
    }
    cout << area/2 << '\n';
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
