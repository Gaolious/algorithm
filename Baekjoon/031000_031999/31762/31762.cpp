#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void process() {
    int R, C, K;
    int i, j;
    char c;
    string M, P;

    cin >> R >> C >> K ;

    cin.ignore();
    vector<bool> mustTurnOn(R);
    vector<bool> allGoodLED(R);
    // M : '*' good LED, '-' broken
    // P : '*' must be tunred on, '-' must be turned off.
    for (i = 0 ; i < R ; i ++ ) {
        mustTurnOn[i] = false;
        allGoodLED[i] = true;
        cin >> M >> P ;
        for ( auto c: M) {
            if ( c == '-') allGoodLED[i] = false;
        }

        for (auto c: P) {
            if ( c == '*' ) mustTurnOn[i] = true;
        }
    }
    for (i = 0 ; i < R ; i ++ ) {
        if ( mustTurnOn[i] && !allGoodLED[i]) {
            cout << "N\n";
            return;
        }
    }
    cout << "Y\n";
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


