#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

struct PIPE {
    int size;
    int cumLargerSize;
    int count;
    int cumLargerCount;
};
int M, N ;
vector<int> OriginalLongPipe;
vector<int> LongPipe;
int totalLongPipeLength ;
vector<PIPE> OriginalShortPipe; // backup.
vector<PIPE> ShortPipe;

int best = 0 ;
int maxWaste = 0;

void input() {
    int i, n, s, maxLongPipe ;
    int A[128]={0,};

    cin >> M ;
    OriginalLongPipe.resize(M);
    totalLongPipeLength = 0 ;
    maxLongPipe = 0 ;
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> OriginalLongPipe[i] ;
        totalLongPipeLength += OriginalLongPipe[i];
        maxLongPipe = max( maxLongPipe, OriginalLongPipe[i] );
    }
    std::sort(OriginalLongPipe.begin(), OriginalLongPipe.end());

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> n ;
        if ( n <= maxLongPipe )
            A[n]++;
    }

    for ( s = 0, i = 1 ; i <= 128 && s < totalLongPipeLength ; i ++ )
    if ( A[ i ] > 0 )
    {
        PIPE pipe = {0, };
        pipe.count = A[i];
        pipe.size = i ;

        if ( s + i * A[ i ] >= totalLongPipeLength )
            pipe.count = (totalLongPipeLength - s ) / i ;
        if ( pipe.count == 0 )
            break;

        OriginalShortPipe.push_back(pipe);
        s += i * A[ i ];
    }
}

int generatePipeVector(int maxPipeCount) {
    int s, len, cumlen ;
    int i ;

    s = 0;
    LongPipe.clear();
    for ( auto p: OriginalLongPipe) {
        LongPipe.push_back(p);
    }

    ShortPipe.clear();
    cumlen = 0;
    for (auto p : OriginalShortPipe ) {
        if ( s + p.count >= maxPipeCount ) {
            p.count = maxPipeCount - s ;
        }
        if ( p.count == 0 ) break;
        ShortPipe.push_back(p);
        s += p.count;
        cumlen += p.count * p.size ;
    }
    maxWaste = totalLongPipeLength - cumlen;

    std::sort(ShortPipe.begin(), ShortPipe.end(), [](PIPE &a, PIPE &b) {
        return a.size > b.size;
    });
    int cnt = 0 ;
//    for ( auto &large : LongPipe ) {
//        for ( auto &small : ShortPipe ) {
//            if ( small.size == large && small.count > 0 )
//            {
//                large = 0;
//                small.count --;
//                cnt ++;
//            }
//        }
//    }
//    auto it1 = std::remove_if(LongPipe.begin(), LongPipe.end(), [&](int n) -> bool { return n <= 0 ; });
//    LongPipe.erase( it1, LongPipe.end());
//
//    cnt = ShortPipe.size();
//    auto it2 = std::remove_if(ShortPipe.begin(), ShortPipe.end(), [&](PIPE &p) -> bool { return p.count <= 0 ; });
//    ShortPipe.erase( it2, ShortPipe.end());
//    cnt -= ShortPipe.size();

//    len = (int)ShortPipe.size();
//    for ( i = len-2 ; i >= 0 ; i -- ) {
//        ShortPipe[i].cumLargerCount = ShortPipe[i+1].cumLargerCount + ShortPipe[i+1].count;
//        ShortPipe[i].cumLargerSize = ShortPipe[i+1].cumLargerSize + ShortPipe[i+1].count * ShortPipe[i+1].size;
//    }

    return cnt;

}
int findShortIdx(int val) {
    int l, r, ret, m;
    l = 0, r = (int)(ShortPipe.size()-1) ;

    if ( ShortPipe[0].size < val ) return 0;
    else if ( ShortPipe[ r ].size > val ) return r + 1;

    ret = 0 ;
    while ( l <= r ) { // desc order
        m = ( l + r ) / 2 ;
        if ( ShortPipe[m].size >= val ) {
            ret = m;
            l = m + 1 ;
        } else {
            r = m - 1;
        }
    }
    return ret;
}
int predict_waste(int longIdx) {
    int D[100001]={0,};
    int maxValue = 0 ;
    int i, j ;

    D[ 0 ] = 1;

    for (auto &s : ShortPipe ) {
        if ( s.count == 0 ) continue;
        maxValue = min( LongPipe[longIdx] , max(s.size, maxValue) );

        for ( i = maxValue ; i >= s.size ; i -- )
            if ( D[ i - s.size ] )
            {
                for ( j = 1 ; j <= s.count && i + s.size * j <= LongPipe[longIdx] ; j ++ )
                {
                    D[i + s.size * j] = 1;
                    maxValue = max(maxValue, i + s.size * j);
                }
            }

        if ( D[LongPipe[longIdx] ] > 0 )
            return 0 ;
    }
    for ( i = 1 ; i <= LongPipe[longIdx] ; i ++ ) {
        if ( D[ LongPipe[longIdx] - i ] > 0 )
            return i;
    }
    return LongPipe[longIdx];
}

bool possible(int shortIdx, int longIdx, int remainShortPipeCount, int waste) {
    // cut 1
    if (remainShortPipeCount == 0 )
        return true ;

    // cut 2
//    if ( ShortPipe[shortIdx].cumLargerCount + ShortPipe[shortIdx].count < remainShortPipeCount)
//        return false ;

    // cut 3
    if ( maxWaste < waste )
        return false;
//    int t = predict_waste(longIdx);
//    if ( maxWaste < waste + t ) {
//        return false;
//    }

    int i, sumSize, sumCount  ;
    int lenShort = (int)ShortPipe.size() ;
    int lenLong = (int)LongPipe.size() ;

    // cut 4
    if ( shortIdx >= lenShort || longIdx >= lenLong )
        return false ;

    // cut 5
    int &longPipe = LongPipe[longIdx];
//    for ( i = shortIdx ; i < lenShort ; i ++ )
//    {
//        PIPE &sp = ShortPipe[i];
//        if ( sp.size == longPipe && sp.count > 0 )
//        {
//            sp.count--;
//            longPipe -= sp.size;
//            if (possible(findShortIdx(longPipe), longIdx+1, remainShortPipeCount - 1, waste) )
//                return true ;
//            sp.count++;
//            longPipe += sp.size;
//            return false;
//        }
//    }
    for ( i = shortIdx ; i < lenShort ; i ++ )
    {
        PIPE &sp = ShortPipe[i];

#ifdef AJAVA_DEBUG
//        printf("\nshortIdx:%d(loop:%d), longIdx:%d, remainShortPipeCount:%d, waste:%d", shortIdx, i, longIdx, remainShortPipeCount, waste);
//        printf("\nLong Pipe : ");
//        for (auto _L: LongPipe) { printf("%d ", _L); }
//        printf("\nShortPipe : ");
//        for (auto _L: ShortPipe) { printf("%d(%d) ", _L.size, _L.count); }
//        printf("\n");
#endif
        if ( longPipe > sp.size && sp.count > 0 ) {
            sp.count--;
            longPipe -= sp.size;
            if ( possible(findShortIdx(longPipe), longIdx, remainShortPipeCount - 1, waste) )
                return true;
            longPipe += sp.size;
            sp.count++;
        }
    }
    return possible(findShortIdx(LongPipe[longIdx+1]), longIdx + 1, remainShortPipeCount, longPipe + waste);
}

void process() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int lo, hi, m, cnt ;
    input();

    lo = 0 ;
    hi = N ;
    while ( lo <= hi ) {
        m = ( lo + hi ) / 2 ;
        cnt = generatePipeVector(m);


#ifdef AJAVA_DEBUG
        cout << "try to find " << m << " with max waste " << maxWaste << endl;
#endif
        if (possible(0, 0, m - cnt, 0) ) {
            lo = m + 1 ;
            best = max(best, m);
#ifdef AJAVA_DEBUG
            cout << "update best : " << best << endl;
#endif
        } else {
            hi = m - 1;
        }
    }
    cout << best << endl;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


