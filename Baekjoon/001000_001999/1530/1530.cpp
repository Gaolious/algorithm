#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef pair<int, int> pii;

struct PAIR47 {
    int use4, use7;
    bool operator < (PAIR47 &o) {
        if ( use4+use7 != o.use4 + o.use7 ) return use4+use7 < o.use4 + o.use7 ;
        return ( use4 != o.use4 ) ? use4 < o.use4 : use7 < o.use7 ;
    }
};
vector<PAIR47> Pair[10];
PAIR47 sol[11];

bool F(int N, int idx, int prevCount) {
    if ( N == 0 ) {
        vector<int> ans (sol[0].use4 + sol[0].use7, 0);
        int i, j, k, digit ;
        for ( i = 0, digit=1 ; i < idx ; i ++, digit *= 10 ) {
            k = 0 ;
            for ( j = 0 ; j < sol[i].use7 ; j ++ ) ans[k++] += 7 * digit;
            for ( j = 0 ; j < sol[i].use4 ; j ++ ) ans[k++] += 4 * digit;
        }
        sort(ans.begin(), ans.end());
        for ( auto n: ans) cout << n << ' ';
        cout << '\n';
        return true;
    }
    for (auto &p: Pair[ N%10 ]) {
        int nextN = N - p.use4 * 4 - p.use7 * 7;
        if ( p.use4 + p.use7 > prevCount || nextN < 0 || nextN % 10 != 0 ) continue;
        sol[idx] = p;
        if ( F(nextN / 10, idx + 1, p.use4 + p.use7) )
            return true;
    }
    return false;
}
void process() {
    int i, j;
    int N;

    for ( i = 0 ; i < 25 ; i ++ )
        for ( j = 0 ; i*4+j*7 < 100 ; j ++ )
            if ( i * 4 + j * 7 >0 )
                Pair[(i * 4 + j * 7) % 10].push_back({i, j});

    for ( i = 0 ; i < 10 ; i ++ )
        sort(Pair[i].begin(), Pair[i].end());

    cin >> N ;
    if ( !F(N, 0, 99) )
        cout << "-1\n";
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


