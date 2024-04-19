#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int a, b, c;
    int q, w, e;
    cin >> a >> b >> c >> q>>w>>e;
    int A = a*3+b*20+c*120 ;
    int B = q*3+w*20+e*120;
    string s[] = {"Max", "Draw", "Mel"};
    cout << s[(A<B) - (A>B) + 1] << '\n';
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


