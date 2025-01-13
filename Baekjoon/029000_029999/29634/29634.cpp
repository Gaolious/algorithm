#include <bits/stdc++.h>
using namespace std;
void init(){
}
void process(int Case) {
    int Y, X, S, s;
    int i, j, x, y, w, h;
    cin >> Y >> X;
    vector<string> M(Y);
    vector A(Y, vector<int>(X));
    for (i = 0; i < Y; i++) cin >> M[i];

    S = 0;
    for (i = 1; i < Y-1; i++) {
        for (j = 1; j < X-1; j++) {
            A[i][j] = M[i][j] == '*' ? 0 : 1;
            S = max(S, A[i][j]);
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        }
    }

    for (i = 1; i < Y-1; i++) {
        for (j = 1; j < X-1 && (Y - i) * (X - j) > S; j++) {
            if (M[i][j] == '*') continue;
            for (y = 1; i+y < Y; y++) {
                x = S/y + 1;
                for ( ; x < X ; x ++ ) {
                    s = A[i+y-1][j+x-1] - A[i-1][j+x-1] - A[i+y-1][j-1] + A[i-1][j-1];
                    if ( s == y*x )
                        S = max(S, s);
                }
            }
        }
    }
    if ( S == 0 )
        cout << "-1\n";
    else
        cout << S << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
