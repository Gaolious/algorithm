#include <bits/stdc++.h>

#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MAX_N = 1'000'000'001;

int digits(ll t) {
    int cnt ;
    for ( cnt = 0 ; t > 0 ; t /= 10, cnt++)
    {}
    return cnt;
}

ll Add(ll a, ll b) {
    return min( a+b, MAX_N);
}
ll Multi(ll a, ll b) {
    if ( digits(a) + digits(b) > 12)
        return MAX_N;
    else
        return min(a*b, MAX_N);
}
int main()
{
    ll N, D;
    ll a, x;
    vector<ll> Monster, Equip;
    fastio;
    cin >> N >> D;
    while ( N -- ) {
        cin >> a >> x;
        if ( a == 1 ) {
            Monster.push_back(x);
        } else {
            Equip.push_back(x);
        }
    }
    sort(Monster.begin(), Monster.end());
    sort(Equip.begin(), Equip.end());

    vector<ll>::iterator e = Equip.begin();
    int cnt = 0;
    for ( auto m = Monster.begin() ; m != Monster.end() ; ) {
        if ( D > *m ) {
            D = Add(D, *m);
            cnt ++;
            m++;
            continue;
        }
        if ( e == Equip.end() ) break;

        D = Multi(D, *e);
        e++;
        cnt ++;
    }
    for ( ; e != Equip.end() ; e++ ) cnt ++;

    cout << cnt << '\n';
    return 0;
}


