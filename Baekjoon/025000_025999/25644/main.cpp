#include <bits/stdc++.h>
using namespace std;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); } while (false)


void process() {
    fastio;
    int N ;
    int i;
    int ans, min_val ;

    cin >> N;
    vector<int> A(N, 0);

    for (i = 0 ; i < N ; i ++ ) cin >> A[i];

    min_val = A[0];
    ans = 0 ;

    for ( i = 1 ; i < N ; i ++ )
    {
        ans = max( ans, A[i] - min_val);
        min_val = min(min_val, A[i]);
    }

    cout << ans << "\n";
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


