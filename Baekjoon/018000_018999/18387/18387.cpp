#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef pair<int, int> pii;

int move(string &s, int from, int to) {
    int d = from < to ? 1 : -1 ;
    int ret = 0 ;
    while ( from != to ) {
        swap( s[from], s[from+d]);
        from +=d ;
        ret ++;
    }
    return ret;

}
void process() {
    int N ;
    int cnt[127+1]={0,};
    int oddCnt, i;
    int l, r, m, d;
    int ans ;
    pii P[128];

    string s ;
    cin >> N ;

    while ( N -- ) {
        cin >> s ;
        memset(cnt, 0, sizeof(cnt));
        for ( auto c : s ) cnt[c] ++;

        for ( oddCnt = 0, i = 0 ; i <= 127 ; i ++) {
            if ( cnt[ i ] % 2 == 1 )
                oddCnt++;
        }
        if ( s.size() % 2 != oddCnt ) {
            cout << "Impossible\n";
            continue;
        }
        ans = 0 ;
        while ( s.size() > 2 ) {
            for (i = 0; i < 128; i++) P[i] = {s.size() + 1, -1};
            for (i = 0; i < s.size(); i++) {
                P[s[i]].first = min(P[s[i]].first, i);
                P[s[i]].second = max(P[s[i]].second, i);
            }
            l = 0, r = s.size() - 1;
            int minDist = s.size() * 10 ;
            int minC;

            for ( i = 0 ; i < 128 ; i ++ ) {
                if ( P[i].second < 0 ) continue;
                d = abs(P[i].first) + abs(P[i].second - r) ;
                if ( minDist > d ) {
                    minDist = d;
                    minC = i;
                }
            }
            ans += minDist ;
            string k ;
            for ( i = 0 ; i < s.size() ; i ++ ) {
                if ( P[minC].first == i || P[minC].second == i ) continue;
                k.push_back(s[i]);
            }
            s = k;
        }
        cout << ans << '\n';
    }
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


