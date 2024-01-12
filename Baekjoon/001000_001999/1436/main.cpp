#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
using namespace std;

bool is( int n )
{
    while ( n > 100 )
    {
        if ( (n/100) % 10 == 6 && (n/10)%10 == 6 && n%10 == 6 ) return true ;
        n/=10;
    }
    return false ;
}
void process()
{
    int i, n ;
    int cnt = 0 ;
    cin >> n;

    for ( i = 666 ; i <= 2666799 ; i ++ )
    {
        if ( is(i) )
        {
            cnt ++;
            cout << cnt << ' ' << i << '\n';
            if ( n == cnt )
            {
                cout << i << '\n';
                return;
            }
        }
    }
}

int main()
{
    process();
}

