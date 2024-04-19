#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

pair<int, int> F(const char A[], const char B[]) {
    int H[10]={0,};
    int i, hit, blow;
    hit = blow = 0 ;
    for ( i = 3 ; i >= 0 ; i -- ) H[ A[i] - '0'] = 1;

    for ( i = 0 ; i < 4 ; i ++ ) {
        if ( A[i] == B[i] ) hit++;
        else if ( H[ B[i]  - '0' ] ) blow ++;
    }
    return {hit, blow };
}
struct DATA {
    char A[5];
};
struct _INPUT {
    char A[5];
    int hit, blow;
};
vector<DATA> D;

void init() {
    char a,b,c,d;
    for (a='0' ; a <= '9' ; a++) {
        for (b = '0'; b <= '9'; b++) {
            if (a == b) continue;
            for (c = '0'; c <= '9'; c++) {
                if (a == c || b == c) continue;
                for (d = '0'; d <= '9'; d++) {
                    if (a == d || b == d || c == d) continue;
                    D.push_back({a, b, c, d});
                }
            }
        }
    }
}
void solve(int N) {
    int i, j;
    pair<int,int> hitblow;
    vector<DATA> candidate;
    vector<_INPUT> in(N);
    bool f;

    for(auto &a : in )
        cin >> a.A[0] >> a.A[1] >> a.A[2] >> a.A[3] >> a.hit >> a.blow ;

    for (auto &d: D) {
        f = true;
        for (auto &a: in) {
            hitblow = F(d.A, a.A);
            if (hitblow.first != a.hit || hitblow.second != a.blow) {
                f = false;
                break;
            }
        }
        if (f) candidate.push_back(d);
    }

    if (candidate.size() == 1) {
        auto &d = candidate[0];
        cout << d.A[0] << d.A[1] << d.A[2] << d.A[3] << '\n';
        return;
    }

    for (auto &d : D ) {
        int H[5][5]={{0}, };

        f=true;
        for ( auto &b: candidate ) {
            auto ret = F(d.A, b.A);
            if ( H[ret.first][ret.second]++ != 0 ) {
                f=false;
                break;
            }
        }

        if ( f ) {
            cout << d.A[0] << d.A[1] << d.A[2] << d.A[3] << '\n';
            return;
        }
    }
    cout << "????\n";
}
void process() {
    int N;

    init();

    while ( cin >> N && N )
        solve(N);
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


