#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

string s;
bool F() {
    int n ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( i != 1 ) cin >> n ;
        cout << i << endl;
        cin >> s ;
        if ( s == "Colder" ) {
            if ( F() ) return true;
        }
        else if ( s == "Warmer" ) {
            return false;
        }
        else if ( s == "Success" ) {
            return true;
        }
    }
    return false;
}
void process() {
    while ( true ) {
        if ( F() )
            break;
    }
}

int main()
{
    fastio;
    process();
    return 0;
}


