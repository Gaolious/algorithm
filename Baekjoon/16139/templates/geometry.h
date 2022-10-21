#include <bits/stdc++.h>
using namespace std;

#ifndef BOJ_GEOMETRY_H
#define BOJ_GEOMETRY_H
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

    bool getPoint(Line& other, Vector2D<double> &c) {
        T dx1 = e.x - s.x, dy1 = e.y - s.y ;
        T dx2 = other.e.x - other.s.x, dy2 = other.e.y - other.s.y ;
        if (this->dx() == other.dx() && this->dy() == other.dy() ) {
            T x = min( max(s.x, e.x), max(other.s.x, other.e.x)) - max( min(s.x, e.x), min(other.s.x, other.e.x));
            T y = min( max(s.y, e.y), max(other.s.y, other.e.y)) - max( min(s.y, e.y), min(other.s.y, other.e.y));
            if ( x > 0 || y > 0 ) return false ;
            if ( s == other.s || s == other.e )
                c.x = s.x, c.y = s.y;
            else
                c.x = e.x, c.y = e.y;
            return true;
        }

        auto px = this->det() * other.dx() - this->dx() * other.det();
        auto py = this->det() * other.dy() - this->dy() * other.det();
        auto p  = this->dx() * other.dy() - this->dy() * other.dx();

        c.x = (double)px / (double)p;
        c.y = (double)py / (double)p;
        return true ;
    }
};
#endif //BOJ_GEOMETRY_H

