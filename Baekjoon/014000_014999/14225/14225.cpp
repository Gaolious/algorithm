#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int A[20];
int N;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int i, s ;

    fastio;
    cin >> N ;
    for (i = 0 ; i < N ; i ++ )
        cin >> A[ i ];
    sort(A, A+N);

    for ( s = 0, i = 0 ; i < N ; i ++ ) {
        if ( A[i] > s + 1 )
            break;
        s += A[i];
    }
    cout << s+1 << '\n';
    return 0;
}


