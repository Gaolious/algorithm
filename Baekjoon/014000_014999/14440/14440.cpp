#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD = 100;

struct Mat {
    int M[2][2];
    Mat operator * (Mat &o ) {
        int i, j, k;
        Mat ret={0,};
        for ( i = 0 ; i < 2 ; i ++ ) {
            for ( j = 0 ; j < 2 ; j ++ ) {
                for ( k = 0 ; k < 2 ; k ++ )
                    ret.M[i][j] += M[i][k] * o.M[k][j];
                if ( ret.M[i][j] >= MOD )
                    ret.M[i][j] = ret.M[i][j] % MOD + MOD;
            }
        }
        return ret;
    }
};
ostream &operator <<(ostream &out, Mat o) {
    int i, j;
    for ( i = 0 ; i < 2 ; i ++) {
        for (j = 0; j < 2; j++) {
            cout << o.M[i][j] << ' ';
        }
        cout << '\n';
    }
    return out;
}

Mat I = {1, 0, 0, 1};
Mat Pow(Mat &o, int n) {
    if ( n == 0 ) return I;
    auto ret = Pow(o, n/2);
    ret = ret * ret;
    if ( n % 2 == 1 ) ret = ret * o;
    return ret;
}
void init() {}

int F() {
    int x, y, a0, a1, n;
    cin >> x >> y >> a0 >> a1 >> n ;
    Mat m = { x, y, 1, 0};
    if ( n == 0 ) return a0;
    if ( n == 1 ) return a1;

//    if ( n == 0 ) return x; // 오류
//    if ( n == 1 ) return y; // 오류
    auto ret = Pow(m, n-1);
    return ret.M[0][0] * a1 + ret.M[0][1] * a0;
}
void process(int Case) {
    auto ans = F();
    if ( ans >= MOD ) ans = ans % MOD + MOD ;
    cout << setw(2) << setfill('0') << ans % MOD << '\n';
}
int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
