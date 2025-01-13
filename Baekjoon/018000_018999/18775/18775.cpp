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
void test() {
    var A, B, C;
    var X, Y, Z, D, E, F, J, M, O, Q;
    X = tovar("00000100");
    Y = tovar("00000100");
    Z = tovar("000");

    A = X & Y;
    B = Y & Z;
    C = Z & X;

    cout << "X & Y = " << tobin(X & Y) << '\n';
    cout << "Y & Z = " << tobin(Y & Z) << '\n';
    cout << "Z & X = " << tobin(Z & X) << '\n';

    cout << "X | Y = " << tobin(X | Y) << '\n';
    cout << "Y | Z = " << tobin(Y | Z) << '\n';
    cout << "Z | X = " << tobin(Z | X) << '\n';

    D = A | B | C;
    cout << "A | B | C = " << tobin(A | B | C) << '\n';
    cout << "X | Y | Z = " << tobin(X | Y | Z) << '\n';
    cout << "X & Y & Z = " << tobin(X & Y & Z) << '\n';
    E = ~D;
    F = X | Y | Z;
    J = ~( (E & F) | (X & Y & Z) );

    cout << "E = " << tobin(E) << '\n';
    cout << "E & F = " << tobin(E&F) << '\n';
    cout << "J = " << tobin(J) << '\n';
    cout << "E & J = " << tobin(E&J) << '\n';
    cout << "D & J = " << tobin(D&J) << '\n';

    M = ( (Y | Z) & E & F ) | (Y & Z & D & J) | (E & J);
    O = ( (Z | X) & E & F ) | (Z & X & D & J) | (E & J);
    Q = ( (X | Y) & E & F ) | (X & Y & D & J) | (E & J);

    cout << "X : " << tobin(X) << '\n';
    cout << "X : " << tobin(M) << '\n';
    cout << "Y : " << tobin(Y) << '\n';
    cout << "Y : " << tobin(O) << '\n';
    cout << "Z : " << tobin(Z) << '\n';
    cout << "Z : " << tobin(Q) << '\n';

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
    printGet(0, 7);
    printGet(8, 15);
    printGet(16, 18);
    printMergeNvars(19, 0, 7); // 8개 bit를 변수 1개에
    printMergeNvars(20, 8, 15);
    printMergeNvars(21, 16, 18);

    // X & Y; // A=0
    i = 0; printSet(i, 19); printAnd(i, 20);
    // Y & Z;
    i = 1; printSet(i, 20); printAnd(i, 21);
    // Z & X;
    i = 2; printSet(i, 19); printAnd(i, 21);

    // X | Y;
    i = 3 ; printSet(i, 19); printOr(i, 20);
    // Y | Z;
    i = 4 ; printSet(i, 20); printOr(i, 21);
    // Z | X;
    i = 5 ; printSet(i, 19); printOr(i, 21);

    // A | B | C;
    i = 6; printSet(i, 0); printOr(i, 1); printOr(i, 2);
    // X | Y | Z;
    i = 7; printSet(i, 19); printOr(i, 4);
    // X & Y & Z;
    i = 8; printSet(i, 19); printAnd(i, 1);

    //E = ~(A|B|C)
    i = 9; printSet(i, 6); printNot(i);
    // E & F
    i = 10; printSet(i, 9); printAnd(i, 7);
    // J = ~( (E & F) | (X & Y & Z) )
    i = 11; printSet(i, 10); printOr(i, 8); printNot(i);
    // E & J
    i = 12; printSet(i, 9); printAnd(i, 11);
    // D & J
    i = 13; printSet(i, 6); printAnd(i, 11);

    i=6; printSet(i, 4); printAnd(i, 10);
    i=7; printSet(i, 1); printAnd(i, 13);
    i=19; printSet(i, 12); printOr(i, 6);printOr(i, 7);

    i=6; printSet(i, 5); printAnd(i, 10);
    i=7; printSet(i, 2); printAnd(i, 13);
    i=20; printSet(i, 12); printOr(i, 6);printOr(i, 7);

    i=6; printSet(i, 3); printAnd(i, 10);
    i=7; printSet(i, 0); printAnd(i, 13);
    i=21; printSet(i, 12); printOr(i, 6);printOr(i, 7);

    printSplitNvars(19, 0, 7); // 8개 bit를 변수 1개에
    printSplitNvars(20, 8, 15);
    printSplitNvars(21, 16, 18);

    printPut(0, 7);
    printPut(8, 15);
    printPut(16, 18);
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
/*
A B C D E F G H I J K L M N O P Q R S
0 1 0 0 1 1 0 0 0 1 1 1 0 0 0 0 1 1 1

 1. Z = S ~ M 까지 ( 7 )
 2. Y = L ~ G 까지 ( 6 )
 3. X = F ~ A 까지 ( 6 )

 A = X & Y
 B = Y & Z
 C = Z & X
 D = A | B | C
 E = ~D

 F = X | Y | Z
 G = E & F
 H = X & Y & Z

 I = G | H
 J = ~I

 K = E & J

 L = D & J

 M = ( (Y | Z) & G )
 N = (Y & Z & L)
 M = M | N | K

 O = (Z | X) & G
 P = Z & X & L

 O = O | P | K

 Q = ( X | Y ) & G

 R = X & Y & L

 Q = Q | R | K

 X = M
 Y = O
 Z = Q

 X = 1 0 0 0 0 0 0(2)
 Y =   0 0 1 0 0 0(2)
 Z =   0 0 0 0 0 1(2)
 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 0
 * */