#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);

typedef long long int ll ;

using namespace std;

void process() {
    fastio;
    ll N ;
    cin >> N ;
    cout << max(0ll, N * ( N - 1 ) / 2 * ( N - 2 ) / 3 ) << '\n' << 3 << '\n';
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


