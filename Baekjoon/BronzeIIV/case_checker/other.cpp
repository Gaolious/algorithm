#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    int c, n, x, y, Q, z, s ;
    int dx[] = { 1, 0, -1, 0 };
    int dy[] = { 0, 1, 0, -1 };
    int d ;
    int i, k ;

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie();
    cin >> Q ;    
    while ( Q-- ) {
        int A[110][110]={0,};
        cin >> c ;
        if ( c == 1 ) {
            cin >> n >> y >> x ;

            int tx = 0, ty = 1, d = 0 ;
            int x2 = 0, y2=1;
            for ( i = 1 ; i <= n*n ; i ++ ) {
                tx = x2 + dx[d] ;
                ty = y2 + dy[d] ;

                if ( tx < 1 || tx > n || ty < 1 || ty > n || A[ty][tx] != 0) {
                    d = ( d + 1 ) % 4 ;
                    tx = x2 + dx[d] ;
                    ty = y2 + dy[d] ;
                }

                A[ty][tx] = i ;
                x2 = tx ;
                y2 = ty;
            }
            cout << A[y][x] << '\n';
        }
        else if ( c == 2 ) {
            cin >> n >> z ;            
            int tx = 0, ty = 1, d = 0 ;
            int x2 = 0, y2=1;
            for ( i = 1 ; i <= n*n ; i ++ ) {
                tx = x2 + dx[d] ;
                ty = y2 + dy[d] ;

                if ( tx < 1 || tx > n || ty < 1 || ty > n || A[ty][tx] != 0) {
                    d = ( d + 1 ) % 4 ;
                    tx = x2 + dx[d] ;
                    ty = y2 + dy[d] ;
                }

                A[ty][tx] = i ;
                if ( i == z ) {
                    cout << ty << ' ' << tx << '\n';
                    break;
                }
                x2 = tx ;
                y2 = ty;
            }
        }
if (false) {
        for ( y = 1 ; y <= n ; y ++ ) {
            for ( x = 1 ; x <= n ; x ++ )
                cout << A[y][x] << ' ';
            cout << '\n';
        }
        cout << '\n';
}
    }

    return 0;

}
