#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Trie {
    map<char, Trie> data;
    bool is_end;
    Trie():is_end(false){}
    bool has(char c) {
        return this->data.find(c) != this->data.end();
    }
    Trie *trie(char c) {
        return &(this->data[c]);
    }
};
void addTrie(Trie *root, string &s, bool foward) {
    Trie *curr ;
    int i ;
    if (!s.empty()) {
        int len = s.size();
        if (foward) {
            for (i = 0, curr=root ; i < len ; curr = curr->trie(s[i++])) {
                if ( !curr->has(s[i]) )
                    curr->data.insert({s[i], Trie()});
            }
        }
        else {
            for (i = len-1, curr=root ; i >= 0 ; curr = curr->trie(s[i--])) {
                if ( !curr->has(s[i]) )
                    curr->data.insert({s[i], Trie()});
            }
        }
        curr->is_end = true;

    }
}

Trie Color, Team ;
bool Check[2000+1];
bool find(string &s) {
    Trie *color, *team;
    int i, j ;
    memset(Check, 0, sizeof(Check));

    int len = s.length();
    for ( i = 0, color=&Color ; i < len && color->has(s[i]) ; ) {
        color = color->trie(s[i++]);
        if (color->is_end)
            Check[i-1] = true;
    }
    for ( i = len-1, team=&Team ; i > 0 && team->has(s[i]) ; ) {
        team = team->trie(s[i--]);
        if (team->is_end) {
            if (Check[i])
                return true;
        }
    }
    return false;
}
int main()
{
    fastio;
    int C, N, Q ;
    string s ;

    cin >> C >> N;

    while (C--) {
        cin >> s ;
        addTrie(&Color, s, true);
    }
    while (N--) {
        cin >> s ;
        addTrie(&Team, s, false);
    }

    cin >> Q;
    while (Q--) {
        cin >> s ;
        cout << (find(s) ? "Yes" : "No") << "\n";
    }
    return 0;
}


