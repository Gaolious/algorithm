#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int A[4][4];
#define AB (A[0][1])
#define AC (A[0][2])
#define AD (A[0][3])
#define BC (A[1][2])
#define BD (A[1][3])
#define CD (A[2][3])

bool check_triangle() {
    int i, j, k;

    for ( i = 0 ; i < 4 ; i ++ ) {
        for ( j = 0 ; j < 4 ; j ++ ) {
            if ( i == j ) continue;
            for ( k = 0 ; k < 4 ; k ++ ) {
                if ( k == i || k == j ) continue;

                if ( A[i][j] + A[j][k] < A[i][k])
                    return false;
            }
        }
    }

    //       C                                            D
    //       +                                            +
    //      /| \                                         /| \
    //     / |h1 \                                      / |h2 \
    //    /  |     \                                   /  |     \
    // A +---+------+ B                             A +---+------+ B
    //     x1    AB-x1                                  x2

    // x1^2 + h^2                  = AC^2
    // (AB-1x)^2 + h^2             = BC^2
    // AB^2 - 2*x1*AB + x1^2 + h^2 = BC^2
    // -AB^2 + 2*x1*AB = AC^2 - BC^2
    // x1 = (AC^2 - BC^2 + AB^2) / (2*AB)          x2 = (AD^2 - BD^2 + AB^2) / (2*AB)

    long double x1 = (AC*AC - BC*BC + AB*AB) / (2.0*AB);

    long double h1 = sqrt(AC*AC - x1*x1);

    long double x2 = (AD*AD - BD*BD + AB*AB) / (2.0*AB);
    long double h2 = sqrt(AD*AD - x2*x2);

    // cout << "h1 = " << h1 << '\n';
    // cout << "h2 = " << h2 << '\n';
    // cout << "CD = " << CD << '\n';

    long double sqX = (x1-x2)*(x1-x2);
    long double sqY1 = (h1-h2)*(h1-h2);
    long double sqY2 = (h1+h2)*(h1+h2);
    long double c2 = CD*CD - sqX;

    return sqY1 <= c2 && c2 <= sqY2;
}

int main()
{
    int i, j;
    fastio;
    for ( i = 0 ; i < 4 ; i ++ ) {
        for ( j = 0 ; j < 4 ; j ++ ) {
            cin >> A[ i ][ j ] ;
        }
    }

    if ( check_triangle() )
        cout << "YES";
    else
        cout << "NO";

    return 0;
}


