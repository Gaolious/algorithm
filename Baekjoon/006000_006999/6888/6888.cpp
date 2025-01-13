#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char S[6000];
int L[101];
void process() {
    int i, j, len;
    char c;
    for ( len=0, i = 1 ; i <= 100; i ++ ) {
        for ( j = 1 ; j <= i ; j ++ )
            S[len++] = '*';
        S[len++] = '\n';
        L[i] = len;
    }
    while ( cin >> len && len ) {
        c = S[ L[len] ];
        S[ L[len] ] = 0;
        cout << S ;
        S[ L[len] ] = c;
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    process();
    return 0;
}


