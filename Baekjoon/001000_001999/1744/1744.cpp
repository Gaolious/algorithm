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
    int N, l, r ;
    int s ;

    fastio;
    cin >> N ;

    deque<int> A(N);
    for (auto &n: A) cin >> n ;
    sort(A.begin(), A.end());

    s = 0;

    while ( A.size() >= 2 ) {
        l = A[0] * A[1];
        r = A[A.size()-2] * A[A.size()-1];
        if ( l < r && A[ A.size()-2] + A[ A.size()-1] < r ) {
            s += r ;
            A.pop_back();
            A.pop_back();
        }
        else if ( A[ 0 ] + A[ 1 ] < l ) {
            s += l ;
            A.pop_front();
            A.pop_front();
        }
        else
            break;
    }
    for (auto n:A) s += n;
    cout << s << '\n';
    return 0;
}


