#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = 1000;

void process() {
    fastio;
    int N, M, i, prev, curr, n ;

    cin >> N >> M ;

    vector< set<int> > Prev( N+1, set<int>());
    vector< set<int> > Next( N+1, set<int>());
    vector<bool> B(N+1, false);
    vector<int> ret;
    queue<int> Q;

    while ( M-- ) {
        cin >> n ;
        for ( prev=-1, i = 0 ; i < n ; i ++, prev = curr ) {
            cin >> curr ;
            if (prev > 0 )
            {
                Prev[curr].insert(prev);
                Next[prev].insert(curr);
            }
        }
    }

    for ( i = 1 ; i <= N ; i ++ ) {
        if (Prev[i].size() == 0) {
            Q.push(i);
            B[i] = true;
        }
    }

    while ( !Q.empty() ) {
        n = Q.front();
        Q.pop();
        ret.push_back(n);

        for(auto next: Next[n]) {
            if ( B[next] ) continue;

            Prev[next].erase(n);
            if ( Prev[next].size() != 0 ) continue;
            Q.push(next);
            B[next] = true ;
        }
    }

    if ( ret.size() != N )
        cout << "0\n";
    else {
        for( auto next: ret)
            cout << next << '\n';
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


