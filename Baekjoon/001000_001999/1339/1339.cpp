#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;

    int A[26]{};
    int N, i, k, ret, j, len;
    string s;

    cin >> N;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> s;
        len = s.length() ;
        for (k=1, j = len-1 ; j>=0 ; j --, k*=10 )
            A[ s[j] - 'A' ] += k ;
    }
    sort(A, A+26, greater<>());

    for ( ret = i = 0 ; i < 9 ; i ++ )
        ret += A[i] * ( 9 - i );

    cout << ret << '\n';

    return 0;
}


