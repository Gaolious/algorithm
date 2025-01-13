#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int z, y, x;
} P[] = {
        {0,0,0},
        {0,0,1},
        {0,1,0},
        {0,1,1},
        {1,0,0},
        {1,0,1},
        {1,1,0},
        {1,1,1},
};
void init(){}
void process(int Case) {
    bool A[2][2][2] = {false};
    int i, n, z, y, x, cnt;
    for (i = 0; i < 4; i++) {
        cin >> n;
        A[P[n].z][P[n].y][P[n].x] = true;
    }
    for (z = 0; z < 2; z++) {
        cnt = 0;
        for (y = 0; y < 2; y++) for (x = 0; x < 2; x++) cnt += A[z][y][x];
        if (cnt == 4) { cout << "YES\n"; return ;}
    }
    for (y = 0; y < 2; y++) {
        cnt = 0;
        for (z = 0; z < 2; z++) for (x = 0; x < 2; x++) cnt += A[z][y][x];
        if (cnt == 4) { cout << "YES\n"; return ;}
    }
    for (x = 0; x < 2; x++) {
        cnt = 0;
        for (y = 0; y < 2; y++) for (z = 0; z < 2; z++) cnt += A[z][y][x];
        if (cnt == 4) { cout << "YES\n"; return ;}
    }
    cout << "NO\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
