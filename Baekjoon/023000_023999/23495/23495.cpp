#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
	int N, K;
	cin >> N >> K ;
	int ret = 0;
	for (int i = 1; i <= N; i++)
		ret = (ret + K - 1) % i+1;
	cout << ret << '\n';

    return 0;
}


