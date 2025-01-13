#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

int D[10][10][10][10][10][10];
#define V(a, b, c, d, e, f) D[ a ][ b ][ c ][ d ][ e ][ f ]
#define Vi(a, b, c, d, e, f, i) V( (a+i)%10, (b+i)%10, (c+i)%10, (d+i)%10, (e+i)%10, (f+i)%10)
#define S(a, b, c, d, e, f, i) ( (a+i+10)%10 + (b+i+10)%10 + (c+i+10)%10 + (d+i+10)%10 + (e+i+10)%10 + (f+i+10)%10 )

void init() {
    int a, b, c, d, e, f, i;
    int val;
    memset(D, -1, sizeof(D));

    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            for (c = 0; c < 10; c++) {
                for (d = 0; d < 10; d++) {
                    for (e = 0; e < 10; e++) {
                        for (f = 0; f < 10; f++) {
                            if ( D[a][b][c][d][e][f] >= 0 ) continue;
                            val = 0;
                            for ( i = 0 ; i < 10 ; i ++ ) val = max(val, S(a, b, c, d, e, f, i));
                            for ( i = 0 ; i < 10 ; i ++ ) Vi(a,b,c,d,e,f,i) = val;
                        }
                    }
                }
            }
        }
    }
}
int A[6][6];
int AddCol(int idx){
    int ret = 0, t ;
    for ( int i = 0 ; i < 6 ; i ++ ) {
        t = (A[i][idx] + 1)%10;;
        ret += t - A[i][idx];
        A[i][idx] = t;
    }
    return ret;
}
int AddRow(int idx){
    int ret = 0, t ;
    for ( int i = 0 ; i < 6 ; i ++ ) {
        t = (A[idx][i] + 1)%10;;
        ret += t - A[idx][i] ;
        A[idx][i] = t;
    }
    return ret;
}
void AddDiag1() {
    for ( int i = 0 ; i < 6 ; i ++ ) A[i][i] = (A[i][i] + 1)%10;
}
void AddDiag2() {
    for ( int i = 0 ; i < 6 ; i ++ ) A[5-i][i] = (A[5-i][i] + 1)%10;
}
void process(int Case) {
    int a, b, c, d, e, f, g, h, i;
    int ans, ret=0 ;

    for (a = 0; a < 6; a++)
        for (b = 0; b < 6; b++)
            cin >> A[ a ][ b ];

//    for (a = 0; a < 10; a++, AddCol(0)) {
        for (b = 0; b < 10; b++, AddCol(1)) {
            for (c = 0; c < 10; c++, AddCol(2)) {
                for (d = 0; d < 10; d++, AddCol(3)) {
                    for (e = 0; e < 10; e++, AddCol(4)) {
                        for (f = 0; f < 10; f++, AddCol(5)) {
                            for (g = 0; g < 10; g++, AddDiag1()) {
                                for (h = 0; h < 10; h++, AddDiag2()) {
                                    ans = 0 ;
                                    for ( i = 0 ; i < 6 ; i ++ )
                                        ans += V(A[i][0], A[i][1], A[i][2], A[i][3], A[i][4], A[i][5]);
                                    ret = max(ret, ans);
                                }
                            }
                        }
                    }
                }
            }
        }
    cout << ret << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
    init();
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
