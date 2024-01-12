#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
char Card[1'000'000+1];
int Result[1'000'000+1];

int main()
{
    fastio;
    int N ;
    int i, j;
    cin >> N ;

    vector<int> A(N);

    for (auto &n: A) {
        cin >> n ;
        Card[n] = 1;
    }
    for(auto n: A) {
        for ( j=n*2 ; j <= 1'000'000 ; j += n ) {
            if ( Card[j] ) {
                Result[n] ++;
                Result[j] --;
            }
        }
    }
    for(auto n: A) {
        cout << Result[ n ] << ' ';
    }
    return 0;
}


