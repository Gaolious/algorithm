#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;


void process() {
    int Total = 0;
    int N = 9;
    vector<int> H(N);

    for (auto &h : H) cin >> h;

    sort(H.begin(), H.end());

    // i : 1 1111 1111 ~ 0 0000 0000
    for ( int i = (1 << 9) - 1 ; i >= 0 ; i -- ) {
        if ( __builtin_popcount(i) != 7 ) continue; // 1개수가 7개?

        int s = 0 ;
        for ( int j = 0 ; j < 9 ; j ++ ) // bit가 1인곳만 H[j] 합산
            s += ( i & (1<<j) ) ? H[j] : 0;

        if ( s != 100 ) continue;

        for ( int j = 0 ; j < 9 ; j ++ ) // bit가 1인곳만 H[j] 출력
            if (  i & (1<<j) )
                cout << H[j] << '\n';
        break;
    }
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


