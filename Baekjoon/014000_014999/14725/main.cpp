#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
char blanks[20][50];
struct Trie {
    map<string, Trie> data;
    bool is_end;
    Trie(): is_end(false){}
    bool has(string &s) {
        return data.find(s) != data.end();
    }
    Trie *add(string &s) {
        data.insert({s, Trie()});
        return &data[s];
    }
    Trie *get(string &s) {
        return &data[s];
    }
    Trie *get_or_create(string &s) {
        return has(s) ? get(s) : add(s);
    }
    void print(int depth) {
        for (auto curr = data.begin() ; curr != data.end() ; curr ++ ) {
            cout << blanks[depth] << curr->first << "\n";
            curr->second.print(depth+1);
        }
    }
};

int main()
{
    string s ;
    Trie root, *curr ;

    fastio;
    int N, i, j, K ;
    for ( i = 0 ; i < 20 ; i ++ )
        for ( j = 0 ; j < i*2 ; j ++ )
            blanks[i][j] = '-';

    cin >> N ;

    while (N--) {
        cin >> K ;
        for ( i = 0, curr = &root ; i < K ; i ++ ) {
            cin >> s ;
            curr = curr->get_or_create(s);
        }
    }
    root.print(0);
    return 0;
}


