#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);

int A[5][5]={0,};
int S ;
int N, K ;
vector< vector<int> > TotalPossibles;
struct DATA {
    vector<int> rowIndex[5];
    vector<int> colIndex[5];
    vector<int> diagUpIndex;
    vector<int> diagDownIndex;

    void setNumber(int y, int x, int n) {
        A[y][x] = n ;
    }
    void unsetNumber(int y, int x, int n) {
        A[y][x] = 0 ;
    }
};


bool Find(int pos, int remainCnt) {
    return false ;
}
void generate_total_possibles(DATA &data) {
    int a, b, c, d, e;
    for ( a = 1 ; a <= N*N ; a ++ ) {
        for ( b = a+1 ; b <= N*N ; b ++ ) {
            if ( a+b > S ) break;
            if ( N == 3 ) {
                c = S - a - b ;
                if ( b < c && c <= N*N )
                    TotalPossibles.push_back({a,b,c});
                continue;
            }
            for ( c = b+1 ; c <= N*N ; c ++ ) {
                if ( a+b+c > S ) break;
                if ( N == 4 ) {
                    d = S - a - b - c;
                    if ( c < d && d <= N*N )
                        TotalPossibles.push_back({a,b,c,d});
                    continue;
                }
                for ( d = c+1 ; d <= N*N ; d++ ) {
                    if ( a+b+c+d > S ) break;
                    e = S - a - b - c - d;
                    if ( d < e && e <= N*N )
                        TotalPossibles.push_back({a,b,c,d,e});
                }
            }
        }
    }

    for ( a = 0 ; a < TotalPossibles.size() ; a ++ ) {
        for ( b = 0 ; b < N ; b ++ ) {
            data.rowIndex[b].push_back(a);
            data.colIndex[b].push_back(a);
        }
        data.diagUpIndex.push_back(a);
        data.diagDownIndex.push_back(a);
    }
}
void process() {
    fastio;
    int i, j, x, y, v ;
    DATA init ;
    cin >> N >> K ;
    S = N * (N*N+1) / 2 ;
    generate_total_possibles(init);

    for ( i = 0 ; i < K ; i ++ ) {
        cin >> y >> x >> v ;
        init.setNumber(y-1, x-1, v);
    }

    if ( Find(0, N*N - K) ) {
        cout << "yes";
    } else {
        cout << "no";
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


