#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int N;
    cin >> N ;
    cout << int(N*N/3) + N + 1<< '\n';
    return 0;
}


