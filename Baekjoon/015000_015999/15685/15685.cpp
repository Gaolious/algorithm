#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
typedef pair<int, int>  Pt;
vector D(11, vector<Pt>()) ;

Pt operator + (Pt a, Pt b) {
    return {a.first+b.first, a.second+b.second};
}
Pt operator - (Pt a, Pt b) {
    return {a.first-b.first, a.second-b.second};
}
Pt R0(Pt a) { return {a.first, a.second};}
Pt R90(Pt a) { return {-a.second, a.first};}
Pt R180(Pt a) { return {-a.first, -a.second};}
Pt R270(Pt a) { return {a.second, -a.first};}

typedef Pt (*fnConvert)(Pt );

void gen_dragon() {
    int i, x, y ;
    D[0].emplace_back(0,0);
    D[0].emplace_back(0,1);
    Pt B;
    for ( i = 1 ; i < 11 ; i ++ ) {
        for ( auto p: D[i-1]) D[i].push_back(p);
        B = D[i-1].back();
        for ( auto p = D[i-1].rbegin()+1 ; p != D[i-1].rend() ; p ++)
            D[i].push_back( R90(*p - B) + B);
    }
    for ( i = 0 ; i < 11 ; i ++ ) {
        for ( auto &p: D[i])
            p.first = -p.first;
    }
}
bool A[101][101];
void dump() {
    int i, j;
    for ( i = 0 ; i <= 100 ; i ++ ) {
        for ( j = 0 ; j <= 100 ; j ++ ) {
            if ( A[i][j]) cout << '@';
            else cout << '.';
        }
        cout << '\n';
    }
    cout << endl;
}
void draw_dragon(Pt sp, int g, fnConvert fnCvt) {
    Pt a;
    for (auto p: D[g] ) {
        a = fnCvt(p) + sp;
        A[a.first][a.second] = true;
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    int N, d, g;
    Pt p;
    fnConvert mapping[] = { R0, R90, R180, R270 };
    gen_dragon();

    cin >> N;
    while (N--) {
        cin >> p.second >> p.first >> d >> g ;
        draw_dragon(p, g, mapping[d]);
        // dump();
    }
    int i, j, cnt=0;
    for ( i = 1 ; i <= 100 ; i ++)
        for ( j = 1 ; j <= 100 ; j ++ ) {
            if (!A[i-1][j-1] || !A[i][j-1]) continue;
            if (!A[i-1][j] || !A[i][j]) {
                j++;
                continue;
            }
            cnt ++;
        }
    cout << cnt << '\n';
    return 0;
}


