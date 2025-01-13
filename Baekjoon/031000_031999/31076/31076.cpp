#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
/*
 x ~ y 까지
 y = x + a

 (x+a)*(x+a+1)*(x+a+2)/6 - x*(x+1)*(x+2)/6 = N
 (x+a)*(x+a+1)*(x+a+2) - x*(x+1)*(x+2) = 6N
 (x+a)^3 + 3(x+a)^2 + 2(x+a) - x^3 - 3x^2 - 2x = 6N

 x^3 + 3ax^2 + 3a^2x + a^3 + 3x^2 + 6ax + 3a^2 + 2x + 2a - x^3 - 3x^2 - 2x = 6N
 ~~~                        ~~~~~                ~~      ~~~~~~~~~~~~~~~~~~

 3ax^2 + 3a^2x + 6ax + a^3 + 3a^2 + 2a= 6N
 a( 3x^2 + 3ax + 6x + a^2 + 3a + 2)= 6N
 a( 3x^2 + 3(a+2)x + (a+1)(a+2) )= 6N

*/
const ld EPS = 1.0e-12;
void process(int Case) {
    ll n, N, x, a, v;
    cin >> N;
    ll l = 0, r = 0;
    for ( a = 1 ; a <= 843432 && a*(a+1)/2*(a+2)/3 <= N ; a ++ ) {
        if ( 6 * N % a != 0 ) continue;
        // n = 3x^2 + 3(a+2)x = 6N / a - (a+1)(a+2)
        n = 6 * N / a - (a+1)*(a+2);

        if ( n % 3 != 0 ) continue;
        n /= 3 ;

        // x^2 + (a+2)x = n
        // x^2 + (a+2)x - n = 0
        //

        x = ( (ll)sqrt( (a+2)*(a+2) + 4*n + EPS) - (a+2) ) / 2;
        if ( x * ( x+a+2) == n ) {
            if ( x > 0 ) cout << "YES\n";
            else cout << "NO\n";
            return;
        }
    }
    cout << ( N==0 ? "YES" : "NO" );
}


int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int T=1;
    // init();
    for ( int i=1 ; i <= T ; i ++ )
        process(i);
    return 0;
}
