#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
struct Data {
    int no;
    int p[4]{};
    bool operator < (Data &o) {
        int i;
        for ( i = 3 ; i >= 0 ; i -- )
            if ( p[i] != o.p[i] )
                return p[i] > o.p[i];
        return false;
    }
    bool operator == (Data &o) {
        int i;
        for ( i = 3 ; i >= 0 ; i -- )
            if ( p[i] != o.p[i] )
                return false;
        return true;
    }
};
void process(int Case) {
    int N, n, i, j;
    cin >> N ;
    vector<Data> A(3);
    for ( j = 0 ; j < 3 ; j ++ )
        A[j].no = j+1;
    for (i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < 3 ; j ++ ) {
            cin >> n ;
            A[j].p[n-1]++;
            A[j].p[3] +=n;
        }
    }
    std::sort(A.begin(), A.end());
    if ( A[0] == A[1] )
        cout << "0 " << A[0].p[3] << '\n';
    else
        cout << A[0].no << " " << A[0].p[3] << '\n';
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
