#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define TREE_HEIGHT (20)
int Tree[ 1 << (TREE_HEIGHT+1) ];
int basis = 1 << TREE_HEIGHT;

void update(int idx, int value ) {
    idx |= basis;
    Tree[idx] += value ;

    while ( idx /= 2 ) {
        Tree[idx] = Tree[idx*2] + Tree[idx*2+1];
    }
}

int query(int idx, int s, int e, int nth) {

    int curr ;
    for ( curr = idx ; !(curr & basis) ; ) {
        if ( nth <= Tree[curr*2] )
            curr = curr * 2 ;
        else {
            nth -= Tree[curr*2];
            curr = curr * 2 + 1 ;
        }
    }
    idx = curr ^ basis ;
    update( idx, -1);
    return idx + 1;
}

int main()
{
    fastio;
    int N ;
    int a, b, c ;

    cin >> N;
    while ( N -- ) {
        cin >> a ;
        if ( a == 1 ) {
            cin >> b;
            cout << query(1, 1, N, b) << "\n";
        }
        else if ( a == 2 ) {
            cin >> b >> c ;
            update(b-1, c);
        }
    }
    return 0;
}


