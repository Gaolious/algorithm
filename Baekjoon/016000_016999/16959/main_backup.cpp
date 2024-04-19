#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;


using namespace std;
// 100 100 100 99
int A[101];
bool Visited[111][111][4];
int initPos;
int N ;
struct Data {
    int from;
    int currN;
    int currType;
    int pos;
    int step;
};
queue<Data> Q;
// vector<Data> Q;
int head = -1;

int lenDxy[] = {4, 4, 8};
int dy[][10] = {
    {0, 1, 0, -1},
    {1, 1, -1, -1},
    {2, 2, -2, -2, 1, 1, -1, -1},
};
int dx[][10] = {
    {1, 0, -1, 0},
    {1, -1, 1, -1},
    {-1, 1, -1, 1, -2, 2, -2, 2},
};

bool InsertQueue(Data curr) {
    auto &ret = Visited[ curr.currN ][ curr.pos ][ curr.currType ]  ;

    if ( !ret ) {
        curr.from = head;
        Q.emplace(curr);
        // Q.emplace_back(curr);
        return ret = true;
    }
    return false;
}

void ChangePiece(Data curr, int newPieceType) {
    if ( curr.currType == newPieceType) return;

    curr.currType = newPieceType;
    curr.step++;
    InsertQueue(curr);
}

void Move(Data curr) {
    int d, x, y;
    // if ( curr.currN == 6 && curr.pos == 2*N+0 && curr.currType == 0 ) {
    //     cout << endl;
    // }
    //  dump( Q[ idx = Find(6, 2, 0, 0, 0) ] );

    for ( d = 0 ; d < lenDxy[curr.currType] ; d ++ ) {
        Data next = curr;
        next.step++;

        y = next.pos / N;
        x = next.pos % N;

        while ( true ) {
            y += dy[next.currType][d];
            x += dx[next.currType][d];
            if ( x < 0 || x >= N || y < 0 || y >= N )
                break;
            next.pos = y * N + x ;
            InsertQueue(next);
            if ( curr.currType == 2 )
                next.step ++;
        }

    }

}

// void dump(Data curr) {
//     cout << "N = " << curr.currN << " / Step = " << curr.step << '\n';
//     int i, j;
//     for ( i = 0 ; i < N ; i ++ ) {
//         for ( j = 0 ; j < N ; j ++ ) {
//             if ( i * N + j == curr.pos ) {
//                 if ( curr.currType == 0 ) cout << setw(3) << '+';
//                 if ( curr.currType == 1 ) cout << setw(3) << 'X';
//                 if ( curr.currType == 2 ) cout << setw(3) << 'J';
//             } else {
//                 cout << setw(3) << A[ i * N + j ] ;
//             }
//         }
//         cout << '\n';
//     }
//     cout << '\n';
// }
// void PrintLog(int idx) {
//     if ( idx >= 0 ) {
//         PrintLog(Q[idx].from);
//         dump(Q[idx]);
//     }
// }

int bfs() {
    Data init{}, curr{};
    int i ;
    for ( i = 0 ; i < 3 ; i ++ ) {
        init.from = -1;
        init.currN = 1;
        init.pos = initPos;
        init.step = 0;
        init.currType = i ;
        InsertQueue(init);
    }

    int ans = 100000000;
    int bestIdx = -1;
    while ( !Q.empty() ) {
        curr = Q.front();
        Q.pop();
    // while ( ++head < Q.size() ) {
    //     curr = Q[head];
        if (ans <= curr.step ) continue;

        if ( A[ curr.pos ] == curr.currN ) {
            if ( curr.currN == N*N ) {
                if ( ans > curr.step ) {
                    bestIdx = head;
                    ans = curr.step;
                }
                // ans = min(ans, curr.step);
                // dump(curr);
                continue;
            }
            curr.currN ++;
        }
        Move(curr);
        for ( i = 0 ; i < 3 ; i ++ )
            ChangePiece(curr, i);
    }
    // PrintLog(bestIdx);

    return ans;
}
// int Find(int num, int y, int x, int type, int prevIndex = -1) {
//     int i;
//     for (i = prevIndex + 1 ; i < Q.size() ; i ++ ) {
//         if ( Q[i].pos != y * N + x ) continue;
//         if ( Q[i].currN != num) continue;
//         if ( Q[i].currType != type ) continue;
//         return i;
//     }
//     return -1;
// }
const int INF = 100000;
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;
    cin >> N ;

    for ( i = 0 ; i < N*N ; i ++ ) {
        cin >> A[i] ;
        if ( A[i] == 1 )
            initPos = i ;
    }

    cout << bfs() << '\n';
    //
    // int idx ;
    // dump( Q[ idx = Find(1, 0, 2, 0, 0) ] );
    // dump( Q[ idx = Find(2, 2, 0, 0, 0) ] );
    // dump( Q[ idx = Find(3, 1, 2, 0, 0) ] );
    // dump( Q[ idx = Find(4, 1, 0, 0, 0) ] );
    // dump( Q[ idx = Find(5, 2, 2, 0, 0) ] );
    // dump( Q[ idx = Find(6, 0, 2, 0, 0) ] );
    // dump( Q[ idx = Find(6, 2, 0, 0, 0) ] );
    // dump( Q[ idx = Find(6, 0, 0, 0, 0) ] );
    // dump( Q[ idx = Find(7, 2, 1, 0, idx) ] );
    // dump( Q[ idx = Find(8, 0, 1, 0, idx) ] );
    // dump( Q[ idx = Find(9, 1, 1, 0, idx) ] );
    // // PrintLog(101);
    return 0;

}


