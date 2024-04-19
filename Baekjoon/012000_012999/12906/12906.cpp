#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;


using namespace std;
int Count[3];
int Total ;

struct Stack {
    bool mixed[3];
    int Len[3];
    char S[3][10];
    uint N() {
        uint ret = 0;
        int i, j, k;

        for ( i = 0 ; i < 3 ; i ++ )
            ret |= (Len[ i ] & 0xF) << ( 2 * Total + 3*(3-i) );

        for ( i = 2 ; i >= 0 ; i -- )
            for ( j = Len[i]-1 ; j >= 0 ; j -- )
                ret = (ret << 2) | ( (S[i][j] - 'A') & 0x3 );

        for ( i = 2 ; i >= 0 ; i -- )
            ret = ( ret << 4 ) | ( Len[i] & 0xF ) ;

        return ret;
    }
    void from(uint N) {
        int i, j, k ;

        for ( i = 0 ; i < 3 ; i ++, N >>= 4 ) {
            Len[i] = N & 0xF;
        }
        for ( i = 0 ; i < 3 ; i ++ ) {
            mixed[i] = false;
            for ( j = 0 ; j < Len[i] ; j ++ ) {
                S[i][j] = (N & 0x3);
                N >>= 2;
                if ( S[i][j] != i) mixed[i] = true;
                S[i][j] += 'A';
            }
        }
    }
    void dump() {
        int i, j;
        for ( i = 0 ; i < 3 ; i ++ ) {
            cout << Len[i] << ' ';
            for ( j = 0 ; j < Len[i] ; j ++ )
                cout << S[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
    void move(int from, int to) {
        S[to][Len[to]++] = S[from][--Len[from]];
    }
};

uint Input() {
    Stack in{};
    int i, j;
    Total = 0;
    for ( i = 0; i < 3 ; i ++ ) {
        cin >> in.Len[i] ;
        Total += in.Len[i];

        for ( j = 0 ; j < in.Len[i] ; j ++ ) {
            cin >> in.S[i][j];
            Count[ in.S[i][j] - 'A' ];
        }
    }
    return in.N();
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;

    uint T = Input();
    unordered_set<uint> D;
    queue<pair<uint, int>> Q;

    Q.emplace(T, 0);
    D.insert(T);

    while ( !Q.empty() ) {
        auto [curr, step] = Q.front();
        Q.pop();

        Stack data{};
        data.from(curr);

        // cout << "Curr = " << curr << " / Step = " << step << '\n';
        // data.dump();

        if ( !data.mixed[0] && !data.mixed[1] && !data.mixed[2] ) {
            cout << step << '\n';
            return 0;
        }
        for ( i = 0 ; i < 3 ; i ++ ) {
            if (!data.mixed[i]) continue;
            if (data.Len[i] < 1 ) continue;

            for ( j = 0 ; j < 3 ; j ++ ) {
                if ( i == j ) continue;
                data.move(i, j);
                T = data.N();
                if ( D.insert(T).second ) {
                    Q.emplace(T, step+1);

                    // cout << "Move " << i << " -> " << j << '\n';
                    // data.dump();
                }
                data.move(j, i);
            }
        }
    }

    return 0;
}


