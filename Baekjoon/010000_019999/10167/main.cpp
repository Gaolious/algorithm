#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Data {
    int x, y, w;
};
struct Node {
    ll s, lm, rm, tm;
};
Node Tree[1 << 13];

Node merge(Node &left, Node &right) {
    Node ret;
    ret.s = left.s + right.s ;
    ret.lm = max(left.lm, left.s + right.lm);
    ret.rm = max(right.rm, right.s + left.rm);
    ret.tm = max({left.tm, right.tm, left.rm+right.lm });
    return ret;
}
void update(int idx, ll val ) {
    idx |= 1 << 12 ;

    Tree[idx].s += val ;
    Tree[idx].lm += val ;
    Tree[idx].rm += val ;
    Tree[idx].tm += val ;
    while ( idx /= 2 ) {
        Tree[idx] = merge( Tree[idx*2], Tree[idx*2+1]);
    }
}
int main()
{
    fastio;
    int N ;
    int y1, y2;

    vector<int> X, Y;
    cin >> N ;
    vector<Data> D(N);
    vector<vector<Data>> A;
    for (auto &d: D) {
        cin >> d.x >> d.y >> d.w ;
        X.push_back(d.x);
        Y.push_back(d.y);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    A.resize(Y.size());
    for (auto &d: D) {
        d.x = lower_bound(X.begin(), X.end(), d.x) - X.begin();
        d.y = lower_bound(Y.begin(), Y.end(), d.y) - Y.begin();
        A[d.y].push_back(d);
    }
    ll ret = 0;

    for ( y1 = 0 ; y1 < A.size() ; y1 ++ ) {
        memset(Tree, 0, sizeof(Tree));

        for ( y2 = y1 ; y2 < A.size() ; y2 ++ ) {

            for(auto p: A[y2]) update(p.x, p.w);
            ret = max(ret, Tree[1].tm);
        }
    }
    cout << ret;

    return 0;
}


