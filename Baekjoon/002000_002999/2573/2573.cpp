#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[300][300];
char visited[300][300];
vector< pair<int,int> > PointList;
int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};
int N, M ;

bool is_separated() {
    int tx, ty;
    int d ;
    int cnt = 0 ;

    queue< pair<int, int> > SQ ;
    if (PointList.empty() ) return true ;
    memset(visited, 0, sizeof(visited));

    SQ.push(PointList.front());
    visited[ SQ.front().first ][ SQ.front().second ] = 1 ;
    cnt ++;
    while ( !SQ.empty()) {
        auto p = SQ.front();
        SQ.pop();
        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = p.first + dy[d];
            tx = p.second + dx[d];
            if ( ty < 0 || ty >= N || tx < 0 || tx >= M ) continue;
            if (visited[ty][tx] == 1 ) continue;
            if ( A[ty][tx] == 0 ) continue;
            SQ.emplace(ty, tx);
            visited[ty][tx] = 1;
            cnt++;
        }
    }
    return cnt != PointList.size();
}

int ZeroCount(int y, int x){
    int tx, ty;
    int d, ret ;
    for ( ret = 0 , d = 0 ; d < 4 ; d ++ ) {
        ty = y + dy[d];
        tx = x + dx[d];
        if ( ty < 0 || ty >= N || tx < 0 || tx >= M ) continue;
        if ( A[ty][tx] == 0 ) ret ++;
    }
    return ret;
}
void process() {
    fastio;
    int i, j;
    int year ;
    int minValue = 100 ;
    cin >> N >> M ;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < M ; j ++ )
        {
            cin >> A[ i ][ j ] ;
            if ( A[ i ][ j ] > 0 ) {
                PointList.emplace_back(i, j);
                minValue = min(minValue, A[i][j]);
            }
        }

    int multi ;
    for ( year = 0 ; !is_separated() ; year += multi) {
        vector<int> reduce ;
        vector<pair<int,int>> nextPoints;
        multi = 10;

        for( auto p: PointList ) {
            int cnt = ZeroCount(p.first, p.second );
            reduce.emplace_back(cnt);
            if ( cnt > 0 ) {
                multi = max(1, min( multi, ( A[p.first][p.second] + cnt - 1 ) / cnt ));
            }
        }
        for ( i = 0 ; i < PointList.size() ; i ++ ){
            auto p = PointList[i];
            auto &n = A[p.first][p.second] ;
            if ( n > reduce[i] * multi)
            {
                n -= reduce[i] * multi;
                nextPoints.push_back(p);
            }
            else {
                n = 0;
            }
        }
        PointList.clear();
        for (auto p : nextPoints)
            PointList.push_back(p);
//        cout << multi << " times\n";
//        for ( i = 0 ; i < N ; i ++ ) {
//            for ( j = 0 ; j < M ; j ++ ) {
//                cout << A[i][j] << ' ';
//            }
//            cout <<'\n';
//        }
//        cout <<'\n';
    }
    if ( PointList.empty())
        cout << "0\n";
    else
        cout << year << '\n';
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


