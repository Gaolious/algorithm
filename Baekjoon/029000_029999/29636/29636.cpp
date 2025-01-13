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

string S;
vector<string> Element;
vector<vector<int>> Candidates;
vector<int> P;

struct Data {
    int cnt;
    vector<ll> possible;
};
vector<Data> D;

void init(){
}

void addCandidates(int idx, int offset, int minEIdx, int maxEIdx) {
    int l, r, m, lo, hi ;
    if ( minEIdx > maxEIdx )
        return;
    lo = 10000, hi = -1;

    for ( l = minEIdx, r = maxEIdx ; l <= r ; ) {
        m = ( l + r ) / 2 ;
        if ( S[idx + offset] > Element[m][offset] )
            l = m + 1;
        else {
            lo = min(lo, m) ;
            r = m-1;
        }
    }
    for ( l = minEIdx, r = maxEIdx ; l <= r ; ) {
        m = ( l + r ) / 2 ;
        if ( S[idx + offset] >= Element[m][offset] ) {
            hi = max(hi, m);
            l = m + 1;
        }
        else r = m-1;
    }
    while ( lo <= hi && Element[lo].size() == offset+1 )
        Candidates[idx].push_back(lo++);

    addCandidates(idx, offset+1, lo, hi);
}

void dumpCandidates(){
    int i;
    for ( i = 0 ; i < S.size() ; i ++ ) {
        cout << "Idx[" << i << "] : " << S[i] <<  '\n';
        for (auto lo: Candidates[i] ) cout << '\t' << Element[lo] << ' ';
        cout << '\n';
    }
}
bool Used[1000];
int best = -1;
int UsedIndex[1000];
int ans[1000];

void F(int idx, int cnt) {
    if ( idx >= S.size() ) {
        if ( idx == S.size() ) {
            // update best
            if ( best < 0 || best > cnt ) {
                best = cnt ;
                memcpy(ans, UsedIndex, sizeof(UsedIndex));
            }
        }
        return;
    }
    int remainLen = S.size();
    remainLen -= idx;
    if ( best > 0 && (remainLen+2)/3 + cnt >= best ) return;

    for ( auto candidateIndex: Candidates[idx] ) {
        if ( Used[ candidateIndex ] ) continue;
        Used[ candidateIndex ] = true;
        UsedIndex[cnt] = candidateIndex ;
        F(idx + Element[candidateIndex].size(), cnt + 1);
        UsedIndex[cnt] = -1 ;
        Used[ candidateIndex ] = false;
    }
}

void process(int Case) {
    int N, i, j ;
    cin >> S;
    cin >> N ;
    Element.resize(N);
    Candidates.resize(S.size());
    memset(UsedIndex, -1, sizeof(UsedIndex));

    for(auto &s: Element) cin >> s ;
    std::sort(Element.begin(), Element.end());

    for ( i = 0 ; i < S.size() ; i ++ ) {
        addCandidates(i, 0, 0, N - 1);
        std::sort(Candidates[i].begin(), Candidates[i].end(), [](int a, int b) {
            return Element[a].size() > Element[b].size();
        });
    }
//    dumpCandidates();
    F(0, 0);
    cout << best << '\n';
    for ( i = 0 ; i < best ; i ++ ) {
        cout << Element[ans[i]] << '\n';
    }
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
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
