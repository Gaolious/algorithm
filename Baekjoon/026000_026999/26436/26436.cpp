#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
ll run() {
    ll L, D, P;
    int N, i;
    ll ans = 0, dir;
    char C, prev;

    cin >> L >> N ;

    prev = 0;
    P = 0;

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> D >> C;
        if ( prev != C && D >= abs(P) ) {
            prev = C;
            D -= abs(P);
            P = 0;
        }
        dir = C == 'C' ? 1 : -1;
        P += D * dir ;
        ans += abs( P / L );
        P %= L ;
    }

    return ans;
}
void process() {
    int T;
    cin >> T;

    for ( int Case=1 ; Case <= T ; Case ++ ) {
        cout << "Case #" << Case << ": " << run() << '\n';
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


