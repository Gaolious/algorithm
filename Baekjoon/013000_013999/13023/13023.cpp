#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int N, M;
vector< vector<int> > A;
vector<bool> visited;

bool F(int s, int depth) {
    if ( depth == 5 )
        return true;
    for (auto nxt : A[s] ) {
        if ( visited[nxt] ) continue;
        visited[nxt] = true ;
        if (F(nxt, depth+1))
            return true;
        visited[nxt] = false ;
    }

    return false;
}

int main()
{
    fastio;
    int i, a, b;

    cin >> N >> M ;

    A = vector(N, vector<int>());
    visited = vector<bool>(N);

    for ( i = 0 ; i < M ; i ++ ) {
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for ( i = 0 ; i < N ; i ++ ) {
        visited[i] = true;
        if ( F(i, 1) ) {
            cout << "1\n";
            return 0;
        }
        visited[i] = false;
    }

    cout << "0\n";
    return 0;
}


