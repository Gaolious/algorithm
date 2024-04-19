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

void process() {
    int N, T, x, i;
    cin >> N >> T ;
    vector<int> A(N);
    for (auto &n: A) cin >> n;
    cin >> x ;
    x--;

    std::sort(A.begin(), A.end());
    int front, back;
    front = A[x] - A[0];
    back = A[N-1] - A[x];

    if ( front <= T ) {
        //  1->2->3-> X
        cout << A[N-1] - A[0] << '\n';
        for ( i = 1 ; i <= N ; i ++ ) cout << i << ' ';
    }
    else if ( back <= T ) {
        // X <- 5 <- 6 <- .. <- N-1
        cout << A[N-1] - A[0] << '\n';
        for ( i = N ; i > 0 ; i-- ) cout << i << ' ';
    }
    else if ( front < back ) {
        cout << A[N-1] - A[0] + A[x] - A[0] << '\n';
        cout << (x+1) << ' ';
        for ( i = 1 ; i <= N ; i ++ ) if ( i != x+1 ) cout << i << ' ';
    }
    else {
        cout << A[N-1] - A[0] + A[N-1] - A[x] << '\n';
        cout << (x+1) << ' ';
        for ( i = N ; i > 0 ; i -- ) if ( i != x+1 ) cout << i << ' ';
    }
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


