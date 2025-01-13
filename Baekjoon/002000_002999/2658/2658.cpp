#include <bits/stdc++.h>
using namespace std;
const int N = 10;
struct Data {
    char c;
    int y, x;
};

typedef vector<vector<Data>> Mat ;
void mirrorX(Mat &src, Mat &dest) {
    int i, j;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            dest[i][j] = src[i][N - 1 - j];
}
void Rot90(Mat &src, Mat &dest) {
    int i, j;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            dest[i][j] = src[j][N - 1 - i];
}
bool checkL(Mat &src, int y, int x, int cnt) {
    int i;
    for ( i = 1 ; i <= cnt ; i ++ ) {
        if ( y < 0 || x - i < 0 || y >= N || x - i >= N || src[y][x - i].c != '1' )
            return false;
    }
    return true;
}
bool checkR(Mat &src, int y, int x, int cnt) {
    int i;
    for ( i = 1 ; i <= cnt ; i ++ )
        if ( y < 0 || x + i < 0 || y >= N || x + i >= N || src[y][x + i].c != '1' )
            return false;
    return true;
}
vector<pair<int,int>> isTriangle(Mat &src, int y, int x, int S) {
    int i, j, k;
    int s;
    bool left = true, right = true;
    for ( s = 0, k = 0 ; y + k < N && src[y+k][x].c == '1' ; k ++ ) {
        if ( left && !checkL(src, y+k, x, k) ) left = false;
        if ( right && !checkR(src, y+k, x, k) ) right = false;
        if ( !left && !right ) break;

        if ( left ) s += k + 1 ;
        if ( right ) s += k + 1 ;
        if ( left && right ) s -= 1 ;

        if ( s == S ) {
            vector<pair<int,int>> out;
            out.emplace_back( src[y][x].y, src[y][x].x );
            if ( left ) out.emplace_back(src[y + k][x - k].y, src[y + k][x - k].x);
            if ( right ) out.emplace_back(src[y + k][x + k].y, src[y + k][x + k].x);
            if ( !left || !right ) out.emplace_back(src[y + k][x].y, src[y + k][x].x);
            return out;
        }
    }
    return {};
}

void init(){
}
void process(int Case) {
    int i, j, k;
    int S = 0, s;
    vector<Mat> M(8, vector(N, vector<Data>(N)));
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> M[0][i][j].c;
            if ( M[0][i][j].c == '1' ) {
                S ++;
                M[0][i][j].y = i ;
                M[0][i][j].x = j ;
            }
        }
    }
    mirrorX(M[0], M[1]);
    for ( i = 2 ; i < 8 ; i ++ )
        Rot90(M[i-2], M[i]);

    for (auto &m: M) {
        for ( i = 0 ; i < N ; i ++ ) {
            for ( j = 0 ; j < N ; j ++ ) {
                auto out = isTriangle(m, i, j, S);
                if ( out.empty() ) continue;
                std::sort(out.begin(), out.end());
                for (auto [Y, X]: out) {
                    cout << Y+1 << ' ' << X+1 << '\n';
                }
                return;
            }
        }
    }
    cout << 0;
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
