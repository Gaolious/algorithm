#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int Y, X, K ;
struct Data {
    int A[50][50];
    int S[50];
    int score;

    void calcSum() {
        int i, j ;
        score = -1;
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( S[i] = j = 0 ; j < X ; j ++ ) S[i] += A[i][j];
            if ( score < 0 || S[i] < score ) score = S[i];
        }
    }
    void rotate(int y, int x, int s ) {
        int i, j, t ;
        for ( i = 1 ; i <= s ; i ++ ) {
            t = A[y-i][x-i];
            for ( j = 0 ; j < i*2 ; j ++ ) A[y-i+j][x-i] = A[y-i+j+1][x-i];
            for ( j = 0 ; j < i*2 ; j ++ ) A[y+i][x-i+j] = A[y+i][x-i+j+1];
            for ( j = 0 ; j < i*2 ; j ++ ) A[y+i-j][x+i] = A[y+i-j-1][x+i];
            for ( j = 0 ; j < i*2 ; j ++ ) A[y-i][x+i-j] = A[y-i][x+i-j-1];
            A[y-i][x-i+1] = t;
        }
        for ( i = y-s ; i <= y+s ; i ++ )
            for ( S[i] = j = 0 ; j < X ; j ++ )
                S[i] += A[i][j];

        score = -1 ;
        for ( i = 0 ; i < Y ; i ++ )
            if ( score < 0 || S[i] < score ) score = S[i];
    }
    void dump() {
        int i, j;
        cout << "Score = " << score << '\n';
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < X ; j ++ ) {
                cout << setw(2) << A[i][j] << ' ';
            }
            cout << " : " << S[i] << '\n';
        }
        cout << '\n';
    }
};
struct Rotate {
    int y, x, s;
};
Data D[10], d;
bool Visited[10];
int best = 500000;
vector<Rotate> R;

void F(int depth) {
    if ( depth >= K ) {
        // D[depth-1].dump();
        best = min(best, D[depth-1].score);
        return ;
    }
    for ( int i = 0 ; i < K ; i ++ ) {
        if ( Visited[i] ) continue;

        D[depth] = ( depth == 0 ) ? d : D[depth-1];
        D[depth].rotate( R[i].y, R[i].x, R[i].s );
        Visited[ i ] = true;
        F(depth+1);
        Visited[ i ] = false;
    }

}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;
    cin >> Y >> X >> K;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
           cin >> d.A[i][j];
        }
    }
    d.calcSum();
    R.resize(K);
    for ( i = 0 ; i < K ; i ++ ) {
        cin >> R[i].y >> R[i].x >> R[i].s ;
        R[i].y --; R[i].x --;
    }

    F(0);
    cout << best << '\n';
    return 0;
}


