#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int N, i, j;
    cin >> N;
    vector A(N, vector<int>(N));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            cin >> A[i][j];

    bool rule1, rule2, rule3;
    int cnt=0, diagSum, Sum;
    rule1 = rule2 = true;
    rule3 = false;
    for ( i = 0 ; i < N ; i ++ ) {
        diagSum = Sum = 0 ;
        for ( j = 0 ; j < N ; j ++ ) {
            if ( i == j ) diagSum += A[i][j];
            else Sum += A[i][j];
            rule1 = rule1 && (A[i][j] >= 0);
        }
        rule2 = rule2 && (Sum <= diagSum) ;
        rule3 = rule3 || (Sum < diagSum);
        cnt += Sum < diagSum;
    }
    if ( rule1 && rule2 && rule3 ) {
        cout << "YES\n";
        cout << cnt << '\n';
    }
    else {
        cout << "NO\n";
    }
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
