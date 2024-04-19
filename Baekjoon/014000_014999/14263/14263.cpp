#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Data {
    char c;
    int sy, sx, ey, ex;

    Data(char c, int y, int x): c(c), sy(y), ey(y), sx(x), ex(x){}
    void update(int y, int x) {
        sy = sy < 0 ? y : min(sy,y);
        ey = ey < 0 ? y : max(ey,y);
        sx = sx < 0 ? x : min(sx,x);
        ex = ex < 0 ? x : max(ex,x);
    }
    bool operator < (Data &o ) const {
        return c < o.c ;
    }
};
vector<Data> A;
int Y, X;
vector<vector<int>> Child;
vector<int> ParentCount;
char C[50][50];
int Index[256];

bool Input() {

    int i, j, y, x ;
    int n = 0;
    vector<vector<bool>> Check;
    memset(Index, -1, sizeof(Index));

    cin >> Y >> X ;

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> C[i][j] ;
            if ( C[i][j] == '.') continue;
            auto &idx = Index[ C[i][ j ] ];
            if ( idx < 0 ) {
                idx = n ++;
                A.emplace_back(C[i][j], i, j);
            }
            else {
                A[ idx ].update(i, j);
            }
        }
    };

    Child.resize(A.size());
    ParentCount.resize(A.size());

    Check.resize(A.size(), vector<bool>(A.size(), false));

    for ( i = 0 ; i < A.size() ; i ++ ) {
        for (y = A[i].sy ; y <= A[i].ey ; y ++ ) {
            for ( x = A[i].sx ; x <= A[i].ex ; x ++ ) {
                auto idx = Index[ C[y][x] ];
                if ( idx < 0 ) return false;
                if ( idx == i ) continue;
                if (!Check[idx][i]) {
                    Child[i].push_back(idx);
                    ParentCount[idx] ++;

                    Check[idx][i] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    char c ;
    int i, j ;

    if ( Input() ) {
        priority_queue<int, vector<int>, greater<> > Q;
        for ( i = 0 ; i < A.size() ; i ++ )
            if ( ParentCount[ i ] == 0 )
                Q.push(A[i].c);

        string ans ;
        while ( !Q.empty() ) {
            auto c = Q.top(); Q.pop();
            auto idx = Index[c];

            ans.push_back( (char)(c) );
            for (auto child: Child[idx]) {
                if ( --ParentCount[child] == 0 )
                    Q.push(A[child].c);
            }
        }
        if ( ans.size() == A.size() ) {
            cout << ans << '\n';
            return 0;
        }
    }


    cout << "-1\n";
    return 0;
}


