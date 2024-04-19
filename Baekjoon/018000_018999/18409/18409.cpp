#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

void process() {
    int N, ans;
    char c;
    cin >> N ;
    ans = 0 ;
    while ( N-- ) {
        cin >> c;
        if ( c == 'a' || c == 'i' || c == 'u' || c == 'e' || c =='o' )
            ans ++;
    }
    cout << ans << '\n';
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


