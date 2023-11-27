#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int MaxN = 200000;
int D[MaxN+1];
int P[MaxN+1];

struct DATA {
    int second ;
    int pos ;
    bool operator < (DATA d) const {
        return this->second < d.second;
    }
};

int main()
{
    fastio;
    int N, K ;
    int i;

    cin >> N >> K ;

    priority_queue<DATA> Q ;
    D[N] = 0;
    P[N] = -1;
    for (i=0 ; i < MaxN ; i ++ ){
        D[i] = MaxN ;
        P[i] = -1;
    }
    if ( K <= N ) {
        for ( i = K ; i < N ; i ++ )
        {
            D[i] = N-i;
            P[i] = i+1;
        }
    }
    Q.push(DATA{0, N});

    while ( !Q.empty() ){
        auto curr = Q.top();
        Q.pop();

        if ( curr.second >= D[K] )
            continue;

        if ( curr.pos > K && ( K - curr.pos + curr.second ) >= D[K] )
            continue;

        for ( auto next_pos : { curr.pos-1, curr.pos+1, curr.pos*2, }) {
            if ( next_pos < 0 || next_pos >= MaxN )
                continue;
            if ( next_pos > K && ( K - next_pos + curr.second + 1 ) >= D[K] )
                continue;
            if ( D[next_pos] <= curr.second + 1 )
                continue;

            D[next_pos] = curr.second + 1;
            P[next_pos] = curr.pos;
            Q.push(DATA{curr.second + 1, next_pos});
        }
    }

    vector<int> O ;
    for ( i = K ; i >= 0 ; i = P[i])
        O.push_back(i);
    cout << D[K] << "\n";
    for ( i = O.size()-1 ; i >= 0 ; i -- )
        cout << O[i] << ' ';
    cout << "\n";
    return 0;
}


