#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process(int Case) {
    int N;
    int i, j, a, b;
    cin >> N;

    vector<int> A(N), B(N);
    for ( auto &n: A) cin >> n;
    for ( auto &n: B) cin >> n;

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    a = b = 0 ;
    for (auto n: A) {
        i = std::lower_bound(B.begin(), B.end(), n) - B.begin();
        a += i ;
    }
    for (auto n: B) {
        i = std::lower_bound(A.begin(), A.end(), n) - A.begin();
        b += i ;
    }
    if ( a == b ) cout << "tie";
    else if ( a > b ) cout << "first";
    else cout << "second";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
