#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
typedef long long int ll;
typedef long double ld;
using Pt = pair<ld, ld> ;
const ld EPS = 1.0e-12;
istream &operator >>(istream &in, Pt &a) {in >> a.x >> a.y; return in;}
ostream &operator <<(ostream &out, Pt &a) {out << a.x << ' ' << a.y; return out;}
Pt operator - (Pt A, Pt B) { return {A.x - B.x, A.y - B.y};}
Pt operator + (Pt A, Pt B) { return {A.x + B.x, A.y + B.y};}
Pt operator * (Pt A, ld n) { return {A.x * n, A.y * n};}
Pt operator / (Pt A, ld n) { return {A.x / n, A.y / n};}
Pt operator * (ld n, Pt A) { return {A.x * n, A.y * n};}
bool operator == (Pt A, Pt B) { return abs(A.x - B.x) < EPS && abs(A.y - B.y) < EPS;}
template <typename T> T DIST2(pair<T,T> a) {return a.first*a.first + a.second*a.second;}

ld cross(Pt A, Pt B) {
    return A.x * B.y - A.y * B.x;
}

ld area(Pt A, Pt B, Pt C) {
    // (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) = 2*S
    return abs( cross(B-A, C-A) ) / 2.0;
}

void init() {}

void process(int Case) {
    Pt a, b, c;
    ld S, N;
    cin >> a >> b >> c >> N;
    S = area(a,b,c);

    if ( S < N ) {
        cout << "No solution\n";
    }
    else {
        Pt l = a, r = c;
        while ( DIST2(r-l) > 1.0e-16 ) {
            Pt m = (l + r) / 2.0;
            ld s = area(a, b, m);
            if (s < N) l = m;
            else r = m;
        }
        l = (l+r)/2;

        cout << setprecision(12);
        cout << a << '\n';
        cout << b << '\n';
        cout << l << '\n';
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
