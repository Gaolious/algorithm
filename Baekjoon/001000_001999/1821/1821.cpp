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

int A[10][10];
vector<int>B;

int N, S ;
void process() {
    int i, j, t;
    A[0][0] = 1;
    for ( i = 1 ; i < 10 ; i ++ ) {
        for ( j = 0 ; j <= i ; j ++ ) {
            A[i][j] = (j==0 ? 0 : A[i-1][j-1] ) + A[i-1][j];
        }
    }
    cin >> N >> S;
    B.resize(N);
    for ( i = 0 ; i < N ; i ++ ) B[i] = i + 1;
    do {
        for ( t = 0, i = 0 ; i < N ; i ++ )
            t += A[N-1][i] * B[i];
        if ( t == S ) {
            for (auto n: B) cout << n << ' ';
            return;
        }
    } while (next_permutation(B.begin(), B.end()));
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


