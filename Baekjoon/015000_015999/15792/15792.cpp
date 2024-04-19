#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    int a, b, k;
    cin >> a >> b ;

    cout << a / b ;
    for (k = 0, a = (a%b) * 10  ; a > 0 && k < 1500 ; a = (a%b) * 10 , k++ ) {
        if ( k == 0 ) cout << '.';
        cout << a / b ;
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


