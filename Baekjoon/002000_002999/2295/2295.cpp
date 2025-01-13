#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){}
unsigned char F[25000001];
void Set(ll a) {
    if ( a <= 200'000'000)
        F[a/8] |= 1 << (a%8);
}
bool isSet(ll a) {
    return a <= 200'000'000 && (F[a/8] & (1 << (a%8)) );
}
void process(int Case) {
    int N, i, j;
    cin >> N;
    vector<ll> A(N);
    for (auto &n: A) cin >> n;
    std::sort(A.begin(), A.end());

    for (i = 0; i < N; i++)
        for (j = 0; j <= i; j++)
            Set( A[i] + A[j]);

    for (i = N - 1; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            if (isSet(A[i] - A[j]) ) {
                cout << A[i] << '\n';
                return;
            }
        }
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
