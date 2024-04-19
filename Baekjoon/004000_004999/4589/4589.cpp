#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int N ;
    cin >> N ;
    cout << "Gnomes:\n";

    while (N--) {
        vector<int> A(3);
        for (auto &a: A) cin >> a ;
        vector<int> B = A, C=A;
        sort(B.begin(), B.end(), less<>());
        sort(C.begin(), C.end(), greater<>());
        if ( A == B || A == C) {
            cout << "Ordered\n";
            continue;
        }
        else  {
            cout << "Unordered\n";
            continue;
        }
    }
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


