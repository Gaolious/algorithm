#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
unsigned char A[1001][1001];
int main()
{
    fastio;
    int Y, X, Q;
    int c, dx, dy, y, x;
    cin >> Y >> X >> Q;
    int cnt = X*Y;

    while (Q-- ) {
        cin >> c;
        switch(c) {
            case 1: {
                cin >> dy >> dx >> y >> x;
                while( A[y][x] == 0 ) {
                    A[y][x] = 1;
                    cnt--;
                    y += dy;
                    x += dx;
                    if ( y < 1 || y > Y || x < 1 || x > X) break;
                }
            }
                break;
            case 2: {
                cin >> y >> x;
                cout << (int)A[y][x] << '\n';
            }
                break;
            case 3:
                cout << cnt << '\n';
                break;
        }
    }
    return 0;
}


