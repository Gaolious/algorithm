#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int D[301][101];
const int INF = 1000001;

int f(int w, int h) {
    if ( h > w ) swap(w, h);
    if ( h < 1 ) return INF;

    int &ret = D[w][h] ;
    if ( ret < 0 ) {
        if ( w % h == 0 )
            ret = w / h ;
        else if ( w > h*3 )
            ret = f(w-h, h) + 1;
        else
        {
            int i ;
            ret = w * h;
            for ( i = w/2 ; i >= 1 ; i -- )
                ret = min( ret, f(w-i, h) + f(i, h) );
            for ( i = h/2 ; i >= 1 ; i -- )
                ret = min( ret, f(w, h - i) + f(w, i));
        }
    }
    return ret;
}

int main()
{
    fastio;
    int N, M ;
    int add = 0;

    memset((void *)D, -1, sizeof(D));

    cin >> N >> M ;
    if (N < M) swap(N, M);

    if ( N > M * 3 ) {
        add = N / M - 2;
        N -= M * add ;
    }
    cout << add + f(N, M) << '\n';
    return 0;
}


