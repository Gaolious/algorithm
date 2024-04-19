#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

struct TrieData {
    bool isEnd = false;
    int count = 0;
};
typedef struct TRIE {
    TrieData data;
    TRIE *next[26]{};
} Trie;
void addTrie(string &s) {

}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N , i;
    string s ;
    fastio;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> s ;
        addTrie(s);
    }
    return 0;
}


