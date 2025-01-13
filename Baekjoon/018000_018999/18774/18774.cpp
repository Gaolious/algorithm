#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T> pair<T,T> minxy(pair<T,T> a, pair<T,T> b) { return { min(a.first, b.first), min(a.second, b.second) }; }
template <typename T> pair<T,T> maxxy(pair<T,T> a, pair<T,T> b) { return { max(a.first, b.first), max(a.second, b.second) }; }
template <typename T> ll DIST2(pair<T,T>  a) {return a.first*a.first + a.second*a.second;}
template <typename T> ll DISTm(pair<T,T>  a) {return abs(a.first) + abs(a.second);}

void init(){
}
typedef unsigned char var;
string tobin(var n){
    string s;
    for ( int i = 7 ; i >= 0 ; i -- )
        s.push_back( ( n &(1<<i) ) ? '1' : '0');
    return s;
}
var tovar(string s) {
    int len = s.size();
    var ret = 0;

    for ( int i = 0 ; i < 7 ; i ++ )
        if ( i < s.size() && s[len-1-i] == '1' )
            ret |= 1 << i;
    return ret;
}

char toC(int idx) {
    return idx+'A';
}
void printGet(int from, int to) {
    for ( ;from <= to ; from ++ )
        cout << "get " << toC(from) << '\n';
}
void printPut(int from, int to) {
    for ( ;from <= to ; from ++ )
        cout << "put " << toC(from) << '\n';
}
void printSet(int idx, int from) {
    cout << "mov " << toC(idx) << ' ' << toC(from) << '\n';
}
void printAnd(int idx, int from) {
    cout << "and " << toC(idx) << ' ' << toC(from) << '\n';
}
void printOr(int idx, int from) {
    cout << "or " << toC(idx) << ' ' << toC(from) << '\n';
}
void printNot(int idx) {
    cout << "not " << toC(idx) << '\n';
}
void printshiftLeft(int idx, int bit) {
    cout << "shl " << toC(idx) << ' ' << bit << '\n';
}
void printshiftRight(int idx, int bit) {
    cout << "shr " << toC(idx) << ' ' << bit << '\n';
}
void printMergeNvars(int idx, int from, int to) {
    printSet(idx, to);
    for ( ;from <= to ; to -- ) {
        printshiftLeft(idx, 1);
        printOr(idx, to);
    }
}
void printSplitNvars(int idx, int from, int to) {
    for ( ;from <= to ; from++ ) {
        printSet(from, idx);
        cout << "and " << toC(from) << " 1 \n";
        printshiftRight(idx, 1);
    }
}
void process(int Case) {
    int i;
    printGet(0, 6);
    printMergeNvars(7, 0, 6); // 8개 bit를 변수 1개에
    printNot(7);
    printSplitNvars(7, 0, 6); // 8개 bit를 변수 1개에
    printPut(0, 6);
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ ) {
         process(i);
    }
    return 0;
}