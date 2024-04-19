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

string word, text;
vector<int> Table;

struct Data {
    deque<char> LQ, MQ, RQ;
    int LQIdx, RQIdx;
    bool isWordInLQ() {
        int i;
        if ( word.size() > LQ.size() ) return false;
        i = LQ.size() - word.size();
        for (auto c : word) if ( c != LQ[i++] ) return false;
        return true;
    }
    bool PushToLeft() {
        if ( !MQ.empty() ) {
            LQ.push_back(MQ.front());
            MQ.pop_front();
            return true;
        }
        if ( !RQ.empty() ) {
            LQ.push_back(RQ.front());
            RQ.pop_front();
            return true;
        }
        return false;
    }
    bool isWordInRQ() {
        int i;
        if ( word.size() > RQ.size() ) return false;
        i = 0;
        for (auto c : word) if ( c != RQ[i++] ) return false;
        return true;
    }
    bool PushToRight() {
        if ( !MQ.empty() ) {
            RQ.push_front(MQ.back());
            MQ.pop_back();
            return true;
        }
        if ( !LQ.empty() ) {
            RQ.push_front(LQ.back());
            LQ.pop_back();
            return true;
        }
        return false;
    }
};

void genTable() {
    int i, j ;

    Table.resize(word.size());
    for ( j=0, i=j+1 ; i < word.size() ; i ++ ) {
        while ( j > 0 && word[i] != word[j] )
            j = Table[j-1];
        if ( word[i] == word[j] )
            Table[i] = ++j;
    }

}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i;
    Data D;
    bool found ;
    cin >> word >> text;
    for ( auto c: text ) D.MQ.push_back(c);


    while ( true ) {
        found = false ;
        while ( D.PushToLeft() ) {
            if ( D.isWordInLQ() ) {
                for(i = 0 ; i < word.size() ; i ++) D.LQ.pop_back();
                found = true ;
                break;
            }
        }

        if ( !found) break;

        while ( D.PushToRight() ) {
            if ( D.isWordInRQ() ) {
                for(i = 0 ; i < word.size() ; i ++) D.RQ.pop_front();
                break;
            }
        }
    }
    for (auto c: D.LQ) cout << c ;
    for (auto c: D.MQ) cout << c ;
    for (auto c: D.RQ) cout << c ;
    return 0;
}