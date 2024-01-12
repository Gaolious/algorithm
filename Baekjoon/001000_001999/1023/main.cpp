#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll SIZE = 50 ;

ll D[SIZE+1][SIZE*2 + 1][2];
ll N, K ;

ll F(ll len, ll cnt, int invalid) {
    if ( len == N ) {
        return invalid || cnt != 0;
    }

    ll &ret = D[len][SIZE + cnt][invalid];
    if ( ret < 0 ) {
        ret = F(len+1, cnt+1, invalid);
        ret += F(len+1, cnt-1, invalid || cnt <= 0) ;
    }

    return ret;
}
void P(ll len, ll cnt, int valid, ll target) {
    if (len < N) {
        ll prev = F(len+1, cnt+1, valid);
        if ( prev <= target ) {
            cout << ")";
            P(len+1, cnt-1, valid || cnt <= 0, target - prev);
        }
        else {
            cout << "(";
            P(len+1, cnt+1, valid, target);
        }
    }
}
int main()
{
    fastio;
    memset(D, -1, sizeof(D));

    cin >> N >> K ;

    if ( F(0, 0, 0) <= K )
        cout << -1;
    else
        P(0, 0, 0, K);

    return 0;
}


//for i in `seq 0 10`
//do
//    echo ""
//    echo "seq $i"
//    echo "3 $i" > ./input.txt
//    ./boj < ./input.txt
//done