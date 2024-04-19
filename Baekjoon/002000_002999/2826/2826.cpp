#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
struct VAR {
    bool is_number ;
    int loopIndex;
    ll number ;
};

struct LOOP {
    VAR left ;
    VAR right ;
    vector<int> childs;
    bool is_include(ll value ) const {
        if ( this->left.is_number )
            return this->left.number <= value ;
        else if ( this->right.is_number )
            return value <= this->right.number ;
        else
            return this->left.number <= value && value <= this->right.number;
    }
};
ll M = 1'000'000'007;
int N ;
 const int MaxN = 100000;
//const int MaxN = 10;

ll D[26][MaxN+1];
vector<LOOP> ForLoop;
ll CountChild(int nth, ll value);
ll Count(int nth, ll value);

void Parse(char str[], VAR &v) {

    if ( '0' <= str[0] && str[0] <= '9'){
        ll ret = 0;
        char *p = str ;
        while ( p && *p > ' ' )
            ret = ret * 10 + (ll)(*p++ - '0');
        v.is_number = true;
        v.number = ret;
    }
    else {
        v.is_number = false ;
        v.loopIndex = (int)(str[0] - 'a');
    }
}

void input() {
    char str[10];
    int i ;

    memset(D, -1, sizeof(D));
    scanf("%d ", &N);
    ForLoop.resize(N);

    for ( i = 0 ; i < N ; i ++ ) {
        LOOP &loop = ForLoop[i];

        scanf("%s ", str);
        Parse(str, loop.left);

        scanf("%s ", str);
        Parse(str, loop.right);

        if ( !loop.left.is_number )
            ForLoop[ loop.left.loopIndex ].childs.push_back(i);
        else if ( !loop.right.is_number )
            ForLoop[ loop.right.loopIndex ].childs.push_back(i);
    }
}

//  a : 1   3
//  b : a   4
//  d : b   3
//  c : 2   a
//  e : 1   10
//  Count('a') : 5
//      Count('a', 1) : 0
//          CountChild('b', a=1) : 6    D['b'][1] = 6
//              CountChild('d', b=1) : 3  D['d'][1] = 3
//              CountChild('d', b=2) : 2  D['d'][2] = 2
//              CountChild('d', b=3) : 1  D['d'][3] = 1
//              CountChild('d', b=4) : 0  D['d'][4] = 0
//          CountChild('c', a=1) : 0
//      Count('a', 2) : 3
//          CountChild('b', a=2) : 3
//              CountChild('d', b=2) : 2
//              CountChild('d', b=3) : 1
//              CountChild('d', b=4) : 0
//          CountChild('c', a=2) : 1
//      Count('a', 3) : 2
//          CountChild('b', a=3) : 1
//              CountChild('d', b=3) : 1
//              CountChild('d', b=4) : 0
//          CountChild('c', a=3) : 2
//  Count('e') : *10

ll Count(int nth, ll value) {
    ll &ret = D[nth][value];
    if ( ret < 0 ) {
        ret = 0 ;
        if ( ForLoop[nth].is_include(value) )
        {
            if (ForLoop[nth].right.is_number )
                ret = ( value < ForLoop[nth].right.number ) ? Count(nth, value+1) : 0;
            else
                ret = ( value > ForLoop[nth].left.number ) ? Count(nth, value-1) : 0;

            ret = (ret + CountChild(nth, value)) % M ;
        }
    }

    return ret ;
}

ll CountChild(int nth, ll value ) {
    ll multi = 1;
    for ( auto childIdx : ForLoop[nth].childs )
        multi = ( multi * Count(childIdx, value) ) % M ;
    return multi;
}

void process() {
    input();
    int i;
    ll ret = 1;

    memset(D, -1, sizeof(D));

    for ( i = 0 ; i < N ; i ++ )
        if (ForLoop[i].left.is_number && ForLoop[i].right.is_number )
            ret = ( ret * Count(i, ForLoop[i].left.number) ) % M ;
//
//    for ( j = 0 ; j <= MaxN ; j ++ )
//        printf("%3d ", j);
//    printf("\n");
//
//    for ( i = 0 ; i < N ; i ++ ) {
//        for ( j = 0 ; j <= MaxN ; j ++ )
//            printf("%3lld ", D[i][j]);
//        printf("\n");
//    }
    printf("%lld\n", ret);
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


