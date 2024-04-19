#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

const ll MaxM = 1'000'000ll;
const ll MaxS = 1'000'000ll;

void process() {

    int N ;
    ll h, m, s;
    int i ;

    cin >> N ;
    vector<ll> S(N+1);
    vector<ll> A(N+1);
    for ( i = 1 ; i <= N ; i ++ ) {
        cin >> h >> m >> s ;
        A[i] = ( h * MaxM + m ) * MaxS + s;
    }
    sort(A.begin(), A.end());
    for ( i = 1 ; i <= N ; i ++ )
        S[i] = A[i] + S[i-1];

    ll ans = -1;
    for ( i = 1 ; i <= N ; i ++ ) {
        ll t = i * A[i];
        t += ( 12ll * MaxM * MaxS + A[i]) * ( N-i ) - S[N];
        if ( ans < 0 || ans > t )
            ans = t;
    }
    s = ans % MaxS ; ans /= MaxS;
    m = ans % MaxM ; ans /= MaxM ;
    h = ans;
    cout << h << ' ' << m << ' ' << s << '\n';
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


