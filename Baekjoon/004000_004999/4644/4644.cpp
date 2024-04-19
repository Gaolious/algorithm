#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

const long double eps = 1.0e-9;
struct Data {
    int rank;
    string name;
    int point[10]; // 0 : solvedCnt, 1:totalTime, 2:geometricMean, 3 ~ 9:point
    bool operator < (Data &o) {
        if ( point[0] != o.point[0] ) return point[0] > o.point[0];
        if ( point[1] != o.point[1] ) return point[1] < o.point[1];
        if ( point[2] != o.point[2] ) return point[2] < o.point[2];
        return name < o.name;
    }
    bool operator == (Data &o) {
        if ( point[0] != o.point[0] ) return false;
        if ( point[1] != o.point[1] ) return false;
        if ( point[2] != o.point[2] ) return false;
        return true;
    }
};
struct Round {
    vector<Data> data;
    long double geomtricMean ;
    void run(int N) {
        data.resize(N);
        int i;
        for (auto &d: data) {
            cin >> d.name;
            memset(d.point, 0, sizeof(d.point));
            geomtricMean = 0;
            for ( i = 3; i < 10 ; i ++ ) {
                cin >> d.point[i];
                if ( d.point[i] > 0 ) {
                    d.point[0] ++;
                    d.point[1] += d.point[i];
                    geomtricMean += log( (long double)(d.point[i]));
                }
            }
            if ( d.point[0] > 0 ) {
                geomtricMean /= d.point[0];
                geomtricMean = exp(geomtricMean);
                d.point[2] = (int) (geomtricMean + 0.5 + eps);
            }
        }
        std::sort(data.begin(), data.end());
        int rank;
        for ( i = 0 ; i < data.size() ; i ++ ) {
            rank = i + 1;
            data[i].rank = rank;
            while ( i + 1 < data.size() && data[i+1] == data[i] )
                data[++i].rank = rank;
        }
    }
};
int digitLen(int a){
    int cnt;
    for ( cnt = 1 ; a >= 10 ; cnt ++, a/=10 ) ;
    return cnt;
}
void process() {
    int N;
    int i, j, k;
    int maxNameLen=0, maxPointLen[10]={0,};
    vector<Round> R;
    while ( cin >> N && N ) {
        R.emplace_back();
        R.back().run(N);
    }

    for (auto &r: R) {
        for ( auto &d: r.data) {
            maxNameLen = max(maxNameLen, (int)d.name.length());
            for ( i = 0 ; i < 10 ; i ++ )
                maxPointLen[i] = max( maxPointLen[i], digitLen(d.point[i]));
        }
    }
    i = 0;
    for (auto &r: R ) {
        cout << "CONTEST " << ++i << '\n';
        for ( auto &d: r.data) {
            cout << setw(2) << setfill('0') << d.rank << ' ';
            cout << setw(maxNameLen) << setfill(' ') << left << d.name << ' ';
            for (k = 0; k < 10; k++) {
                if (k > 0) cout << ' ';
                cout << setw(maxPointLen[k]) << setfill(' ') << right << d.point[k];
            }
            cout << '\n';
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


