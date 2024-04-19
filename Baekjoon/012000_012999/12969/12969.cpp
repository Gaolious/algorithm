#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void print(int a, int b, int c, int N, int K) {
    while( N -- > 0 ) {
        if ( a && b + c <= K ) {
            cout << 'A'; K -= (b+c); a--;
        }
        else if ( b && c <= K ) {
            cout << 'B';  K -= c; b--;
        }
        else {
            cout << 'C'; c--;
        }
    }
}
bool F(int N, int K) {
    int i, a, b, c;

    for ( a = 0 ; a <= N ; a ++ ) {
        for ( b = 0 ; a+b <= N ; b ++ ) {
            c = N - (a+b);
            if ( a * (b+c) + b * c >= K ) {
                print(a, b, c, N, K);
                return true;
            }
        }
    }
    return false;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, K;
    cin >> N >> K ;
    if ( F(N, K) ) {
        //
    }
    else
        cout << "-1\n";
    return 0;
}


