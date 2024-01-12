#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

namespace std {
    template <> struct hash<std::pair<int, int>> {
        inline size_t operator()(const std::pair<int, int> &v) const {
            std::hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };

}


void process() {
    fastio;
    int N, M;
    int i, a, b ;
    vector<int> C[32'000];
    int A[32'000]={0,};
    priority_queue<int> Q;

    cin >> N >> M ;

    for ( i = 0 ; i < M ; i ++ ) {
        cin >> a >> b ; // a -> b
        C[a-1].push_back(b-1);
        A[b-1]++;
    }
    for ( i = 0 ; i < N ; i ++ )
        if (A[i] == 0)
            Q.push(-i);

    for ( i = 0 ; i < N ; i ++ ) {
        a = -Q.top();
        cout << (a+1) << ' ' ;
        Q.pop();
        for ( auto prior: C[a]) {
            A[prior]--;
            if ( A[prior] == 0 )
                Q.push(-prior);
        }
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


