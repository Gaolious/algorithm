#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    long double h, w, b;
    cin >> w >> h ;
    b = w / (h*h);
    if ( b > 25.0 ) cout << "Overweight\n";
    else if ( b >= 18.5 ) cout << "Normal weight\n";
    else cout << "Underweight\n";
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    process();
    return 0;
}


