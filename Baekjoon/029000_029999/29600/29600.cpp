#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, K, i;
    cin >> N >> K;
    vector<int> A(N);
    for ( i = 0 ; i < N ; i ++ ) A[i] = i+1;
    do {
        bool f = true;
        for (i = 0 ; i < N - 1 ; i ++ ){
            if ( A[i] == 1 || A[i] == 2) {
                if ( A[i+1] == 2 || A[i+1] == 1 ) f = false;
                break;
            }
        }
        if (f) K--;
    } while ( K && std::next_permutation(A.begin(), A.end()));
    for (auto n: A) cout << n << ' ';
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
