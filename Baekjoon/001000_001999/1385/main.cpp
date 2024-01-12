#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define ABS(x) ( (x) < 0 ? -(x) : (x) )
int D[1000];
int dx[6] = {1, 2, 1, -1, -2, -1};
int dy[6] = {1, 0, -1, -1, 0, 1};

struct Range {
    int offset ;
    int Sn, En ;
    int sy, sx;
    int ey, ex;
    int dir ;
};
bool compare(const Range &left, const int n){
    return left.Sn < n ;
}
vector<Range> arr ;

int incX[6] = {2, 1, -1, -2, -1, 1};
int incY[6] = {0, -1, -1, 0, 1, 1};

char F[1'000'000+1];

void setNewData(const Range &prev, Range &next) {
    next.offset = prev.offset + ( prev.dir == 5 ? 1 : 0 );
    next.dir = (prev.dir + 1 ) % 6;
    next.Sn = prev.En + 1;
    next.En = next.Sn + next.offset - 1;

    if (prev.dir == 5 ) {
        next.sx = prev.ex + 1;
        next.sy = prev.ey + 1;
    }
    else {
        next.sx = prev.ex + incX[ next.dir ];
        next.sy = prev.ey + incY[ next.dir ];
    }
    next.ex = next.sx + incX[next.dir] * (next.offset-1);
    next.ey = next.sy + incY[next.dir] * (next.offset-1);

//    cout << "offset : " << next.offset << '\n'
//            << "Sn : " << next.Sn << ' ' << "En : " << next.En << '\n'
//            << "sx : " << next.sx << ' ' << "sy : " << next.sy << '\n'
//            << "ex : " << next.ex << ' ' << "ey : " << next.ey << '\n'
//            << "dir : " << next.dir
//            << '\n';
//    flush(cout);
}

int getNumber(int y, int x) {
    int offset = 0;
    int num = 0;
    char c = 0;

    // a : y > -x / y >= x
    if ( x == 0 && y == 0 ) {
        return 1;
    }
    else if ( y > 0 && y > -x && y >= x) { // y >= -x && y >= x
        c = 'a' ;
        offset = y ;
        num = D[offset-1] + offset - ( y - x ) / 2 ;
    }
    // b
    else if ( x > 0 && y >= 0 && y < x ) { // y < x && y >= x
        c = 'b';
        offset = (x+y)/2 ;
        num = D[offset-1] + offset + ( x - offset )  ;
    }
    // c
    else if ( x > 0 && y < 0 && y >= -x ) { // y < x && y >= x
        c = 'c';
        offset = (x-y)/2 ;
        num = D[offset-1] + offset*3 - ( x - offset )  ;
    }

        // 16 (-3, -1)
        // 10 (3, 1)

        //                      -3   -2   -1    0     1    2    3    4    5    6   7
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
        //|    |    |    |    |    | 38 |    | 39 |    | 40 |    | 41 |    |    |    |  4
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
        //|    |    |    |    | 37 |    | 20 |    | 21 |    | 22 |    | 42 |    |    |  3
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
        //|    |    |    | 36 |    | 19 |    | 8  |    | 9  |    | 23 |    | 43 |    |  2
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
        //|    |    | 35 |    | 18 |    | 7  |    | 2  |    | 10 |    | 24 |    | 44 |  1
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
        //|    | 34 |    | 17 |    | 6  |    | 1  |    |  3 |    | 11 |    | 25 |    |  0
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
        //|    |    | 33 |    | 16 |    | 5  |    | 4  |    | 12 |    | 26 |    |    | -1
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
        //|    |    |    | 32 |    | 15 |    | 14 |    | 13 |    | 27 |    |    |    | -2
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
        //|    |    |    |    | 31 |    | 30 |    | 29 |    | 28 |    |    |    |    | -3
        //+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
//            a
//          +----+
//       5 /      \  b
//        +        +
//       4 \      / c
//          +----+
//            3

    // d
    else if ( y < 0 && y < -x && y <= x) { // y >= -x && y >= x
        c = 'd';
        offset = -y;
        num = D[offset-1] + offset*4 - ( x - y )/2  ;
    }
    // e
    else if ( y <= 0 && y > x) { // y >= -x && y >= x
        c = 'e';
        offset = -(x+y)/2 ;
        num = D[offset-1] + offset*5 + y;
    }
    // f
    else if ( y > 0 && y <= -x) { // y >= -x && y >= x
        c = 'f';
        offset = -(x-y)/2 ;
        num = D[offset-1] + offset*5 + y;
    }

//    cout << "(Y=" << y << ", X=" << x << ") Position : " << c << "/ Offset is : " << offset  << "/ Number is " << num << '\n';
    return num;
}

void getPos(int N, int &y, int &x) {

    int l = 0, r = arr.size() - 1;
    int m ;

    while ( l <= r ) {
        m = ( l + r ) / 2 ;
        if (arr[m].Sn <= N && N <= arr[m].En) {
            int offset = N - arr[m].Sn ;

            y = arr[m].sy + incY[arr[m].dir] * offset;
            x = arr[m].sx + incX[arr[m].dir] * offset;
            return;
        }
        else if ( arr[m].En < N ) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    y = -1 ;
    x = -1;
}
struct BFS {
    int n, x, y, parent, dist;
};
int main()
{
    fastio;
    int sx, sy, ex, ey, d, n, i ;
    arr.push_back(Range{0,1, 1, 0, 0, 0, 0, 5 });

    for ( i = 1 ; ; i ++ ) {
        Range data{} ;
        setNewData(arr.back(), data);
        arr.push_back(data);
        if (data.En > 3'000'000) break;
    }
    D[0] = 1;
    for ( i = 1 ; i < 1000 ; i++)
        D[i] = D[i-1] + 6*i ;

    int s, e ;
    cin >> s >> e ;


//    int x1, y1, x2, y2, x, y ;
//    int min_val, min_idx;
//    vector<BFS> Q;
//    int head ;
//    getPos(s, y1, x1);
//    getPos(e, y2, x2);
//    F[s] = 1;
//
//    Q.push_back(BFS{s, x1, y1, -1, 0});
//    head = 0;
//
//    min_val = 10'000'000;
//
//    for ( head = 0 ; head < Q.size() ; head++ ) {
//        BFS top = Q[head];
//        if ( top.x == x2 && top.y == y2 ) {
//            if ( min_val > top.dist) {
//                min_val = top.dist ;
//                min_idx = head;
//            }
//        }
//
//        for ( i = 0 ; i < 6 ; i ++ ) {
//            y = top.y + dy[i];
//            x = top.x + dx[i];
//            n = getNumber(y, x);
//            if ( n > 1'000'000 || F[n]) continue;
//            F[n] = 1;
//            Q.push_back(BFS{n, x, y, head, top.dist + 1});
//        }
//    }
//
//    vector<int> output;
//    while ( true ) {
//        output.push_back(Q[min_idx].n);
////        cout << Q[min_idx].n << ' ';
//        if ( min_idx == 0 ) break;
//        min_idx = Q[min_idx].parent;
//    }
//    std::reverse(output.begin(), output.end());
//    for (auto a : output)
//        cout << a << ' ';

    return 0;
}


