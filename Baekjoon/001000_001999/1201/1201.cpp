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

deque<int> A;

int LIS() {
    vector<int> T;
    for (auto n: A) {
        if ( T.empty() || T.back() < n )
            T.push_back(n);
        else {
            T[ lower_bound(T.begin(), T.end(), n, less<>()) - T.begin() ] = n;
        }
    }
    return T.size();
}

int LDS() {
    vector<int> T;
    for (auto n: A) {
        if ( T.empty() || T.back() > n )
            T.push_back(n);
        else {
            T[ lower_bound(T.begin(), T.end(), n, greater<>()) - T.begin() ] = n;
        }
    }
    return T.size();
}

bool F(int N, int M, int K) {
    int n = 0, i, cnt, j ;

    for ( j = 0 ; j < M ; j ++ ) {
        if ( j == 0 ) {
            for ( i = 0 ; i < K ; i ++ ) A.push_back(K - i);
            n = K ;
        }
        else if ( N-n < M-j )
            return false;
        else {
            cnt = (N-n)/(M-j);
            if ( cnt * (M-j) < N-n) cnt++;
            for ( i = cnt ; i > 0 ; i -- ) A.push_back(n + i);
            n += cnt;
        }
    }

    if ( A.size() == N && LIS() == M && LDS() == K )
        return true;
    return false;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, M, K;
    cin >> N >> M >> K ;

    if ( F(N, M, K) ) {
        for (auto n: A)
            cout << n << ' ';
    }
    else {
        cout << "-1";
    }
    cout << "\n";

    return 0;
}


