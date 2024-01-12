#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{

    fastio;
    long double b, c, a1, a2;
    cin >> b >> c >> a1 >> a2;
    cout << setprecision (20) << (b + sqrt(b*b+4*c)) / 2.0 << '\n';
    return 0;
}


