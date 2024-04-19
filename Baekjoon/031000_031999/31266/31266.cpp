#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct Data {
    ll a, b, c, d;
    ll Maximum() const {
        return max( max(a, b), max(c, d));
    }
    bool operator< (Data &r) const {
        if ( a != r.a ) return a < r.a ;
        if ( b != r.b ) return b < r.b ;
        if ( c != r.c ) return c < r.c ;
        return d < r.d ;
    }
};
vector<ll> PreSum;
vector<Data> A;
ll best = -1;
int N ;

void F(int nth, int a, int b, int c, int d, ll score) {
    if ( a + b + c + d == 11 ) {
        best = max(best, score);
        return ;
    }

    if ( nth >= N ) {
        return ;
    }

    if ( best > 0 && score + PreSum[nth] <= best )
        return ;
    if ( d > 1 ) return ;
    if ( a > 8 ) return ;
    if ( b > 8 ) return ;
    if ( c > 8 ) return ;
    if ( a+b+c+d > 11 )
        return ;
    if ( N-nth+a+b+c+d < 11 )
        return ;

    F(nth+1, a, b, c, d, score );
    F(nth+1, a+1, b, c, d, score + A[nth].a);
    F(nth+1, a, b+1, c, d, score + A[nth].b);
    F(nth+1, a, b, c+1, d, score + A[nth].c);
    F(nth+1, a, b, c, d+1, score + A[nth].d);
}
int main()
{
    fastio;
    cin >> N ;
    A.resize(N);

    for (auto &i: A) {
        cin >> i.a >> i.b >> i.c >> i.d ;
        PreSum.push_back(i.Maximum());
    }
    for ( int i = N-2 ; i >= 0 ; i -- )
        PreSum[i] += PreSum[i+1];
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    F(0, 0, 0, 0, 0, 0ll);
    cout << best << '\n';
    return 0;
}


