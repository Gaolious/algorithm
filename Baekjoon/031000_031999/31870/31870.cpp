#include <bits/stdc++.h>
using namespace std;
void init(){
}
int F(vector<int> &A, vector<int> &B) {
    int cnt = 0 ;
    int i, j;
    int N = A.size();
    for ( i = 0 ; i < N ; i ++ ) {

        for ( j = N-1 ; j > i && B[j] != A[i] ; j-- );
        for ( ; j > i ; j-- ) {
            swap(B[j-1], B[j]);
            cnt++;
        }
    }
    return cnt;
}
void process(int Case) {
    int N , i, c1, c2;
    cin >> N ;
    vector<int> A(N), B(N);
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[i];
        B[i] = A[i];
    }

    std::sort(B.begin(), B.end());
    c1 = F(A, B);
    std::sort(B.begin(), B.end(), greater<>());
    c2 = F(A, B);
    cout << min(c1, c2+1) << '\n';
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
