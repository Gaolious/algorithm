#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int N) {
    vector A(N+1, vector<int>(N+1));
    int i, j, k, x;
    for ( i = 1 ; i <= N ; i ++ )
        for ( j = 1 ; j <= N ; j ++ )
            cin >> A[i][j];

    for ( i = 1 ; i <= N ; i ++ )
        for ( j = 1 ; j <= N ; j ++ )
            if ( A[i][j] < 1 || A[i][j] > N ) {
                cout << "no\n";
                return;
            }

    // Associativity: For all x, y and z in G, x × (y × z) = (x × y) × z.
    for ( i = 1 ; i <= N ; i ++ ) {
        for ( j = 1 ; j <= N ; j ++ ) {
            for ( k = 1 ; k <= N ; k ++ ) {
                if (A[i][ A[j][k] ] != A[A[i][j]][k]) {
                    cout << "no\n";
                    return;
                }
            }
        }
    }

    // Identity: the group contains an “identity element” (we can use i) so that for every x in G, x × i = x and i × x = x.
    bool foundIdentity = false;
    int Identity;
    for ( i = 1 ; i <= N ; i ++ ) {
        bool f = true ;
        for ( x = 1 ; x <= N ; x ++ ) if ( A[i][x] != x || A[i][x] != x ) { f = false; break; }
        if ( f ) { Identity = i, foundIdentity = true; break;}
    }

    if ( !foundIdentity ) {
        cout << "no\n";
        return;
    }

    // Inverse: for every element x there is an inverse element (we denote by x-1) so that x × x-1 = i and x-1 × x = i.
    bool hasInverse = true ;
    for ( i = 1 ; i <= N && hasInverse; i ++ ) {
        bool f = false;
        for ( j = 1 ; j <= N ; j ++ ) {
            if ( A[i][j] == Identity && A[j][i] == Identity ) {
                f = true;
                break;
            }
        }
        if ( !f) {
            hasInverse = false;
        }
    }
    if ( !hasInverse ) {
        cout << "no\n";
        return;
    }

    cout << "yes\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	while( cin >> T && T )
	    process(T);
    return 0;
}
