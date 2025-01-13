#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef pair<int,int> pii;
ld PI = acos(-1);

pair<ld, int> convert(ld angle) {
    if ( angle <= 90.0l ) return {90.0l - angle, 1}; // 1사분면
    else if ( angle <= 180.0l ) return {180.0 - angle + 270.0l, 4}; // 4사분면
    else if ( angle <= 270.0l ) return {270.0l - angle + 180.0, 3}; // 3사분면
    else return {360.0l - angle + 90.0l, 2}; // 2사분면
}
int Rnd(ld v) {
    return (int)( v + ( v < 0 ? -0.5 : 0.5) );
}
void getPos(vector<pii>& out, int sx, int sy, ld degree, int dir, int len) {
    int x, y;

    for ( int i = 0 ; ; i ++ ) {
        x = y = 0;

        if ( dir == 1 ) {
            if ( degree < 45 ) x = i, y = Rnd( i * tan(degree / 180.0 * PI ) ) ;
            else if ( degree > 45 ) y = i, x = Rnd( i / tan(degree / 180.0 * PI ) ) ;
            else x = y = i;
        }
        else if ( dir == 2 ) {
            if ( degree > 135 ) x = -i, y = Rnd( i * tan((180-degree) / 180.0 * PI ) ) ;
            else if ( degree < 135 ) y = i, x = -Rnd( i / tan((180-degree) / 180.0 * PI ) ) ;
            else x = -i, y = i;
        }
        else if (dir == 3 ) {
            if ( degree < 225 ) x = -i, y = -Rnd( i * tan((degree-180) / 180.0 * PI ) ) ;
            else if ( degree > 225 ) y = -i, x = -Rnd( i / tan((degree-180) / 180.0 * PI ) ) ;
            else x = -i, y = -i;
        }
        else {
            if ( degree > 315 ) x = i, y = -Rnd( i * tan((360-degree) / 180.0 * PI ) ) ;
            else if ( degree < 315 ) y = -i, x = Rnd( i / tan((360-degree) / 180.0 * PI ) ) ;
            else x = i, y = -i;
        }
        out.emplace_back(sy-y, sx+x);
        if ( x*x + y*y > len*len ) break;
    }
}
#define DX(a, b, c) ( abs( pos[a].second - pos[b].second ) == c )
#define DY(a, b, c) ( abs( pos[a].first - pos[b].first ) == c )
#define DIAG(a, b) ( DX(a, b, 1) && DY(a, b, 1) )

#define SIGN(a) ( ( (a) < 0 ? -1 : (a) > 0 ? 1 : 0 )
void draw(vector<pii>& pos, vector<string> &ans, ld angle, int d) {
    int i;
    vector<char> c ;
    for ( i = 0 ; i + 1 < pos.size() ; i ++ ) {
        if (i > 0 ) {
            if (DX(i - 1, i, 0) && DX(i, i + 1, 0)) {
                c.emplace_back('|');
                continue;
            }
            else if (DY(i - 1, i, 0) && DY(i, i + 1, 0)) {
                c.emplace_back('-');
                continue;
            }
            else if (DIAG(i - 1, i) && DIAG(i, i + 1)) {
                if (d == 2 || d == 4)
                    c.emplace_back('\\');
                else
                    c.emplace_back('/');
                continue;
            }
        }
        c.emplace_back('o');
    }
    for (i = 0 ; i + 1< pos.size() ; i ++ )
        ans[ pos[i].first ][ pos[i].second ] = c[i];
}
void process(int h, int m) {
    int i;
    int ex, ey;
    vector<string> ans(51, string(51, ' '));
    for (i = 0 ; i <=50 ; i ++ )
        ans[i][0] = ans[i][50] = ans[0][i] = ans[50][i] = i%10 == 0 ? '@' : 'X';
    ans[2][24] = '1'; ans[2][26] = '2';
    ans[48][25] = '6';
    ans[25][2] = '9';
    ans[25][48] = '3';

    auto [degreeH, dirH] = convert(h * 30.0l + 0.5*m );
    auto [degreeM, dirM] = convert(m * 6.0l);
    vector<pii> hourPos, minPos;
    getPos(hourPos, 25, 25, degreeH, dirH, 15 );
    getPos(minPos, 25, 25, degreeM, dirM, 21 );
    draw(hourPos, ans, degreeH, dirH);
    draw(minPos, ans, degreeM, dirM);
    ans[25][25] = '*';

    for (auto &s: ans) cout << s << '\n';

}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    string s ;
    int i;
    for ( i = 0 ; cin >> s && s != "END" ; i ++) {
        if ( i > 0 ) cout << '\n';
        stringstream  ss(s);
        int h, m;
        char c;
        ss >> h >> c >> m;
        process(h%12, m%60);
    }
    return 0;
}