#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

bool P[101][101]={false,};

void init() {
    int i, j, n ;

    P[0][0] = true;

    for ( i = 1 ; i < 101 ; i ++ ) {
        for ( j = 0 ; j <= i ; j ++ ) {
            n = j * 1000 / i;
            n = (n/10) + ( n % 10 >= 5 );
            P[i][n] = true;
//            cout << j << "/" << i << " : " << n << ' ' << setprecision(5) << fixed << (double)j / i << '\n';
        }
    }
}
bool F(vector<int> &A, int total) {
    for (auto n: A)
        if ( !P[total][n] )
            return false;
    return true;
}
void process() {
    int N, n ;
    cin >> N ;
    vector<int> A;
    init();

    while ( N -- ) {
        cin >> n ;
        A.push_back(n);
    }

    std::sort(A.begin(), A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());

    for ( n = 1 ; n <= 100 ; n ++ ) {
        if (F(A, n)) {
            cout << n << '\n';
            return;
        }
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


