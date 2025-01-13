#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MaxN = 10'000;
vector<ll> phi;
void init(){
    int i, j;
    phi.resize(MaxN+1);

    for (i = 1; i <= MaxN; ++i) phi[i] = i;

    for (i = 2; i <= MaxN; ++i) {
        if ( phi[i] != i ) continue;
        for (j = i; j <= MaxN; j += i) phi[j] -= phi[j]/i;
    }
    for (i = 1; i <= MaxN; ++i) phi[i] += phi[i-1];
}

void process(int Case) {
    int T, N;
    std::cin >> T >> N;
    ll a = (phi[N]*3-1), b = 2 ;
    auto g = gcd(a,b);
    a /= g;
    b /= g;

    if ( b == 1 )
        cout << T << ' ' << a << '\n';
    else
        cout << T << ' ' << a << '/' << b << '\n';

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
