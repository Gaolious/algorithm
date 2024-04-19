#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
template <typename T>
struct Vector2D {
    T x, y ;
    T cross(Vector2D other) {
        return x * other.y - y * other.x;
    }
    T dot(Vector2D other) {
        return x * other.x + y * other.y ;
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
    double dist() {
        T _dot = this->dot(*this);
        return (_dot > 0) ? sqrt(_dot) : 0.0;
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
    Vector2D a1 = b - a ;
    Vector2D b1 = c - a ;
    return ccw2(a1, b1);
}


void process() {
    fastio;
    vector<Vector2D<ll>> P;

    int N ;
    int i, j ;

    cin >> N ;
    P.resize(N);
    for (auto &a: P) {
        cin >> a.x >> a.y ;
    }
    std::sort(P.begin(), P.end());
    std::sort(P.begin()+1, P.end(), [&](Vector2D<ll> a, Vector2D<ll> b){
        int t = ccw3(P[0], a, b);
        if (t) return t == 1;
        return a.y < b.y || a.y == b.y && a.x < b.x;
    });

    vector<Vector2D<ll>> ans = {P[0], P[1]};
    int s;

    for ( i = 2 ; i< N ; i ++ ) {
        while ( ans.size() >= 2 ) {
            s = ans.size();
            auto &a = ans[s-2],
                &b = ans[s-1],
                &c = P[i];
            int t = ccw3(a, b, c) ;
            if ( t < 0 ) {
                ans.pop_back();
                continue;
            }
            if ( t == 0 ) {
                double d1 = (b - a).dist();
                double d2 = (c - a).dist();
                if ( d1 <= d2 ) {
                    ans.pop_back();
                    continue;
                }
            }
            break;
        }
        ans.push_back(P[i]);
    }

//    for (auto a : ans)
//        cout << "(" << P[a].x << "," << P[a].y << "), \n";
    cout << ans.size() << '\n';
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


