#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

struct Data {
    int Y, X;
    vector<string> M;
    void dump() {
        int i, j;
        cout << Y << ' ' << X << '\n';
        for (i = 0; i < Y; i++) {
            for (j = 0; j < X; j++)
                cout << M[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
    void clear() {
        int i, j;
        for (i = 0; i < Y; i++)
            for (j = 0; j < X; j++)
                M[i][j] = '.';
    }
};
void Read(Data &A) {
    int i, j;
    char c;

    cin >> A.Y >> A.X ;

    int minY=A.Y + 1 , minX=A.X + 1;
    int maxY=-1 , maxX=-1;

    for ( i = 0 ; i < A.Y ; i ++ ) {
        auto &s = A.M.emplace_back() ;
        for ( j = 0 ; j < A.X ; j ++ ) {
            cin >> c;
            s.push_back(c);
            if ( c == '#' ) {
                minY = min(minY, i);
                minX = min(minX, j);
                maxY = max(maxY, i);
                maxX = max(maxX, j);
            }
        }
    }

    A.Y = maxY - minY + 1 ;
    A.X = maxX - minX + 1 ;

    for (i = minY; i <= maxY; i++) {
        for (j = minX; j <= maxX; j++)
            A.M[i - minY][j - minX] = A.M[i][j];
        A.M[i].resize(A.X);
    }
    A.M.resize(A.Y);
}
void Draw(Data &d, int y, int x, Data &Map, Data &Result ) {
    int i, j;

    for ( i = 0 ; i < d.Y ; i ++ ) {
        for ( j = 0 ; j < d.X ; j ++ ) {
            if ( d.M[i][j] == '.' ) continue;
            if ( y + i < 0 || y + i >= Map.Y ) return;
            if ( x + j < 0 || x + j >= Map.X ) return;
            if ( Map.M[y+i][x+j] == '.' ) return;
        }
    }

    for ( i = 0 ; i < d.Y ; i ++ ) {
        for ( j = 0 ; j < d.X ; j ++ ) {
            if ( d.M[i][j] == '.' ) continue;
            Result.M[y+i][x+j] = '#';
        }
    }

}
void process() {
    int i, j, k;
    int N ;

    Data Map, Result;
    vector<Data> A;

    Read(Map);
    Result = Map;

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ )
        Read(A.emplace_back());

    Result.clear();
    for ( i = 0 ; i < Map.Y ; i ++ ) {
        for ( j = 0 ; j < Map.X ; j ++ ) {
            for ( k = 0 ; k < N ; k ++ ) {
                Draw(A[k], i, j, Map, Result);
            }
        }
    }
//    Map.dump();
//    Result.dump();
    for ( i = 0 ; i < Map.Y ; i ++ ) {
        for (j = 0; j < Map.X; j++) {
            if ( Map.M[i][j] != Result.M[i][j] )
            {
                cout << "NIE\n";
                return;
            }
        }
    }
    cout << "TAK\n";
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


