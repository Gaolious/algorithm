#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

string A, S;
ll N, L, R;
ll cntDollar;
vector<ll> Length;
char F(ll repeat, ll nth) {
    int i ;
    for (i = 0 ; i < S.size() ; i ++ ) {
        if ( S[i] == '$' ) {
            if ( Length[repeat-1] < nth )
                nth -= Length[repeat-1];
            else
                return repeat == 1 ? A[nth-1] : F(repeat - 1, nth);
        }
        else {
            if ( nth == 1 ) return S[i];
            else nth--;
        }
    }
    return '-';
}
char F1(ll repeat, ll nth) {
    ll aLen = A.size() ;
    if ( nth <= aLen ) {
        return A[ nth - 1 ];
    }
    nth -= aLen ;
    ll sLen = S.size() - 1 ;
    if ( nth <= sLen * repeat ) {
        nth = (nth-1) % sLen + 1;
        return S[nth];
    }

    return '-';
}
void process() {
    int i;

    cin >> A >> S >> N >> L >> R;

    cntDollar = 0;
    for ( auto c: S )
        if ( c == '$' )
            cntDollar ++;

    if ( cntDollar == 1 ) {
        for ( ll i = L ; i <= R ; i ++ )
            cout << F1(N, i);
        return;
    }

    Length.push_back(A.size());
    for ( i = 1 ; i <= N ; i ++ ) {
        Length.push_back( Length.back() * cntDollar + ( S.size() - cntDollar) );
        if ( Length.back() > R ) break;
    }
    N = min((ll)Length.size(), N);
    for ( ll i = L ; i <= R ; i ++ )
        cout << F(N, i);
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


