#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct Node {
    int idx;
    ll x, y, z ;
    ll dist(Node &node ) {
        return min(abs(x - node.x), min(abs(y - node.y), abs(z - node.z)));
    }
};
struct Edge {
    int s, e ;
    ll dist ;
    bool operator <(Edge edge) const {
        return dist < edge.dist;
    }
};
vector<int> P;
int parent(int x){
    if ( P[x] == x )
        return x;
    return P[x] = parent(P[x]);
}
void merge(int x, int y) {
    x = parent(x);
    y = parent(y);
    if ( x > y ) swap(x,y);
    P[y] = x;
}
void process() {
    fastio;
    int N, i ;
    ll ret, cnt;

    cin >> N ;
    vector<Node> A(N);
    vector< Edge > E ;
    P.resize(N);
    for ( i = 0 ; i < N ; i ++ )
    {
        A[i].idx = i;
        cin >> A[i].x >> A[i].y >> A[i].z ;
        P[i] = i;
    }

    std::sort(A.begin(), A.end(), [](Node &a, Node &b) {return ( a.x < b.x );});
    for ( i = 0 ; i < N-1 ; i ++ )
        E.push_back(Edge{ A[i].idx, A[i+1].idx, abs(A[i].x - A[i+1].x)});
    std::sort(A.begin(), A.end(), [](Node &a, Node &b) {return ( a.y < b.y );});
    for ( i = 0 ; i < N-1 ; i ++ )
        E.push_back(Edge{ A[i].idx, A[i+1].idx, abs(A[i].y - A[i+1].y)});
    std::sort(A.begin(), A.end(), [](Node &a, Node &b) {return ( a.z < b.z );});
    for ( i = 0 ; i < N-1 ; i ++ )
        E.push_back(Edge{ A[i].idx, A[i+1].idx, abs(A[i].z - A[i+1].z)});

    std::sort(E.begin(), E.end());

    ret = 0;
    for ( auto edge : E ) {
        if ( parent(edge.s) != parent(edge.e) ) {
            merge(edge.s, edge.e);
            ret += edge.dist;
        }
    }

    cout << ret << '\n';
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


