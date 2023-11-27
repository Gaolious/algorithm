#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int D[1'000'000]={0,};

int main()
{
    fastio;
    int N, i, j ;
    cin >> N ;


    for ( i = 1; i <= N ; i ++ ) {
        for ( j = 1 ; i - j > 0 ; j *= 2 ) {
        }
    }
    cout << D[N] << "\n";
    return 0;
}


