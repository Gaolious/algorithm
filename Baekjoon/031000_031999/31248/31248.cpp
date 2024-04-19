#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
vector<pair<char, char>> ret;

void F(int n, char from, char mid, char to)
{
    if (n == 0)
        return;
    F(n-1, from, to, mid);
    ret.emplace_back(from, mid);
    F(n-1, to, mid, from);
}

int main()
{
    fastio;
    int N ;
    cin >> N ;
    char a = 'A', b='B', c='C', d='D';
    while ( N >= 2 ) {
        F(N-2, a, c, b);
        ret.emplace_back(a, b);
        ret.emplace_back(a, d);
        ret.emplace_back(b, d);
        N -= 2;
        swap(a,c);
    }
    if ( N ) ret.emplace_back(a, d);
    cout << ret.size() << '\n';
    for (auto [a, b] : ret)
        cout << a << ' ' << b << '\n';
    return 0;
}


