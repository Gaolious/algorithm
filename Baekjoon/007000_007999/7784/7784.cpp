#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Data {
    int from ;
    int added_num;
    int len;
};

Data C[65536+1];
int BestCount;
string BestString;

int update(int remain, int i, int N) {
    int nxt = ( remain * 10 + i ) % N ;
    if ( remain == 0 && i == 0 )
        return -1;

    if ( C[nxt].len == 0 ) {
        C[nxt].from = remain;
        C[nxt].added_num = i;
        C[nxt].len = C[remain].len + 1;
        return nxt;

    }
    return -1;
}
bool need_to_update(int digit_count, int len) {
    if ( BestCount < digit_count ) return false;
    if ( BestCount > digit_count ) return true;

    if ( BestString.length() < len ) return false;
    if ( BestString.length() > len ) return true;

    return true;
}
bool need_to_update(int digit_count, string &s) {
    if ( BestCount < digit_count ) return false;
    if ( BestCount > digit_count ) return true;

    if ( BestString.length() < s.length() ) return false;
    if ( BestString.length() > s.length() ) return true;

    return s < BestString;
}
void update_solution(int digit_count, int curr) {
    int i ;
    string s;
    int len = C[curr].len;

    if ( BestCount < digit_count) return;

    s.resize(len);
    for ( i = curr ; ; i = C[i].from ) {
        s[--len] = (char)('0' + (C[i].added_num) );
        if (C[i].from < 0)
            break;
    }
    if ( need_to_update(digit_count, s) ) {
        BestCount = digit_count;
        BestString = s ;
    }
}
bool update_cache(int nxt, int from, int added_num, int len) {
    if ( C[nxt].len == 0 ) {
        C[nxt].from = from;
        C[nxt].added_num = added_num;
        C[nxt].len = len;
        return true;
    }
    return false;
}
void sol(int N, int a, int b) {
    int curr, nxt;
    int digit_count;
    queue<int> Q;

    digit_count = a == b ? 1 : 2;
    if ( BestCount < digit_count ) return;

    memset(C, 0, sizeof(C));

    for (auto k: {a, b}) {
        if ( !k) continue;
        nxt = k % N;
        if ( update_cache(nxt, -1, k, 1) )
            Q.push(nxt);
    }

    while( !Q.empty() ) {
        curr = Q.front();
        Q.pop();
        if ( !need_to_update(digit_count, C[curr].len))
            continue;

        if ( curr == 0 ) {
            update_solution(digit_count, curr);
            continue;
        }

        for (auto k: {a, b}) {
            nxt = (curr * 10 + k) % N;
            if ( update_cache(nxt, curr, k, C[curr].len + 1) ) {
                if ( need_to_update(digit_count, C[nxt].len))
                    Q.push(nxt);
            }
        }
    }
}
int main()
{
    fastio;
    int n;
    int i, j ;
    while ( true ) {
        cin >> n ;
        if ( n == 0) break;
        BestCount = 1e9;
        BestString.clear();
        for ( i = 0 ; i < 10 ; i ++ ) {
            for ( j = i+1 ; j < 10 ; j ++ ) {
                if ( i + j == 0) continue;
                sol(n, i, j);
            }
        }
        cout << BestString << endl;
    }

    return 0;
}