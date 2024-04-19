#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct Data {
    int No;
    int *Score;
    int currRank;
    int worstRank;
    bool operator <(Data &o) {
        return *Score == *o.Score ? No < o.No : *Score > *o.Score;
    }
};
void process() {
    int N, K;
    int i, n, r;

    cin >> N >> K ;
    vector<Data> A(N);
    vector<int> S(N);
    for (i = 0 ; i < N ; i ++ ) {
        S[i] = 0;
        A[i] = { i+1, &(S[i]), 1, 1};
    }
    while (K--) {
        for (i = 0; i < N; i++) {
            cin >> n ;
            S[i] += n;
        }

        std::sort(A.begin(), A.end());
        for ( i = 0 ; i < N ; i ++ ) {
            A[i].currRank = (i > 0 && *A[i - 1].Score == *A[i].Score) ? A[i - 1].currRank : i + 1;
            A[i].worstRank = max(A[i].worstRank, A[i].currRank);
        }
    }
    for ( i = 0 ; i < N && A[i].currRank == 1 ; i ++ ) {
        cout << "Yodeller " << A[i].No << " is the TopYodeller: score " << *A[i].Score << ", worst rank " << A[i].worstRank << "\n";
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    process();
    return 0;
}


