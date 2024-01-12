#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int main()
{
    fastio;
    int a, b, c, d, e, f;
    int t;
    int x, y ;
    cin >> a >> b >> c >> d >> e >> f;
    x = e*c - b*f;
    y = -d*c + a*f;
    t = a*e - b*d;
    cout << x / t << ' ' << y / t<< '\n';
    return 0;
}


