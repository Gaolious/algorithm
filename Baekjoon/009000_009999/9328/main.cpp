#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);

using namespace std;

char A[103][103];
int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, -1, 0, 1};

int solve(int Y, int X, bool hasKey[]) {
    int y, x, tx, ty, d;
    queue<pair<int,int>> Q;
    char C[103][103]={0,};
    int ret = 0 ;

    Q.push({0,0});
    C[0][0] = 1;
    while ( !Q.empty() ) {
        while ( !Q.empty() ) {
            y = Q.front().first;
            x = Q.front().second;
            Q.pop();
            for ( d = 0 ; d < 4 ; d ++ ) {
                ty = y + dy[d];
                tx = x + dx[d];
                if ( ty < 0 || ty > Y + 1 || tx < 0 || tx > X + 1 ) continue;
                if ( C[ty][tx] == 1 ) continue;
                if ( A[ty][tx] == '*') continue;
                if ( A[ty][tx] >= 'A' && A[ty][tx] <= 'Z' ) {
                    if ( !hasKey[ A[ty][tx] - 'A' ] ) {
                        C[ty][tx] = 2;
                        continue;
                    }
                }

                C[ty][tx] = 1;
                Q.push({ty,tx});

                if ( A[ty][tx] >= 'a' && A[ty][tx] <= 'z' )
                    hasKey[ A[ty][tx] - 'a' ] = true ;
                if ( A[ty][tx] == '$' )
                    ret ++;
            }
        }

//        for ( y = 1 ; y <= Y ; y ++ ) {
//            for (x = 1; x <= X; x++) {
//                printf("%c ", C[y][x] + '0');
//            }
//            printf("\n");
//        }
        for ( y = 1 ; y <= Y ; y ++ )
            for ( x = 1 ; x <= X ; x ++ ) {
                if ( C[y][x] == 2 && A[y][x] >= 'A' && A[y][x] <= 'Z' && hasKey[ A[y][x] - 'A' ] ) {
                    Q.push({y,x});
                    C[y][x] = 1;
                }
            }
    }
    return ret;
}
void process() {
    fastio;
    int T, y, x, i, j ;
    char s[1024]={0,};
    int lenS;
    cin >> T ;

    while ( T -- ) {
        cin >> y >> x ;
        memset(A, 0, sizeof(A));
        for ( i = 1 ; i <= y ; i ++ )
            for ( j = 1 ; j <= x ; j ++ )
                cin >> A[i][j];

        for ( i = 0 ; i <= y+1 ; i ++ )
            A[i][0] = A[i][x+1] = '.';
        for ( j = 1 ; j <= x ; j ++ )
            A[0][j] = A[y+1][j] = '.';

        bool hasKey[26]={false, };
        cin >> s ;
        lenS = strlen(s);
        if ( s[0] != '0' )
        {
            for ( i = 0 ; i < lenS ; i ++ ) {
                if ( s[i] >= 'a' && s[i] <= 'z' )
                    hasKey[s[i] - 'a'] = true ;
            }
        }

        cout << solve(y, x, hasKey) << '\n';
    }

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


