#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
unsigned int is_square[1'000'000];

#define SET_SQUARE(x) ( is_square[ (x)/32 ] |= ( 1 << ( (x)%32 ) ) )
#define IS_SQUARE(x) ( is_square[ (x)/32 ] & ( 1 << ( (x)%32 ) ) ? true: false)

bool is_triagle(int a, int b, int c) {
    if ( a < b ) swap(a,b);
    if ( a < c ) swap(a,c);
    if ( a >= b+c) return false;
    if ( a <= 0 || b <= 0 || c <= 0 ) return false;
    return true;
}
bool is_integer_area(int a, int b, int c) {
    int s = a+b+c;
    int S ;
    if ( s % 2 != 0 ) return false ;
    s /= 2;

    S = s * (s-a) * (s-b) * (s-c);
    return IS_SQUARE(S);
}

int main()
{
    fastio;
    int i, j, k ;
    int a, b, c;
    int ret = 0;

    for ( i = 1 ; i * i < 8000000 ; i ++ )
        SET_SQUARE(i*i);
    cin >> a >> b >> c ;

    for ( i = a ; i >= 1 ; i -- )
        for ( j = b; j >= 1 ; j -- )
            for ( k = c ; k>=1 ; k-- )
                if (is_triagle(i, j, k))
                    ret = max(ret, i+j+k);
    cout << ret ;
    return 0;
}


