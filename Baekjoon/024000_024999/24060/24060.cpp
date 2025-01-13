#include <bits/stdc++.h>
using namespace std;

int A[500'000+1];
int tmp[500'000+1];
int K, currK, kValue;
int N;

void merge(int p, int q, int r);
void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p+r)/2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

void merge(int p, int q, int r) {
    int i = p, j = q+1, t = 1;
    while ( i <= q && j <= r )
        tmp[t++] = (A[i] <= A[j]) ? A[i++] : A[j++] ;

    while ( i <= q)
        tmp[t++] = A[i++];
    while ( j <= r )
        tmp[t++] = A[j++];
    i = p, t = 1;

    while (i <= r)
    {
        if ( ++currK == K )
            kValue = tmp[t];
        A[i++] = tmp[t++];
    }

}

void init(){
}
void process(int Case) {
    cin >> N >> K ;
    for (auto i = 0; i < N; i++) cin >> A[i];
    kValue=-1, currK = 0;
    merge_sort(0, N-1);
    cout << kValue << endl;
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
