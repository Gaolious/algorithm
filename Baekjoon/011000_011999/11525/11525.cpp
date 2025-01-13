#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MaxN = 10'000;
std::vector<int> phi;
void init() {
    phi.resize(MaxN+1);
    for (int i = 1; i <= MaxN; i++) phi[i] = i;

    for (int i = 2; i <= MaxN; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MaxN; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for (int i = 1; i <= MaxN; i++) phi[i] += phi[i-1];

}
void process(int Case) {

    int K, N ;
    cin >> K >> N ;
    cout << K << ' ' << phi[ N ] + 1 << '\n';
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
