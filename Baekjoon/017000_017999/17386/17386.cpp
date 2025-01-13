#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
using Pt = pair<ld, ld> ;
enum DIR {LEFT, COLLINEAR, RIGHT};
const ld EPS = 1.0e-12;
istream &operator >>(istream &in, Pt &a) {in >> a.x >> a.y; return in;}
ostream &operator <<(ostream &out, Pt &a) {out << a.x << ' ' << a.y; return out;}
Pt operator - (Pt A, Pt B) { return {A.x - B.x, A.y - B.y};}
Pt operator + (Pt A, Pt B) { return {A.x + B.x, A.y + B.y};}
Pt operator * (Pt A, ld n) { return {A.x * n, A.y * n};}
Pt operator * (ld n, Pt A) { return {A.x * n, A.y * n};}
bool operator == (Pt A, Pt B) { return abs(A.x - B.x) < EPS && abs(A.y - B.y) < EPS;}
struct Line {Pt s, e;};
ld size(Pt A) { // |A| 원점에서 A까지의 길이
    return sqrt ( A.x * A.x + A.y * A.y );
}
ld dot(Pt A, Pt B) {
    // Dot Product A·B = |A|·|B|· cos(Θ)
    // A.x * B.x + A.y + B.y = size(A) * size(B) * cos( Θ )
    return A.x * B.x + A.y * B.y;
}
ld cross(Pt A, Pt B) {
    // Cross Product AxB = |A|·|B|· sin(Θ)
    return A.x * B.y - A.y * B.x;
}
ld dist(Pt A, Pt B) {
    return sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) );
}
DIR ccw( Pt A, Pt B, Pt C) {
    auto ret = cross(B-A, C-A);
    if ( ret > 0 ) return LEFT;
    if ( ret < 0 ) return RIGHT;
    return COLLINEAR;
}
bool between(Pt S, Pt p, Pt E) {
    // S <= p <= E
    return min(S.x, E.x) - EPS <= p.x && p.x <= max(S.x, E.x) + EPS &&
           min(S.y, E.y) - EPS <= p.y && p.y <= max(S.y, E.y) + EPS;
}
bool between(Line &l, Pt p) {
    return between(l.s, p, l.e);
}
bool segmentsIntersect(Line l1, Line l2, Line &overlapLine, bool &isTouchBothEndPoint, bool &isTouchSingleEndPoint, bool &isCollinear, bool &isOverlap) {
    // isTouchBothEndPoint    isTouchSingleEndPoint    isCollinear     isOverlap
    //                        |
    // +---                   +---                     --+--           --+--+--
    // |                      |
    Pt A = l1.e - l1.s;
    Pt B = l2.s - l2.e;
    Pt C = l2.s - l1.s;

    auto denom = cross(A, B);
    auto cp = cross(C, A);

    isCollinear = abs(cp) < EPS;
    isOverlap = false;
    isTouchBothEndPoint = (l1.s == l2.s || l1.s == l2.e || l1.e == l2.s || l1.e == l2.e);
    isTouchSingleEndPoint = false;

    if (abs(denom) < EPS) { // 평행
        if (isCollinear) { // 일직선
            if ( between(l1, l2.s) || between(l1, l2.e) || between(l2, l1.s) || between(l2, l1.e) ) {
                overlapLine.s = max(min(l1.s, l1.e), min(l2.s, l2.e));
                overlapLine.e = min(max(l1.s, l1.e), max(l2.s, l2.e));
                isOverlap = !(overlapLine.s == overlapLine.e);
                return true;
            }
            return false;
        }
        return false;
    }

    // Check if endpoints touch

    auto t = cross(C, B) / denom;
    auto u = -cross(C, A) / denom;

    if (-EPS < t && t < 1 + EPS && -EPS < u && u < 1 + EPS) {
        overlapLine.s = overlapLine.e = l1.s + A * t;
        if ( abs(t) < EPS || abs(t-1) < EPS || abs(u) < EPS || abs(u-1) < EPS )
            isTouchSingleEndPoint = true;
        return true;
    }
    return false;
}
void init(){
}

void process(int Case) {
    Line l1, l2;
    cin >> l1.s >> l1.e;
    cin >> l2.s >> l2.e;

    bool isCross, isCollinear, isOverlap, isTouchBothEndPoint, isTouchSingleEndPoint;
    Line overlapLine;
    isCross = segmentsIntersect(l1, l2, overlapLine, isTouchBothEndPoint, isTouchSingleEndPoint, isCollinear, isOverlap);

    if (isCross) {
        cout << "1\n";
        if ( !isOverlap )
            cout << setprecision(18) << fixed << overlapLine.s ;
    }
    else
        cout << "0\n";
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
