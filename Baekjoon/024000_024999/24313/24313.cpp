#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    double a1, a0, c1, c2, n0 ;
    cin >> a1 >> a0 >> c1 >> c2 >> n0 ;

    bool ret1 = (a0 / n0 >= c1 - a1 && a0 / 100000.0 >= c1 - a1) ? true : false;
    bool ret2 = (a0 / n0 <= c2 - a1 && a0 / 100000.0 <= c2 - a1) ? true : false;
    cout << ( ret1 && ret2 ? 1 : 0) << endl;
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


