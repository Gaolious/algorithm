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

string S, T;
bool check() {
    int head, tail;
    bool isForward = true;
    head = 0, tail = T.size() - 1;

    while ( S.size() < (tail - head + 1) ) {
        if (isForward) {
            if ( T[tail] == 'A' ) tail--;
            else if ( T[tail] == 'B' ) { tail--, isForward = !isForward; }
        }
        else {
            if ( T[head] == 'A' ) head++;
            else if ( T[head] == 'B' ) { head++, isForward = !isForward; }
        }
    }
    if ( isForward ) {
        for(auto c: S )
            if ( c != T[head++])
                return false;
    }
    else {
        for(auto c: S )
            if ( c != T[tail--])
                return false;
    }
    return true ;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    cin >> S >> T;
    cout << (check() ? 1: 0) << '\n';
    return 0;
}


