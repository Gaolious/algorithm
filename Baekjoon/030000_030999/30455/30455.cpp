#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

//int D[100][100];
int N ;
//bool F(int L, int R) {
//    if ( abs(L-R) == 0 ) return true;
//
//    auto &ret = D[L][R];
//    if ( ret < 0 ) {
//        int nextL, nextR ;
//        ret = false ;
//        for (auto d : {-1, 1} ) {
//            if ( L+d < 1 || L +d > N ) continue;
//            nextL = N+1-R;
//            nextR = N+1-(L+d);
//            ret = ret || !F(nextL, nextR);
//        }
//    }
//    return ret;
//}
void process() {
//    memset(D, -1, sizeof(D));
//    for ( N = 3 ; N <= 10 ; N ++ )
//        cout << F(1, N) << '\n';
    cin >> N ;
    string s[] = { "Duck", "Goose" };
    cout << s[N%2] << '\n';
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


