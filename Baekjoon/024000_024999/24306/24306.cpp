#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void init(){
}
void process(int Case) {
    // 1초에
    //초침 = 360 / 60
    //분침 = 360 / (60*11)
    //시침 = 360 / (60*11*3)

    //    360                            360                  360
    // --------- * (h*M*S + m*S + s) = ------- * (m*S + s) = ----- * s
    //  60*11*3                         60*11                 60
    //
    //    360                            360
    // --------- * (h*M*S + m*S + s) = ------- * (m*S + s)
    //  60*11*3                         60*11
    //
    // 시침=분침
    // (h*M*S + m*S + s) = H *(m*S + s)
    // h*M*S + m*S - H*m*S = H*s - s
    // h*M*S + m*S - H*m*S = s(H-1)
    // S*(h*M + m - H*m) = s(H-1)
    //
    // 분침=초침
    // (m*S + s) = (M) * s
    // m*S  = M * s - s
    // m * S  = s * (M-1)
    //
    // 초=분=시
    // s = S * (h * M + m - H * m) * (M-1) == m * S * (H-1)

    // S * (h * M + m - H * m) * (M-1) == m * S * (H-1)

    int i;
    ll h;
    ll H, M, S;
    cin >> H >> M >> S ;
    vector<int> Minutes;
    for (i = 1; i < M - 1; ++i) {
        if ( i*(H-1) % (M-1) == 0 ) Minutes.push_back(i);
    }
    int cnt=0;
    for (h = 0; h < H; ++h) {
        for (auto m: Minutes)
            if ( (h*M + m - H*m) * (M-1) == m * (H-1) )
                ++cnt;
    }
    cout << cnt;
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
