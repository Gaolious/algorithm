#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int N ;
vector<int> A;
bool C[10][10];

bool bfs(int s, bool group[10] ) {
    bool Visited[10]{};
    queue<int> Q;
    Q.push(s);
    Visited[s] = true;
    while (!Q.empty() ) {
        auto curr = Q.front();
        Q.pop();
        for ( int i = 0 ; i < 10 ; i ++ ) {
            if ( !group[i] ) continue;
            if ( Visited[i] ) continue;
            if ( !C[curr][i]) continue;
            Q.push(i);
            Visited[i] = true;
        }
    }
    for ( int i = 0 ; i < 10 ; i ++ )
        if ( group[i] != Visited[i] )
            return false;
    return true;
}
int main() {
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, n, j, k, max_bit;
    bool group1[10]{}, group2[10]{};
    int g1, g2, s1, s2;

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> n;
        A.push_back(n);
    }

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> n ;
        for ( j = 0 ; j < n ; j ++ ) {
            cin >> k ; k--;
            C[i][k] = true;
        }
    }
    max_bit = (1 << N);
    int best = -1;
    for ( i = 1 ; i < max_bit - 1 ; i ++ ) {
        g1 = g2 = N + 1 ;
        s1 = s2 = 0;
        for ( j = 0 ; j < N ; j ++ ) {
            if ( ( 1 << j ) & i ) {
                g1 = min(g1, j);
                group1[j] = true;
                group2[j] = false;
                s1 += A[j];
            }
            else {
                g2 = min(g2, j);
                group1[j] = false;
                group2[j] = true;
                s2 += A[j];
            }
        }
        if ( bfs(g1, group1) && bfs(g2, group2) ) {
            if ( best < 0 || best > abs(s1-s2) )
                best = abs(s1-s2);
        }
    }
    cout << best << '\n';
    return 0;
}


