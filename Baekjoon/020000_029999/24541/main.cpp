#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int diff(int i, int j) {
    return i > j ? i - j : j - i;
}
bool check(vector<int> A, int X, int maxDiff) {

    int len = A.size();
    if ( len <= 1 ) return true ;
    vector<int>::iterator curr, next ;
    next = A.begin();

    for ( curr=next++ ; next != A.end() ; curr=next++ ) {
        if ( diff(*curr, *next) > maxDiff )
    }
}
void process() {
    fastio;
    int X, N ;
    int lo, hi, ans, m ;

    cin >> N >> X ;
    vector<int> A(N);

    ans = lo ;
    lo = 2000000000 ;
    hi = 0;
    for( auto &n: A)
    {
        cin >> n;
        lo = min(n, lo);
        hi = max(n, hi);
    }

    while ( lo <= hi ) {
        m = (lo + hi) / 2 ;
        vector<int> newA;
        std::copy(A.begin(), A.end(), newA);

        if ( check(newA, X, m) ) {
            ans = m ;
            hi = m-1 ;
        } else {
            lo = m + 1 ;
        }
    }
    cout << ans ;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


