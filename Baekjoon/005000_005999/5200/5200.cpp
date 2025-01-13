#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const ld PI = acos(-1);
void init(){
}
void process(int Case) {
    ld w, h, m, d, hi, ri;
    ld cy, x;
    int b;
    cin >> w >> h >> m >> d >> b;
    cy = 0;
    while ( b -- ) {
        cin >> hi >> ri ;
        cy += ri * ri * hi ;
    }
    cy *= PI;
    m *= 2;
    x = ( d * m * (w + h - m) - cy )  / (w*h);
    cout << "Data Set " << Case << ":\n" << setprecision(2) << fixed << x << '\n';
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
