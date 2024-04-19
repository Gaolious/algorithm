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

struct Data {
    string name ;
    vector<int> review;
};
void process() {
    int K, N, i, j, n ;
    // K 리뷰 받을 수, N 리뷰할 논문 수
    while ( cin >> K >> N ) {
        if ( K == 0 && N == 0 ) break;
        vector<Data> A(N);
        vector<bool> hasProblem(N, false);

        for ( i =0 ; i < N ; i ++ ) {
            cin >> A[i].name;
            for ( j = 0 ; j < K ; j ++ ) {
                cin >> n; n --;
                A[n].review.push_back(i);
            }
        }

        for ( i = 0 ; i < N ; i ++ ) {
            sort(A[i].review.begin(), A[i].review.end());
            if ( A[i].review.size() != K ) {
                hasProblem[i] = true;
                continue;
            }
            if (hasProblem[i]) continue;

            for ( j = 1 ; j < A[i].review.size() ; j ++ )
                if ( A[i].review[j-1] == A[i].review[j] ) {
                    hasProblem[i] = true;
                    break;
                }

            if (hasProblem[i]) continue;
            for (auto idx : A[i].review ) {
                if ( A[i].name == A[ idx ].name ) {
                    hasProblem[i] = true;
                    break;
                }
            }
        }

        int cnt = 0 ;
        for ( i =0 ; i < N ; i ++ )
            if ( hasProblem[i] ) cnt ++;

        if ( cnt == 0 )
            cout << "NO PROBLEMS FOUND\n";
        else if ( cnt == 1 )
            cout << "1 PROBLEM FOUND\n";
        else
            cout << cnt << " PROBLEMS FOUND\n";
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


