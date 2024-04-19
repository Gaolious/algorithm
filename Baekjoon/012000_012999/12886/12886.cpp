#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int MaxN = 500;
const int T = MaxN + 1;

struct Data {
    int n[3];
    Data(){}
    Data(int a, int b, int c){ n[0]=a, n[1]=b, n[2]=c; }
    Data(Data &d) { *this=d; }
    Data(int d){ from(d); }

    int toN() {
        int ret = 0;
        for (auto a: n) ret = ret * T + a;
        return ret;
    }
    void from(int V) {
        int i;
        for ( i = 2 ; i >= 0 ; i ++ ) {
            n[i] = V % T;
            V /=T;
        }
    }
    Data New(int i, int j) {
        Data ret = *this;
        if ( ret.n[i] > ret.n[j] ) swap (i, j);

        ret.n[j] -= ret.n[i], ret.n[i]*=2;
        return ret;
    }
};
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, t;
    unordered_set<int> D;
    Data A;
    queue<Data> Q;

    for ( i = 0 ; i < 3 ; i ++ )
        cin >> A.n[i];
    Q.emplace(A);
    D.emplace(A.toN());

    while (!Q.empty()) {
        auto curr = Q.front();
        if ( curr.n[0] == curr.n[1] && curr.n[1] == curr.n[2] ) {
            cout << "1\n";
            return 0;
        }
        Q.pop();
        for (i=0 ; i < 2 ; i ++ ) {
            for ( j = 0 ; j < 3 ; j ++ ) {
                if ( curr.n[i] == curr.n[j] ) continue;
                auto t = curr.New(i, j);
                auto [iter, b] = D.insert(t.toN());
                if ( b )
                    Q.emplace(t);

            }
        }
    }

    cout << "0\n";

    return 0;
}


