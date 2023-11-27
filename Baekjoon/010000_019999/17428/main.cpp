#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

// D[ len ] [ openCnt - closeCnt ]
ll D[60][60];
ll N, K;

ll F( ll len, ll cnt) {
    if ( cnt < 0 ) return 0;
    if ( N <= len ) return cnt == 0 ? 1 : 0;

    ll &ret = D[len][ cnt ];
    if ( ret < 0 )
        ret = F(len+1, cnt-1) + F(len+1, cnt + 1);
    return ret ;
}

void P(ll len, ll cnt, ll target) {
    if ( len < N ) {
        ll prev = F(len+1, cnt+1);
        if ( prev <= target) {
            cout << ")";
            P(len+1, cnt-1, target - prev);
        }
        else{
            cout << "(";
            P(len+1, cnt+1, target);
        }
    }
}

int main()
{
    fastio;

    memset(D, -1, sizeof(D));

    cin >> N >> K ;

    if (F(0, 0) <= K )
        cout << -1;
    else
        P(0, 0, K);

    return 0;
}


