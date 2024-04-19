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

enum DATA_TYPE { HAS_VALUE, HAS_REFERENCE, HAS_NAN};
struct Data {
    vector<pii> reference;
    int value ;
    bool isNan=false;
    void update(string &s) {
        stringstream ss(s);
        string word;

        while(getline(ss, word, '+')) {
            if ( 'A' <= word[0] && word[0] <='Z' )
                reference.emplace_back( word[0] - 'A', word[1]-'1');
            else {
                value = 0;
                for (auto c: word) value = value * 10 + c - '0';
            }
        }
    }
};
bool UpdateValue(vector<vector<Data>> &S, int y, int x){
    bool ret = false;
    auto &curr = S[y][x];
    if ( curr.isNan ) return false;
    if ( !curr.reference.empty() ) {
        for ( int i = 0 ; i < curr.reference.size() ; i ++ ) {
            auto &s = S[ curr.reference[i].first ][ curr.reference[i].second ];

            if ( s.isNan ) continue;
            if ( !s.reference.empty() ) continue;
            curr.value += s.value;
            curr.reference[i] = curr.reference.back();
            curr.reference.pop_back();
            i--;
            ret = true;
        }
    }
    return ret;
}
void process() {
    int i, j ;
    string s;
    Y = 10, X = 9 ;
    vector<vector<Data>> S(Y, vector<Data>(X));

    for (auto &y: S) {
        for (auto &x: y) {
            cin >> s ;
            x.update(s);
        }
    }

    bool ret = true ;
    while ( ret ) {
        ret = false;
        for (i = 0; i < Y; i++)
            for (j = 0; j < X; j++)
                if (UpdateValue(S, i, j))
                    ret = true;
    }

    for (i = 0; i < Y; i++, cout << '\n') {
        for (j = 0; j < X; j++) {
            if ( S[i][j].reference.empty() )
                cout << S[i][j].value;
            else
                cout << '*';
            cout << ' ';
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


