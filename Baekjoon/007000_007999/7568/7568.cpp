#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return ( a.first > b.first && a.second > b.second );
}

int main()
{
    fastio;
    int N, a, b ;
    int i;
    int rank ;
    cin >> N ;

    vector<pair<int,int>> A(N);
    for (auto &a: A) cin >> a.first >> a.second;

    for ( i = 0 ; i< A.size() ; i++ )
    {
        rank = 1 ;
        for ( int j = 0 ; j < A.size() ; j ++)
        if ( i != j && cmp( A[j], A[i])  ) rank++;

        cout << rank << ' ';
    }
    return 0;
}


