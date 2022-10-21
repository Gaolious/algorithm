#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    int T, N;
    ll a, b, n, ret ;
    cin >> T ;
    while ( T -- ) {
        priority_queue<ll> Q;
        cin >> N ;

        while ( N -- ) {
            cin >> n;
            Q.push(-n);
        }
        for ( ret = 0 ; Q.size() >= 2 ; ) {
            a = Q.top();
            Q.pop();
            b = Q.top();
            Q.pop();
            n = a + b;
            ret += -n;
            Q.push(n);
        }
        cout << ret << endl;
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


