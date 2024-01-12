#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    vector<ll> A;
    int N, K, T, i, l, r;
    ll cnt, S, a ;
    cin >> N >> K >> T ;
    S = 0 ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> a;
        A.push_back(a);
        S += a ;
    }
    std::sort(A.begin(), A.end());

    cnt = 0;
    l = 0 , r = A.size() - 1 ;
    if ( S % K == 0 )
    {
        while ( l <= r ) {
            if ( A[l] + A[r] == K ) {
                cnt += min(A[l++], A[r--]);
                S -= K ;
            } else if ( A[l] + A[r] < K ) {
                cnt += A[l];
                A[r] += A[l];
                A[l++] = 0;
            } else {
                cnt += K - A[r];
                A[l] -= K - A[r];
                A[r--] = 0;
                S -= K ;
            }
        }
    }
    if ( S == 0 && cnt <= T ) {
        cout << "YES";
    } else {
        cout << "NO";
    }

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


