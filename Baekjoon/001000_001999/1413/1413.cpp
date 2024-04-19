#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
typedef ll T ;
T gcd(T a, T b) {
    return a == 0 ? b : gcd(b%a, a);
}
typedef pair<T, T> pii;
pii simplify(pii ret) {
    T g = gcd(ret.first, ret.second);
    return { ret.first / g, ret.second / g};
}

pii operator +(pii a, pii b) {
    T g= gcd(a.second, b.second);
    pii ret = {b.second/g * a.first + a.second / g * b.first, a.second / g * b.second};
    return simplify(ret);
}
pii operator *(pii a, pii b) {
    pii ret = {a.first * b.first, a.second * b.second};
    return simplify(ret);
}
ostream &operator <<(ostream &out, pii a ) {
    out << a.first << '/' << a.second;
    return out;
}
pii zero = {0,1};
pii one = {1,1};
vector< vector< vector<pii>>> D;

pii F(int BoxCnt, int Bomb, int hasKey) {

    auto &ret = D[hasKey][BoxCnt][Bomb];
    if ( ret.first < 0 ) {
        pii selfKey = {1, BoxCnt};
        pii otherKey = {BoxCnt - 1, BoxCnt};
        pii r1, r2;
        if ( BoxCnt == 0 ) ret = one;
        else if ( Bomb <= 0 && hasKey <= 0 ) ret = zero;
        else if ( hasKey > 0 ) {
            r1 = F(BoxCnt-1, Bomb, 0);
            r2 = F(BoxCnt-1, Bomb, 1);
            ret = selfKey * r1 + otherKey * r2;
        }
        else {
            r1 = F(BoxCnt-1, Bomb-1, 0);
            r2 = F(BoxCnt-1, Bomb-1, 1);
            ret = selfKey * r1 + otherKey * r2;
        }
    }
    return ret;
}
void dump() {
    for ( int i = 0 ; i < D.size() ; i ++ ) {
        for ( int j = 0 ; j < D[i].size() ; j ++ ) {
            for ( int k = 0 ; k < D[i][j].size() ; k ++ )
                cout << D[i][j][k] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int box, bomb;
    cin >> box >> bomb;
    D.resize(2, vector( box+1, vector<pii>(bomb+1, {-1, -1})));

    auto ret = F(box, bomb, 0);
    cout << ret << '\n';

    return 0;
}


