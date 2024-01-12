#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
template <typename T>
struct Vector2D {
    T x, y ;
    T cross(Vector2D &other) {
        return x * other.y - y * other.x;
    }
    Vector2D operator -(Vector2D &other ) {
        Vector2D ret = Vector2D{ x - other.x, y - other.y};
        return ret;
    }
    bool operator ==(Vector2D &other ) { return ( x == other.x && y == other.y ); }
    bool operator <(Vector2D &other ) {
        return y == other.y ? x < other.x : y < other.y ;
    }
    bool operator <=(Vector2D &other ) {
        return y == other.y ? x <= other.x : y <= other.y ;
    }
    bool operator > (Vector2D &other ) {
        return y == other.y ? x > other.x : y > other.y ;
    }
    bool operator >= (Vector2D &other ) {
        return y == other.y ? x >= other.x : y >= other.y ;
    }
};
template <typename T>
int ccw2(Vector2D<T> &a, Vector2D<T> &b) {
    T ret = a.cross(b);
    if ( ret < 0 ) return -1;
    else if ( ret > 0 ) return 1;
    else return 0;
}
template <typename T>
int ccw3(Vector2D<T> &a, Vector2D<T> &b, Vector2D<T> &c) {
    Vector2D a1 = a - c ;
    Vector2D b1 = b - c ;
    return ccw2(a1, b1);
}

template <typename T>
struct Line {
    Vector2D<T> s, e ;
    Line(T x1, T y1, T x2, T y2) {
        s.x = x1, s.y = y1 ;
        e.x = x2, e.y = y2 ;
        if ( s > e ) swap(s, e);
    }
    bool is_cross(Line& other) {
        int a = ccw3( s, e, other.s ) * ccw3( s, e, other.e );
        int b = ccw3( other.s, other.e, s ) * ccw3( other.s, other.e, e );
        if ( a == 0 && b == 0 ) {
            if ( s > e ) swap(s,e);
            if (other.s > other.e) swap(other.s, other.e);
            return other.s <= e && s <= other.e ;
        }
        return a <= 0 && b <= 0 ;
    }
    T dx() { return s.x - e.x ; }
    T dy() { return s.y - e.y ; }
    T det() { return s.x * e.y - s.y * e.x ; }
};

const int MaxN = 3000 ;
int P[MaxN + 1];
int cnt[MaxN+1];

int Find(int n) {
    return ( n == P[n] ) ? n : P[n] = Find(P[n]);
}
void Merge(int x, int y) {
    x = Find(x);
    y = Find(y);

    if ( x != y )
    {
        if (x < y) swap(x, y);
        P[x] = y;
        cnt[y] += cnt[x];
    }
}
void process() {
    fastio;
    int N ;
    int i, j;
    int sx, sy, ex, ey;
    int max_cnt, nGroups;
    vector< Line<int> > lines ;

    cin >> N ;

    for ( i = 0 ; i < N ; i ++ ) {
        P[i] = i;
        cnt[i] = 1;
        cin >> sx >> sy >> ex >> ey ;
        lines.emplace_back(sx,sy,ex,ey);
    }

    for (i = 0 ; i < N ; i ++ ) {
        auto &l1 = lines[i];
        for ( j = i+1 ; j < N ; j ++ ) {
            auto &l2 = lines[j];
            if ( l1.is_cross(l2) )
                Merge(i,j);
        }
    }

    for (nGroups=0, max_cnt = 0, i = 0 ; i < N ; i ++ )
    {
        if (Find(i) == i ) {
            nGroups ++ ;
            max_cnt = max(max_cnt, cnt[i]);
        }
    }

    cout << nGroups << '\n' << max_cnt << '\n';
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


