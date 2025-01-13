#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ld, ld> pdd;
const ld EPS = 1.0e-12;
const ld PI = acos(-1);
ld P2( ld a) { return a*a; }

bool isEqual(ld a, ld b){
    return abs(a-b) < EPS;
}
void init(){
}
void process(int Case) {
    pdd p1, p2;
    ld r1, r2, d, ans, r12, r22, d2, s;
    cin >> p1.first >> p1.second >> r1 ;
    cin >> p2.first >> p2.second >> r2 ;

    d = sqrt( P2(p1.first-p2.first) + P2(p1.second-p2.second) );
    r12=r1*r1;
    r22=r2*r2;
    d2=d*d;
    s=r1+r2+d;
    if ( d > r1+r2 || isEqual(d, r1+r2) )
        ans = 0;
    else if ( d < abs(r1-r2) || isEqual(d, abs(r1-r2) ) )
        ans = PI * P2(min(r1,r2));
    else {
        ld a = r12 * acos( (d2 + r12 - r22 ) / (2*d*r1) );
        ld b = r22 * acos( (d2 + r22 - r12 ) / (2*d*r2) );
        ld c = 0.5 * sqrt ( (s-2*d)*(s-2*r2)*(s-2*r1)*s);
        ans = a+b-c;
    }
    cout << setprecision(3) << fixed << ans << '\n';
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
