#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct Data {
    ll from;
    char oper;
};
unordered_map<ll, Data> D;
queue<ll> Q;

void PushQ(ll num, ll from, char oper) {
    if ( D.insert({num, {from, oper}}).second ) {
        Q.push(num);
    }
}
bool bfs(ll s, ll t) {
    PushQ(s, -1, -1);

    while (!Q.empty()) {
        auto curr = Q.front();
        if ( curr == t ) return true;
        Q.pop();

        if ( curr * curr <= t ) PushQ(curr * curr, curr, '*');
        if ( curr * 2 <= t ) PushQ(curr * 2, curr, '+');
        PushQ(0, curr, '-');
        if ( curr != 0 )
            PushQ(1, curr, '/');
    }
    return false;
}
void Output(ll s) {
    if ( D[s].from >= 0 ) {
        Output(D[s].from);
        cout << D[s].oper;
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ll s, t;

    fastio;

    cin >> s >> t ;
    assert ( 1 <= s );
    assert ( 1 <= t );
    assert ( s <= 1000000000ll );
    assert ( t <= 1000000000ll );

    if ( s == t )
        cout << "0";
    else if ( bfs(s, t) )
        Output(t);
    else
        cout << "-1";

    return 0;
}


