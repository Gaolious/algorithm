#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Data {
    ll n ;
    int c2, c3;
};

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N ;
    ll t;

    cin >> N ;
    vector<Data> A(N);
    for (auto &a : A ) {
        cin >> a.n ;
        for ( a.c2 = 0, t = a.n ; t % 2 == 0 ; t/=2 ) a.c2 ++;
        for ( a.c3 = 0, t = a.n ; t % 3 == 0 ; t/=3 ) a.c3 ++;
    }
    sort(A.begin(), A.end(), [](Data &a, Data &b) {
        if ( a.c3 != b.c3 ) return a.c3 > b.c3 ;
        return a.c2 < b.c2;
    });

    for ( auto a : A) {
        cout << a.n << '\n';
    }
    return 0;
}


