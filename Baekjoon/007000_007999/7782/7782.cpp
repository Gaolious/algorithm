#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int main()
{
    fastio;
    int N ;
    int b1, b2;
    int i ;
    int sx, sy, ex, ey;
    cin >> N ;
    cin >> b1 >> b2 ;

    for (i = 0 ; i< N ; i ++ ) {
        cin >> sx >> sy >> ex >> ey ;
        if ( sx <= b1 && b1 <= ex && sy <= b2 && b2 <= ey ) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}


