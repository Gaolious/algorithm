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

#define MAX_N (1000000)

int minButton = -1 ;
bool possible_button[ 11 ];
int numbers[7][11]={0,};
int number_size[7]={0,} ;

int tmp ;

int cmp( const void *_a, const void *_b)
{
    int a = *(int *)_a ;
    int b = *(int *)_b ;

    return abs(tmp-a) - abs(tmp-b) ;
}

void recur(int index, int currNo, int currButton, int targetNo, int multiply=1)
{
    if ( index < 0 )
        return ;

    for ( int i = 0 ; i < number_size[ index ] ; i ++ )
    {
        int next_channel = currNo + numbers[index][i] * multiply ;
        int btn_count = currButton + 1 ;

        minButton = min(
                minButton,
                btn_count + abs(targetNo - next_channel )
        );
        if ( minButton == 117 ) {
            cout << "";
        }

        recur(
                index -1 ,
                next_channel,
                btn_count,
                targetNo,
                multiply * 10
        );
    }
}
void process(int Case) {
    int i, j, n;
    int N, T ;
    cin >> N >> T ;

    for ( i = 0 ; i < 10 ; i ++)
        possible_button[ i ] = true ;

    while(T--) {
        cin >> n ;
        possible_button[n] = false;
    }

    for ( i = 0 ; i < 10 ; i ++ )
        if ( possible_button[ i ] )
        {
            for ( j = 0 ; j < 7 ; j ++ )
                numbers[ j ] [ number_size[j] ++ ] = i ;
        }

    for ( i = 6, j = 1, n=N ; i >= 0 ; i-- )
    {
        tmp = n % 10 ;
        qsort( numbers[ i ], number_size[i], sizeof(int), cmp );
        if ( n == 0 )
        {
            for (i--; i>=0 ; i--)
                number_size[ i ] = 0 ;
            break;
        }
        n/=10;
    }

    minButton = max(minButton, abs(N - 100 ) );

    recur(6, 0, 0, N );

    cout << minButton << '\n';
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
