#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int N, M ;
    int A[101]{};
    int i, a, b ;

    cin >> N >> M ;
    for ( i = 1 ; i <= N ; i ++ ) A[ i ] = i ;
    while (M--) {
        cin >> a >> b ;
        while (a < b ) {
            swap(A[a], A[b]);
            a++;
            b--;
        }
    }
    for ( i = 1 ; i <= N ; i ++ ) {
        cout << A[ i ] << ' ';
    }
    return 0;
}


