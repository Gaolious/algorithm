#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int P[30'000+1];
ll Candy[30'000+1];
ll Child[30'000+1];
ll D[3'000+1]={0,};

int find(int x) {

    if ( P[x] != x )
        P[x] = find(P[x]);
    return P[x];
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    P[min(x,y)] = max(x,y);
}

int main()
{
    fastio;
    int N, M, K;
    int i, a, b;
    int j, k;

    cin >> N >> M >> K;

    for ( i = 1 ; i <= N ; i ++ ) {
        cin >> Candy[i];
        P[i] = i ;
        Child[i] = 1;
    }

    for ( i = 0 ; i < M ; i ++ ) {
        cin >> a >> b;
        merge(a, b);
    }
    for ( i = 1 ; i <= N ; i ++ ) {
        j = find(i);
        if ( i != j ) {
            Candy[j] += Candy[i];
            Child[j] += Child[i];
        }
    }
    vector<int> A;
    for ( i = 1, j =0 ; i <= N ; i ++ ) {
        if ( find(i) != i ) continue;
        A.push_back(i);
    }

    for (auto cur : A) {
        ll child = Child[cur];
        ll candy  = Candy[cur];
        for ( j = K ; j >= child ; j -- )
            D[j] = max( D[j], D[ j-child ] + candy);
    }
    cout << *max_element(D, D+K) << "\n";

    return 0;
}


