#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long double ld;
typedef long long int ll;

void process() {
    // deduct a certain fixed administrative cost
    // followed by a fee that is a percentage of the amount that was invested at the beginning of the term
    // and then add a return
    int instruments, terms, rebalance;
    int i, j ;
    cin >> instruments >> terms >> rebalance;

    vector<ld> fixedFee(instruments), percentFee(instruments), principal(instruments);
    vector<ld> originPrincipal(instruments);
    ld totalPrincipal=0, sum;

    vector< vector<ld> > ret(terms, vector<ld>(instruments));
    for (auto &a : fixedFee) cin >> a ;
    for (auto &a : percentFee) cin >> a ;
    for (auto &a : principal) {
        cin >> a ;
        totalPrincipal += a;
    }
    originPrincipal = principal;

    for (auto &a : ret )
        for (auto &n : a)
            cin >> n;

    ld fee, interest;
    for ( i = 0 ; i < terms ; i ++ ) {
        if ( i % rebalance == 0 ) {
            sum = 0;
            for ( j = 0 ; j < instruments ; j ++ ) sum += principal[j];
            for ( j = 0 ; j < instruments ; j ++ )
                principal[ j ] = originPrincipal[j] / totalPrincipal * sum ;
        }
        for ( j = 0 ; j < instruments ; j ++ ) {
            fee = (principal[j] * percentFee[j]) + fixedFee[j] ;
            interest = principal[j] * ret[i][j];
            principal[j] += -fee + interest;
            principal[j] = max(0.0l, principal[j]);
        }
    }

    for ( j = 0 ; j < instruments ; j ++ ) {
        long long v = ( (long long ) (principal[j]*1000.0l) + 5 ) / 10;
        cout << v/100 << '.' << setw(2) << setfill('0') << v%100 << ' ' ;
//        cout << setprecision(2) << fixed << principal[j] << ' ';
    }
    cout << '\n';
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


