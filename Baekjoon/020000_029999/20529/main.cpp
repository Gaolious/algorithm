#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

char P[255];
void test(string s ) {
    int C[1 << 4]={0,};
    int idx = 0;
    for(auto c: s) idx += P[c];
    C[idx]++;
    cout << s << " : " << idx << "\n";
}
int main()
{
    fastio;
    P['I'] = 1 << 0;
    P['N'] = 1 << 1;
    P['F'] = 1 << 2;
    P['P'] = 1 << 3;

    int T, N, i, j, k, idx , ret, sum;
    string s ;

    cin >> T ;
    while (T--) {
        int C[1 << 4]={0,};

        cin >> N ;
        for ( i = 0 ; i < N ; i ++ ) {
            cin >> s ;
            if ( N >= 48 ) continue;
            idx = 0;
            for(auto c: s) idx += P[c];
            C[idx]++;
        }
        if ( N >= 48) {
            cout << "0\n";
        }
        else {
            ret = 10000;

            for ( i = 0 ; i < 16 ; i ++ ) {
                if ( C[i] == 0 ) continue;
                C[i]--;

                for ( j = i ; j < 16 ; j ++ ) {
                    if ( C[j] == 0 ) continue;
                    C[j] --;
                    for ( k = j ; k < 16 ; k ++ ) {
                        if ( C[k] == 0 ) continue;
                        sum = __builtin_popcount( i ^ j) + __builtin_popcount( j ^ k) + __builtin_popcount( i ^ k);
                        ret = min(ret, sum);
                    }
                    C[j] ++;
                }
                C[i]++;
            }
            cout << ret << '\n';
        }

    }
    return 0;
}


