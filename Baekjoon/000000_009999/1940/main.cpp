#include <bits/stdc++.h>
using namespace std;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); } while (false)

int main()
{
    fastio;
    int N, M ;
    int l, r ;
    int t, ret ;
    cin >> N >> M ;

    vector<int> A(N);
    for (auto &n : A) cin >> n;

    sort(A.begin(), A.end());

    l = 0, r = N - 1;
    ret = 0;

    while ( l < r ) {
        t = A[l] + A[r];
        if ( t == M ) {
            ret ++;
            l++; r --;
        }
        else if ( t > M ) r --;
        else l ++;
    }

    cout << ret << '\n';
    return 0;
}


