#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
bool operator < (pii a, pii b){
    return a.first * b.second - a.second * b.first < 0 ;
}
ostream &operator << (ostream &out, pii A) {
    auto [a, b] = A;
    cout << a / b;
    a %= b;
    if ( a != 0 ) {
        cout << '.';
        for ( int k = 0 ; k <10 ; k ++ ) {
            a *= 10;
            cout << a/b;
            a%=b;
        }
    }
    return out;
}
pii G(pii &a) {
    auto g = gcd(a.first, a.second);
    return {a.first/g, a.second/g};
}
void process(int Case) {
    int A[3], B[3];
    pii R[3], r;
    int i;
    for ( i = 0 ; i < 3 ; i ++ ) cin >> A[i], R[i].first = A[i];
    for ( i = 0 ; i < 3 ; i ++ ) cin >> B[i], R[i].second = B[i];
    r = R[1] < R[2] ? R[1] : R[2];
    r = R[0] < r ? R[0] : r;
    r = G(r);

    for ( i = 0 ; i < 3 ; i ++ ) {
        R[i] = G(R[i]);
        pii t = {A[i]*r.second - B[i]*r.first , r.second};
        cout << t << ' ';
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
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
