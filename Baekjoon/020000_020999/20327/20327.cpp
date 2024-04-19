#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int MaxN = ( 1 << 7 );
typedef pair<int, int> Pt;
Pt Cvt90(int y, int x, int size) {
    return { x, size - 1 - y};
}
Pt Cvt180(int y, int x, int size) {
    return  {size-1-y, size-1-x} ;
}
Pt Cvt270(int y, int x, int size) {
    return  {size-1-x, y} ;
}

void FLIP_Y(int src[MaxN][MaxN], int dest[MaxN][MaxN], int sy, int sx, int size) {
    int s = size / 2;
    int i, j;
    for ( i = 0 ; i < s ; i ++ )
        for ( j = 0 ; j < size ; j ++ )
            swap(src[sy + size-1-i ][sx + j], src[sy + i][sx + j]);
}
void FLIP_X(int src[MaxN][MaxN], int dest[MaxN][MaxN], int sy, int sx, int size) {
    int s = size / 2;
    int i, j;
    for ( i = 0 ; i < size ; i ++ )
        for ( j = 0 ; j < s ; j ++ )
            swap(src[sy + i][sx + size-1-j], src[sy + i][sx + j]);
}
void ROT90(int src[MaxN][MaxN], int dest[MaxN][MaxN], int sy, int sx, int size) {
    int i, j;

    for ( i = 0 ; i < size ; i ++ )
        for ( j = 0 ; j < size ; j ++ ) {
            auto [y, x] = Cvt90(i, j, size);
            dest[sy + y][sx + x] = src[sy + i ][ sx + j ];
        }
}
void ROT180(int src[MaxN][MaxN], int dest[MaxN][MaxN], int sy, int sx, int size) {
    int i, j;
    for ( i = 0 ; i < size ; i ++ )
        for ( j = 0 ; j < size ; j ++ ) {
            auto [y, x] = Cvt90(i, j, size);

            dest[sy + y][sx + x] = src[sy + i ][ sx + j ];
        }
}
void ROT270(int src[MaxN][MaxN], int dest[MaxN][MaxN], int sy, int sx, int size) {
    int i, j;
    for ( i = 0 ; i < size ; i ++ )
        for ( j = 0 ; j < size ; j ++ ) {
            auto [y, x] = Cvt270(i, j, size);

            dest[sy + y][sx + x] = src[sy + i ][ sx + j ];
        }
}
typedef void (*cbFn)(int src[MaxN][MaxN], int dest[MaxN][MaxN], int sy, int sx, int size);

struct Matrix {
    int len{};
    int curr{};
    int M[2][MaxN][MaxN]{};
    void toggle() { curr = 1 - curr ; }

    void dump() {
        int i, j;
        for ( i = 0 ; i < len ; i ++ ) {
            for ( j = 0 ; j < len ; j ++ )
                cout << M[curr][i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    void move(int sy, int sx, int dy, int dx, int len) {
        int i;
        for ( i = 0 ; i < len ; i ++ )
            memcpy(M[1-curr][dy+i]+dx, M[curr][sy+i]+sx, len * sizeof(int));
    }
};
Matrix matrix;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, R, k, l;
    int i, j, cnt, size;

    cin >> N >> R;
    matrix.len = 1 << N ;

    for ( i = 0 ; i < matrix.len ; i ++ )
        for ( j = 0 ; j < matrix.len ; j ++ )
            cin >> matrix.M[matrix.curr][ i ][ j ] ;

    for ( int t = 0 ; t < R ; t ++ ) {
        cin >> k >> l;
        switch (k) {
            case 1: {
                if ( l > 0 ) {
                    size = 1 << l ;
                    for ( i = 0 ; i < matrix.len ; i += size )
                        for ( j = 0 ; j < matrix.len ; j += size )
                            FLIP_Y(matrix.M[ matrix.curr ], matrix.M[ 1-matrix.curr ], i, j, size );
                }
            }
            break;
            case 2: {
                if ( l > 0 ) {
                    size = 1 << l ;
                    for ( i = 0 ; i < matrix.len ; i += size )
                        for ( j = 0 ; j < matrix.len ; j += size )
                            FLIP_X(matrix.M[ matrix.curr ], matrix.M[ 1-matrix.curr ], i, j, size );
                }
            }
            break;
            case 3: {
                if ( l > 0 ) {
                    size = 1 << l ;
                    for ( i = 0 ; i < matrix.len ; i += size )
                        for ( j = 0 ; j < matrix.len ; j += size )
                            ROT90(matrix.M[ matrix.curr ], matrix.M[ 1-matrix.curr ], i, j, size );
                    matrix.toggle();
                }
            }
            break;
            case 4: {
                if ( l > 0 ) {
                    size = 1 << l ;
                    for ( i = 0 ; i < matrix.len ; i += size )
                        for ( j = 0 ; j < matrix.len ; j += size )
                            ROT270(matrix.M[ matrix.curr ], matrix.M[ 1-matrix.curr ], i, j, size );
                    matrix.toggle();
                }
            }
            break;
            case 5: {
                size = 1 << l ;
                cnt = matrix.len / size;
                for ( i = 0 ; i < cnt ; i ++ )
                    for ( j = 0 ; j < cnt ; j ++) {
                        matrix.move(i*size, j*size, (cnt-1-i)*size, j*size, size);
                    }
                matrix.toggle();
            }
            break;
            case 6: {
                size = 1 << l ;
                cnt = matrix.len / size;
                for ( i = 0 ; i < cnt ; i ++ )
                    for ( j = 0 ; j < cnt ; j ++) {
                        matrix.move(i*size, j*size, i*size, (cnt-1-j)*size, size);
                    }
                matrix.toggle();
            }
            break;
            case 7: {
                size = 1 << l ;
                cnt = matrix.len / size;
                for ( i = 0 ; i < cnt ; i ++ )
                    for ( j = 0 ; j < cnt ; j ++ ) {
                        auto [y, x] = Cvt90(i, j, cnt);
                        matrix.move(i*size, j*size, y*size, x*size, size);
                    }
                matrix.toggle();

            }
            break;
            case 8: {
                size = 1 << l ;
                cnt = matrix.len / size;
                for ( i = 0 ; i < cnt ; i ++ )
                    for ( j = 0 ; j < cnt ; j ++ ) {
                        auto [y, x] = Cvt270(i, j, cnt);
                        matrix.move(i*size, j*size, y*size, x*size, size);
                    }
                matrix.toggle();

            }
            break;
        }
    }
    matrix.dump();
    return 0;
}


