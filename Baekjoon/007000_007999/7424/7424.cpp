#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init() {}
vector<ll> ans;
void F(ll N) {
    ll i;
    for (i=1 ; i <= N ; i *= 10 ) {
        ll a = (N/i) / 11;
        ll b = (N/i) % 11;
        if ( b < 10 ) {
            ll c = (N - N/i * i ) / 2 ;
            if ( (11 * a + b) * i + 2 * c == N )
                ans.push_back(10 * a * i + b * i + c);
        }
        b--;
        if ( a + b && b >= 0 ) {
            ll c = (N - N/i * i + i) / 2 ;
            if ( (11 * a + b) * i + 2 * c == N )
                ans.push_back(10 * a * i + b * i + c);
        }
    }
}
int GetDigit(ll N) {
    int size ;
    ll k;
    for ( size = 1, k=N ; k > 9 ; size ++, k/=10);
    return size;
}
void process(int Case) {
    ll N;
    cin >> N ;
    F(N);
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';
    for ( auto n: ans ) {
        int d = GetDigit(n);
        cout << n << " + " << setfill('0') << setw(d-1) << N - n << " = " << N << '\n';
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
