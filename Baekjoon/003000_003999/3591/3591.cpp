#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

struct P {
    int y, x;
    bool operator == (P &o) {
        return x == o.x && y == o.y ;
    }
};
struct L {
    P s, e;
    bool operator == (L &o) {
        return s == o.s && e == o.e ;
    }
};
vector<L> First;

void init(){
}
int Idx(vector<int>&A, int n) {
    for ( int i = 0 ; i < A.size() ; i ++ )
        if ( A[i] == n ) return i;
    return -1;
}
bool Equal(vector<L> &A) {
    if ( A.size() != First.size() ) return false;
    for (auto &p: First ) {
        bool f = false ;
        for (auto &q: A) {
            if ( p == q ) {
                f = true;
                break;
            }
        }
        if (!f)
            return false;
    }
    return true;
}
void process(int Case) {
    int N, i, j ;
    cin >> N ;
    vector<L> A(N);
    vector<int> X, Y;
    int idx = 0;
    for ( auto &[s, e] : A) {
        cin >> s.x >> s.y >> e.x >> e.y ;
        X.push_back(s.x);
        X.push_back(e.x);
        Y.push_back(s.y);
        Y.push_back(e.y);
    }

    for ( auto &[s, e] : A) {
        s.x = Idx(X, s.x);
        e.x = Idx(X, e.x);
        s.y = Idx(Y, s.y);
        e.y = Idx(Y, e.y);
    }

    if ( Case == 1 ) First = A;
    else {
        if ( Equal(A) )
            cout << "CORRECT\n";
        else
            cout << "INCORRECT\n";
    }
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
