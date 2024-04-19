#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, a, b, s, d ;
    priority_queue<pii> A;
    priority_queue<int> Q;

    cin >> N ;

    for (int i = 0 ; i < N ; i ++ ) {
        cin >> a >> b ;
        A.emplace(b, a);
    }

    for ( s = 0, d = (A.empty() ? -1 : A.top().first) ;  d > 0 ; d -- ) {
        while ( !A.empty() && A.top().first == d ) {
            Q.emplace(A.top().second);
            A.pop();
        }
        if ( !Q.empty() ) {
            s += Q.top();
            Q.pop();
        }
    }
    cout << s << '\n';

    return 0;
}


