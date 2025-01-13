#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

char M[21][21];
int N ;
//#ifdef AJAVA_DEBUG
//void dumpBin(int size, int val) {
//    for ( int i = size-1 ; i >= 0 ; i -- ) {
//        cout << ( ( val & (1 << i) ) ? 1 : 0 ) << ' ';
//    }
//    cout << endl;
//}
//#endif

struct Data {
    bool isVertical{};
    int len{};
    int index{};
    vector<int> OneCnt;
    vector<pii> range;
    vector<int> possibles;
    void input(int idx, bool isV) {
        int n;
        cin >> n;
        len = N - idx;
        index = idx;
        isVertical = isV;
        OneCnt.resize(n);
        range.resize(n);
        for (auto &v: OneCnt) cin >> v;
    }
    void genByOneCnt() {
        int i, j, n, c;
        n = OneCnt.size();

        for( c = i = 0 ; i < n ; i ++, c+=2 ) {
            range[i].first = c ;
            c = c + OneCnt[ i ] - 1 ;
        }
        for( c = len - 1, i = n - 1 ; i >= 0 ; i --, c-=2 ) {
            range[i].second = c ;
            c = c - OneCnt[ i ] + 1;
        }

        c = -1;
        for ( i = 0 ; i < n ; i ++ ) {
            for ( j = range[i].second - OneCnt[i] + 1 ; j <= range[i].first + OneCnt[i] - 1 ; j ++ ) {
                if ( isVertical ) M[j][index] = 1;
                else M[index][j] = 1;
            }
            if ( c + 2 == range[i].first ) {
                if (isVertical) M[ range[i].first - 1 ][index] = 0;
                else M[index][ range[i].first - 1 ] = 0;
            }
            c = range[i].second;
        }
        if ( n == 0 ) {
            for ( j = 0 ; j < len ; j ++ ) {
                if (isVertical) M[j][index] = 0;
                else M[index][j] = 0;
            }
        }
    }

    void SetAnswer(int n ) {
        int i, v ;

//#ifdef AJAVA_DEBUG
//        cout << "Set Answer Col Index=" << index << " / len = " << len << " : " ;
//        dumpBin(len, n);
//#endif
        for ( i = 0 ; i < len ; i ++ ) {
            v = ( ( n >> ( len - i - 1 ) ) & 1 ) ? 1 : 0;

            if (isVertical)
                M[ i ][ index ] = v;
            else
                M[ index ][ i ] = v;
        }
    }
};
void get_possibles(Data &d, int remainSize, int remainSum, int idx, int val, int mask1, int mask0){
    if ( d.OneCnt.empty() ) {
        d.possibles.push_back(0);
        return;
    }
    int loopI = remainSize - ( d.OneCnt.size() - idx - 1 ) - remainSum;
    int t, cnt, addMask, endPos ;
    int reservedCnt = d.len - remainSize;
    int reservedMask = (( 1 << reservedCnt ) - 1) << remainSize;
    int filter = mask1 & reservedMask ;
    if ( ( val & filter ) != filter )
        return;
    filter = mask0 & reservedMask ;
    if ( ( (~val) & filter ) != filter )
        return;

    if ( d.OneCnt.size() <= idx ) {
        d.possibles.push_back(val);
        return;
    }

    for ( int i = 0 ; i <= loopI ; i ++ ) {
        cnt = d.OneCnt[idx];
        addMask = ( 1 << cnt ) - 1;
        endPos = remainSize - i - cnt;

        t = val | ( addMask << ( endPos )) ;
        get_possibles(d, max(0, endPos - 1), remainSum-cnt, idx+1, t, mask1, mask0);
    }
}
void genPossible(Data &d) {
    int i, j;
    int mask1 = 0, mask0 = 0, m ;
    int s = 0;

    for ( j = 0 ; j < d.len ; j ++ ) {
        m = 1 << ( d.len-1-j);
        if ( d.isVertical ) {
            if (M[j][d.index] == 1) mask1 += m;
            if (M[j][d.index] == 0) mask0 += m;
        }
        else {
            if (M[d.index][j] == 1) mask1 += m;
            if (M[d.index][j] == 0) mask0 += m;
        }
    }

    for ( auto n: d.OneCnt )
        s += n;
    get_possibles(d, d.len, s, 0, 0, mask1, mask0);
}

vector<Data> Row;
vector<Data> Col;
void init(){}

void dump() {
    int i, j ;

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N - i ; j ++ ) {
            if (M[i][j] < 0) cout << setw(2) << ".";
            else cout << (int)M[i][j];
            cout << ' ' ;
        }
        cout << '\n';
    }
}
pii Range[21][21];
pii getRangeOfRow(pii range, Data &row, int offset, int val) {
    int l, r, m, v ;
    pii ret1 = range, ret0 = range;
    l = range.first, r = range.second ;
    while ( l <= r ) {
        m = (l+r)/2;
        v = ( row.possibles[m] >> ( row.len - 1 - offset ) ) & 1;
        if ( v == 1 ) {
            r = m - 1;
            ret1.first = m;
            ret0.second = m-1;
        }
        else {
            l = m + 1;
            ret1.first = m+1;
            ret0.second = m;
        }
    }
    if ( val == 0 ) return ret0;
    else return ret1;
}

bool F(int idx) {
    int i, j, col;

    if ( idx >= N )
        return true;

    for ( j = 0 ; j < Col[idx].possibles.size() ; j ++ ) {
        col = Col[idx].possibles[j];
//#ifdef AJAVA_DEBUG
//        cout << "Try Col[" << idx << "] : ";
//        dumpBin(Col[idx].len, col);
//#endif
        bool possible = true ;
        for ( i = 0 ; i < Col[idx].len ; i ++ ) {
            int v = (col >> ( Col[idx].len - i - 1 )) & 1 ;
            Range[idx + 1][ i ] = getRangeOfRow( Range[idx][i], Row[i], idx, v );
            if ( Range[idx + 1][ i ].first > Range[idx+1][i].second ) {
                possible = false;
                break;
            }
        }
        if ( possible && F(idx+1) ) {
            Col[idx].SetAnswer(col);
            return true;
        }
    }
    return false;
}
void process(int Case) {
    int i;

    cin >> N ;
    Row.resize(N); Col.resize(N);
    memset(M, -1, sizeof(M));

    for ( i = 0 ; i < N ; i ++ ) Row[i].input(i, false);
    for ( i = 0 ; i < N ; i ++ ) Col[i].input(i, true);
    for ( i = 0 ; i < N ; i ++ ) {
        int s = 0 ;
        for (auto n: Row[i].OneCnt ) s += n;
        if ( Row[i].OneCnt.size() > 1 ) s += Row[i].OneCnt.size() - 1;
        if ( s > N - i ) {
            cout << "No Answer\n";
            return;
        }
        s = 0 ;
        for (auto n: Col[i].OneCnt ) s += n;
        if ( Row[i].OneCnt.size() > 1 ) s += Col[i].OneCnt.size() - 1;
        if ( s > N - i ) {
            cout << "No Answer\n";
            return;
        }
    }
    for ( i = 0 ; i < N ; i ++ ) Row[i].genByOneCnt();
    for ( i = 0 ; i < N ; i ++ ) Col[i].genByOneCnt();

    for ( i = 0 ; i < N ; i ++ ) genPossible(Row[i]);
    for ( i = 0 ; i < N ; i ++ ) genPossible(Col[i]);

    for ( i = 0 ; i < N ; i ++ ) {
        std::sort(Row[i].possibles.begin(), Row[i].possibles.end());
        std::sort(Col[i].possibles.begin(), Col[i].possibles.end());
    }

    for ( i = 0 ; i < N ; i ++ )
        Range[0][i] = { 0, (int)(Row[i].possibles.size()) - 1 };

    if ( F(0) ) {
        dump();
    }
    else {
        cout << "No Answer\n";
    }
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
