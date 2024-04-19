#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
struct Data {
    int sign;
    int x;
    void update(string &s) {
        char c, a;
        stringstream ss(s);
        ss >> a >> c >> x;
        sign = ( a == '-') ? -1 : 1;
    }
};
vector<Data> A;
double C[200][10];

double F( int dice, int idx) {
    if ( idx >= A.size() ) {
        return 1.0 * (dice >= 0 );
    }
    auto &ret = C[dice+100][idx];
    if ( ret < 0 ) {
        ret = 0;
        for (int x = 1; x <= A[idx].x; x++)
            ret += F(dice + A[idx].sign * x, idx + 1);
        ret /= A[idx].x;
    }
    return ret;
}
void process() {
    int N, M;
    int nDice;
    string dex, s;

    cin >> N >> M >> dex;
    cin >> nDice;
    A.resize(nDice);
    for (auto &a: A) {
        cin >> s;
        a.update(s);
    }

    int d1, d2, dice;
    double p = 0.0l;
    for ( d1=0 ; d1<200; d1++)
        for (d2=0 ; d2<10 ; d2++)
            C[d1][d2] = -1;

    for ( d1 = 1 ; d1 <= 20 ; d1 ++ ) {
        for ( d2 = 1 ; d2 <= 20 ; d2 ++ ) {

            if ( dex[0] == 's' )
                dice = d1;
            else if ( dex[0] == 'a')
                dice = max(d1, d2);
            else
                dice = min(d1, d2);

            if ( dice >= 20 )
                p += 1.0 / 400.0;

            else if ( dice > 1 )
                p += F(dice + M - N, 0) / 400.0;
        }
    }
    cout << setprecision(12) << fixed << p << '\n';
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


