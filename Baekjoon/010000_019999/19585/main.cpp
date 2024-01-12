#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MAX_HASH_SIZE (100000)

unsigned int hash10(int idx, char c, unsigned int prev) {
    unsigned int ret = prev ;
    ret ^= (ret << 5) ^ ( (unsigned int) idx * 54059 ) ^ ((unsigned int) c * 86969) ^ (ret >> 5);
    return ret;
}
unsigned int hash10(string &s) {
    unsigned int ret = 0;
    int i, len = s.length();
    for ( i = 0 ; i < len ; i ++ )
        ret = hash10(i, s[i], ret);
    return ret;
}
vector<string> ColorList[MAX_HASH_SIZE], TeamList[MAX_HASH_SIZE];
int cmp(string &a, string &b) {
    return a.length() < b.length() ;
}

int LBArr(vector<string> &Arr, int target)
{
    int s, e, m ;
    s = 0, e = Arr.size()-1;
    while ( s < e ) {
        m = (s+e)/2;
        if ( Arr[m].length() >= target ) e = m ;
        else s = m + 1;
    }
    return e;
}

bool search(vector<string> &Arr, string &s, int len, bool reverse) {
    int k, slen = s.length() ;
    int l, r;

    for ( int i = LBArr(Arr, len) ; i < Arr.size() && Arr[i].length() == len ; i ++) {
        bool flag = true ;
        string &data = Arr[i];
        if ( reverse ) {
            for ( k = 0 ; k < len && flag ; k ++ ) {
                if (data[k] != s[slen-1-k] ) flag = false;
            }

        } else {
            for ( k = 0 ; k < len && flag ; k ++ ) {
                if (data[k] != s[k] ) flag = false;
            }
        }
        if (flag)
            return true ;
    }
    return false;
}

unsigned int lkey[2000+1]={0,};
bool find(string &s) {
    int i, len = s.length() ;
    unsigned int l, r ;

    memset(lkey, 0, sizeof(lkey));

    l = r = 0 ;
    for ( i = 0 ; i < len ; i ++ ) {
        lkey[ i ] = l = hash10(i, s[i], l);
    }
    r = 0;
    for ( i = 0 ; i < len - 1 ; i ++ ) {
        l = lkey[ len-2-i ] ;
        r = hash10(i, s[len-1-i], r);

        if (ColorList[l % MAX_HASH_SIZE ].size() <= 0 || TeamList[ r % MAX_HASH_SIZE].size() <= 0)
            continue;

        if ( !search(ColorList[ l % MAX_HASH_SIZE], s, len-1-i, false) )
            continue;

        if ( !search(TeamList[r % MAX_HASH_SIZE], s, i+1, true) )
            continue;

        return true;
    }
    return false;
}

int main()
{
    fastio;
    unsigned int key ;
    int C, N, Q ;
    string s ;

    cin >> C >> N;

    while (C--) {
        cin >> s ;
        key = hash10(s) % MAX_HASH_SIZE;
        ColorList[key].push_back(s);
    }
    while (N--) {
        cin >> s ;
        reverse(s.begin(), s.end());
        key = hash10(s) % MAX_HASH_SIZE;
        TeamList[key].push_back(s);
    }
    for (int i = 0 ; i < MAX_HASH_SIZE ; i ++ ) {
        if ( ColorList[i].size() > 0 )
            sort(ColorList[i].begin(), ColorList[i].end(), cmp);
        if ( TeamList[i].size() > 0 )
            sort(TeamList[i].begin(), TeamList[i].end(), cmp);
    }

    cin >> Q;
    while (Q--) {
        cin >> s ;
        cout << (find(s) ? "Yes" : "No") << "\n";
    }
    return 0;
}


