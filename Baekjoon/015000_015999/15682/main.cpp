#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

typedef __float128 real_t;
real_t EPSILON = 1e-18q;

real_t mysqrt(real_t x)
{
    if(x == 0.0q) return 0.0q;
    real_t y = 1.0q, gy = 0.0q;
    do
    {
        real_t t = (y+(x/y))/2.0q;
        gy = y;
        y = t;
    }while(y!=gy);
    return y;
}
int S(real_t v) {
    if ( v < 0 ) return -1;
    if ( v > 0 ) return 1;
    return 0;
}
int main()
{
    fastio;
    int n;
    long double a, b, c, d ;
    real_t D, sqrt_d, l, r, m , x, y;
    int i, j ;

    cin >> n ;
    cout.precision(9);
    cout << std::fixed;
    auto F = [&](real_t x) -> real_t { return x*(x*(a*x+b)+c)+d; };

    while ( n-- ) {
        cin >> a >> b >> c >> d ;
        // cout << " Input : " << a << ", " << b << ", " << c << ", " << d << "\n";
        // ax^3 + bx^2 + cx + d
        // 3ax^2 + 2bx + c
        // D = 4*b*b - 4*3*a*c = 4 (b^2 - 3*a*c)
        // [-2b + sqrt(4 (b^2 - 3*a*c) ) ] / 6a
        // [-b + sqrt(b^2 - 3*a*c) ] / 3a

        D = b*b - 3*a*c;
        vector<real_t> X = { -1000000, 1000000 };
        vector<real_t> ret;

        if ( D >= 0 ) {
            sqrt_d = mysqrt(D);
            X.push_back((-b + sqrt_d) / (3*a) );
            X.push_back((-b - sqrt_d) / (3*a) );
        }
        sort(X.begin(), X.end());

        for ( i = 1 ; i < X.size() ; i ++ ) {
            l = X[i-1], r = X[i];
            if ( S(F(l) ) * S(F(r)) > 0 )
                continue;

            for ( j = 0 ; j < 100 ; j ++ ) {
                x = (l+r)/2.0q;
                ( S(F(x)) * S(F(l)) > 0 ? l : r ) = x ;
            }
            y = F(x);
            if ( -1e-10 < y && y < 1e-10 )
                ret.push_back(x);
        }
        sort(ret.begin(), ret.end());

        for ( i = 0, j = -1 ; i < ret.size() ; i ++ ) {
            if ( j < 0 || ret[i] - ret[j] > 1e-9 ) {
                j = i;
                cout << (double)ret[i] << ' ';
            }
        }
        cout << "\n";
    }
    return 0;
}


