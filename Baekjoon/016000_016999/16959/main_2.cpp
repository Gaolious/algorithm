// #include <bits/stdc++.h>
// #define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);
//
// typedef long long int ll;
// typedef unsigned long long int ull;
//
//
// using namespace std;
// // 100 100 100 99
// int A[101];
// int N ;
// // [pieceType1][y,x] ~ [pieceType2][y,x] 로 가는데 최소비용.
// int D[3][100][3][100];
// const int ROOK = 0 ; // +
// const int BISHOP = 1 ; // X
// const int KNIGHT = 2 ; // J
//
// int lenDxy[] = {4, 4, 8};
// int dy[][10] = {
//     {0, 1, 0, -1},
//     {1, 1, -1, -1},
//     {2, 2, -2, -2, 1, 1, -1, -1},
// };
// int dx[][10] = {
//     {1, 0, -1, 0},
//     {1, -1, 1, -1},
//     {-1, 1, -1, 1, -2, 2, -2, 2},
// };
// void Spread(int A[100], int pos, int pieceType) {
//     int y, x, d, ty, tx;
//     y = pos / N ;
//     x = pos % N ;
//     for ( d = 0 ; d < lenDxy[pieceType] ; d ++ ) {
//         ty = y ;
//         tx = x ;
//         while ( true ) {
//             ty += dy[pieceType][ d ] ;
//             tx += dx[pieceType][ d ] ;
//             if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) break;
//
//         }
//     }
// }
// const int INF = 100000;
// int main()
// {
// #ifdef AJAVA_DEBUG
//     freopen("input.txt", "rt", stdin);
//     freopen("output.txt", "wt", stdout);
// #endif
//
//     fastio;
//     int i, j, t1, t2, d;
//     int initPos = 0;
//
//     cin >> N ;
//
//     for ( t1 = 0 ; t1 < 3 ; t1 ++ ) {
//         for ( i = 0 ; i < N*N ; i ++ ) {
//             for ( t2 = 0 ; t2 < 3 ; t2 ++ ) {
//                 d = ( t1 == t2) ? 0 : 1;
//
//             }
//         }
//     }
//     for ( i = 0 ; i < N*N ; i ++ ) {
//         cin >> A[i] ;
//         if ( A[i] == 1 )
//             initPos = i ;
//     }
//
//     return 0;
//
// }
//
//
