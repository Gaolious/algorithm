#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MIN_N = 0;
const ll MAX_N = 1'000'000'000'000'000'000;

void forecast() {
    long long x, a, b, min_x = MIN_N, max_x = MAX_N ;
    char c ;
    while (min_x < max_x) {
        x = (max_x + min_x)/2ll ;
        a = min_x ;
        b = (ll)sqrt(x - a) ;
        cout << "? " << a << ' ' << b << endl;
        cin >> c;
        if ( c == '+')
            min_x = b*b+a+1 ;
        else if ( c == '-')
            max_x = b*b+a-1 ;
        else {
            min_x = max_x = b*b+a ;
        }
    }
    cout << "! " << min_x << endl;
}
int main(int argc, char **argv) {
    fastio;
    int T;
    cin >> T ;
    while(T--)
        forecast();
    return 0;
}

