#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct Node {
    int idx;
    double x, y ;
    double dist(Node &node ) {
        double tx = x - node.x ;
        double ty = y - node.y ;
        return sqrt( tx*tx + ty*ty);
    }
};
struct Edge {
    int s, e ;
    double dist ;
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
    int N, i, j ;
    double ret;

    cin >> N ;
    vector<Node> A(N);
    vector< Edge > E ;
    P.resize(N);
    for ( i = 0 ; i < N ; i ++ )
    {
        A[i].idx = i;
        cin >> A[i].x >> A[i].y;
        P[i] = i;

        for ( j = 0 ; j < i ; j ++)
            E.push_back(Edge{ A[j].idx, A[i].idx, A[j].dist(A[i]) } );
    }

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


