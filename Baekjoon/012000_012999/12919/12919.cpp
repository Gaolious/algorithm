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
int D[2][51][51];

int check(int head, int tail, bool isForward) {
    auto &ret = D[isForward][head][tail];
    if ( ret < 0 ) {
        if ( S.size() > (tail - head + 1 ) )
            return ret = 0;
        if ( S.size() == (tail - head + 1 ) ) {
            if ( isForward ) {
                for(auto c: S ) if ( c != T[head++]) return ret=0;
            }
            else {
                for(auto c: S ) if ( c != T[tail--]) return ret=0;
            }
            return ret=1;
        }
        if (isForward) {
            if ( T[tail] == 'A' && check(head, tail-1, isForward) )
                return ret=1;
            if ( T[head] == 'B' && check(head+1, tail, !isForward) )
                return ret=1;
        }
        else {
            if ( T[head] == 'A' && check(head+1, tail, isForward) )
                return ret=1;
            if ( T[tail] == 'B' && check(head, tail-1, !isForward) )
                return ret=1;
        }
        ret = 0;
    }
    return ret;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    cin >> S >> T;

    memset(D, -1, sizeof(D));

    cout << (check(0, T.size()-1, true) ? 1: 0) << '\n';
    return 0;
}


