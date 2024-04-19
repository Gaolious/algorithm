#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);
using namespace std;

pair<int,int> pos[127];

void process() {
    int i;
    for ( i = 0 ; i < 26 ; i ++ ) pos['A' + i] = { i/6, i%6};
    pos[' '] = { 4, 2};
    pos['-'] = { 4, 3};
    pos['.'] = { 4, 4};
    pos['\n'] = { 4, 5};
    int ans = 0, y, x ;
    string s ;
    getline(cin, s);
    y = x = 0 ;
    s += '\n';
    for (auto c: s) {
        ans += abs( pos[c].first - y ) + abs(pos[c].second - x);
        y = pos[c].first;
        x = pos[c].second;
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


