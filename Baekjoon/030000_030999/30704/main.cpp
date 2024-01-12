#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int T, N, x, y  ;

    cin >> T ;
    while (T -- ) {
        cin >> N ;
        x = (int)ceil(sqrt(N));
        y = (int)ceil((double)N / x) ;
        cout << x*2 + y*2 << '\n';
    }
    return 0;
}


