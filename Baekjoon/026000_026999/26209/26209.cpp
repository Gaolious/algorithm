#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

void process() {
    char c;
    bool ans=true;
    for ( int i = 0 ;i < 8 ; i ++ ) {
        cin >> c;
        if ( c == '1' || c == '0' ) continue;
        ans = false;
    }
    cout << (ans ? 'S' : 'F') << '\n';
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


