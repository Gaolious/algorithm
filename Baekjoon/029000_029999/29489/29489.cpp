#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

const long double PI = acos(-1);
const long double T2R = PI / 180.0;

void process() {
    int N, i;
    long double angle, a, r ;
    cin >> N;
    angle = 360.0l / (long double)N * T2R;
    cout << setprecision(10) << fixed;
    for ( a = 0 , i = 0 ; i < N ; i ++, a += angle ) {
        cin >> r ;
        cout << cos(a) * r << ' ' << sin(a) * r << '\n';
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


