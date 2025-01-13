#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
ll AS(ll a, ll b, ll c)
{
    return abs(a+b+c);
}
void process(int Case) {

    int N, i, l, r ;
    ll best, v1, v2, v3, m;

    cin >> N ;
    vector<int> A(N);
    for (auto &n : A) cin >> n ;

    std::sort(A.begin(), A.end());

    best = -1;
    for ( i = 1 ; i < N - 1 ; i ++ )
    {
        l = 0;
        r = N - 1;
        while ( l < i && i < r)
        {
            m = AS(A[l],A[i],A[r]);
            if ( best < 0 || best > m )
            {
                best = m ;
                v1 = A[l];
                v2 = A[i];
                v3 = A[r];
                if ( best == 0 ) break;
            }

            if ( AS(A[l+1],A[i],A[r]) < AS(A[l],A[i],A[r-1]) ) l++;
            else r--;
        }
        if ( best == 0 ) break;
    }
    cout << v1 << ' ' << v2 << ' ' << v3 << '\n';
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
