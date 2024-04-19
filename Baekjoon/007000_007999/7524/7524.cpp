#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

struct Data {
    string name;
    int points{} ;
    int dots{};
    int order{};
    bool operator < (Data &o ) {
        if ( points != o.points ) return points > o.points;
        if ( dots != o.dots ) return dots > o.dots;
        return order < o.order;
    }
};
int who(int a, int b) {
    if ( a < b ) return -1;
    else if ( a > b ) return 1;
    return 0;
}
pair< pair<int,int>, int> getScore() {
    int a, b;
    char c;
    cin >> a >> c >> b ;
    return { {a,b}, who(a,b) };
}
void process() {
    int P, R, G;
    int N, i, j, t ;
    int maxScore = -1, maxWho, maxCnt, s;

    cin >> N ;
    for ( t = 1 ; t <= N ; t ++ ) {
        cin >> P >> R ;
        vector<Data> A(P);

        cin.ignore();
        for ( i = 0 ; i < P ; i ++ ) {
            getline(cin, A[i].name);
            A[i].order = i;
        }

        for ( i = 0 ; i < R ; i ++ ) {
            vector<int> pointsByRound(P);

            cin >> G;
            while (G--) {
                auto [resultScore, resultWin] = getScore();
                for (j = 0; j < P; j++) {
                    auto [score, win] = getScore();
                    if (score == resultScore) pointsByRound[j] += 3;
                    else if (win == resultWin) pointsByRound[j] += 1;
                }
            }
            maxScore = -1;
            for ( j = 0 ; j < P ; j ++ )
                maxScore = max(maxScore, pointsByRound[j]);

            for ( j = 0 ; j < P ; j ++ ) {
                A[j].points += pointsByRound[j];
                if (pointsByRound[j] == maxScore) A[j].dots++;
            }
        }
        std::sort(A.begin(), A.end());
        if ( t > 1 ) cout << '\n';
        cout << "Scenario #" << t << ":\n";
        for ( auto &a : A) {
            cout << a.points << ' ' << a.dots << ' ' << a.name << '\n';
        }
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


