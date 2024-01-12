#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

template <typename T>
struct Pos {
    T x, y ;
    Pos(): x(0), y(0){}
    Pos(T x, T y): x(x), y(y){}
    T cross(Pos other) {
        return x * other.y - y * other.x;
    }
    T dot(Pos other) {
        return x * other.x + y * other.y ;
    }
    Pos operator -(Pos &other ) {
        Pos ret = Pos{ x - other.x, y - other.y};
        return ret;
    }
    bool operator ==(Pos &other ) { return ( x == other.x && y == other.y ); }
    bool operator <(Pos &other ) {
        return y == other.y ? x < other.x : y < other.y ;
    }
    bool operator <=(Pos &other ) {
        return y == other.y ? x <= other.x : y <= other.y ;
    }
    bool operator > (Pos &other ) {
        return y == other.y ? x > other.x : y > other.y ;
    }
    bool operator >= (Pos &other ) {
        return y == other.y ? x >= other.x : y >= other.y ;
    }
    double dist() {
        T _dot = this->dot(*this);
        return (_dot > 0) ? sqrt(_dot) : 0.0;
    }
};

template <typename T>
int ccw2(Pos<T> &a, Pos<T> &b) {
    T ret = a.cross(b);
    if ( ret < 0 ) return -1;
    else if ( ret > 0 ) return 1;
    else return 0;
}
template <typename T>
double area(Pos<T> &a, Pos<T> &b) {
    T ret = a.cross(b);
    return (ret < 0 ? -ret : ret) / 2.0l;
}
template <typename T>
int ccw3(Pos<T> &a, Pos<T> &b, Pos<T> &c) {
    // 0 : line
    // -1 : left
    // 1 : right
    Pos a1 = b - a ;
    Pos b1 = c - a ;
    return ccw2(a1, b1);
}
template <typename T>
double area3(Pos<T> &a, Pos<T> &b, Pos<T> &c) {
    // 0 : line
    // -1 : left
    // 1 : right
    Pos a1 = b - a ;
    Pos b1 = c - a ;
    return area(a1, b1);
}
int main()
{
    fastio;
    int N, K, d, n ;
    int i, x, y , j;
    vector<Pos<int>> A;

    cin >> K ;
    N = 6;
    x = y = 0;
    for ( i = 0 ; i < N ; i ++ ) {

        cin >> d >> n;
        switch (d ) {
            case 1:
                A.emplace_back(x += n, y);
                break;
            case 2:
                A.emplace_back(x -= n, y);
                break;
            case 3:
                A.emplace_back(x, y += n);
                break;
            case 4:
                A.emplace_back(x, y -= n);
                break;
        }
    }
    double ret = 0;
    for ( i = 0 ; i < N  ; i ++ ) {
        if ( ccw3(A[(i-1+N)%N], A[(i)%N], A[(i+1)%N]) > 0 ) {
            for ( j = 2 ; j < N ; j ++ ) {
                ret += area3( A[ i % N ], A[ (i + j - 1 + N ) % N ], A[ (i + j + N ) % N ] );
            }
        }
    }
    cout << int(ret + 0.5) * K << "\n";
    return 0;
}


