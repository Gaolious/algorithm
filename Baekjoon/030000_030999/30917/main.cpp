#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MAX_N (10'000)

int ask(char c) {
    int ret, i ;
    vector<int> N(MAX_N);

    std::random_device random_dev;
    std::mt19937       generator(random_dev());

    for ( i = 0 ; i < MAX_N ; i ++ ) {
        N[i] = i+1;
    }

    std::shuffle(N.begin(), N.end(), generator);

    for(auto n: N) {
        cout << "? " << c << " " << n << endl;
        cin >> ret ;
        if ( ret == 1 ) return n;
    }
    return -1;
}
int main()
{
    fastio;
    int a, b;
    a = ask('A');
    b = ask('B');
    cout << "! " << a + b << endl;
    return 0;
}


