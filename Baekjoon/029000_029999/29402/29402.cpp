#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;

void process() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (auto &n: A) cin >> n;
    sort(A.begin(), A.end());
    for ( int i = 2 ; i < A.size() ; i ++ ) {
        if ( A[i] != A[i-2] + A[i-1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


