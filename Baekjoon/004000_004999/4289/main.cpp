#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);

using namespace std;


typedef struct _data_
{
    int nGames;
    int nDraws;
    int nWins;
    int nLoses;
} DATA;

bool isDraw(char l[], char r[])
{
    return ( l[0] == r[0] );
}
bool LeftWin(char l[], char r[])
{
    if ( l[0] == 'r' && r[0] == 's') return true ;
    if ( l[0] == 's' && r[0] == 'p') return true ;
    if ( l[0] == 'p' && r[0] == 'r') return true ;
    return false ;
}
bool RightWin(char l[], char r[])
{
    return LeftWin(r,l);
}
void process()
{
    int n, k ;
    char t1[1000], t2[1000]={0,};
    int w1, w2, c1, c2;
    int i ;
    int t;
    char *c ;


    for ( t = 0 ; ; t ++ )
    {
        cin >> n ;
        if ( n == 0 ) break;

        vector<DATA> data(n+1);

        cin >> k ;

        for ( i = 1 ; i <= n ; i ++)
            data[i].nGames = data[i].nLoses = data[i].nWins = 0 ;
        k = k * n*(n-1)/2;
        for ( i = 0 ; i < k ; i ++ )
        {

            cin >> w1 >> t1 >> w2 >> t2 ;

            if ( isDraw(t1, t2) )
            {
                // data[w1].nDraws ++;
                // data[w2].nDraws ++;
            }
            else if ( LeftWin( t1, t2 ) )
            {
                data[w1].nGames ++;
                data[w2].nGames ++;
                data[w1].nWins ++;
                data[w2].nLoses ++;
            }
            else
            {
                data[w1].nGames ++;
                data[w2].nGames ++;
                data[w2].nWins ++;
                data[w1].nLoses ++;
            }
        }

        if ( t ) cout << '\n';

        for ( i = 1 ; i <= n ; i ++)
        {
            if ( data[i].nWins + data[i].nLoses < 1 )
                cout << "-\n";
            else
            {
                double ans = (double)(data[i].nWins) / (double)(data[i].nWins + data[i].nLoses);
                long long int Ans = (long long int)(ans * 10000);
                if (Ans%10 < 5) Ans /= 10;
                else Ans = (Ans/10)+1;

                long long int d, f ;
                d = Ans / 1000 ;
                f = Ans % 1000 ;
                cout << d << '.' << setfill('0') << setw(3) << f << '\n';
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    clock_t t = clock();
#else
#endif

    process();

#ifndef ONLINE_JUDGE
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
    printf("\n[Press Enter to Continue ...]");
#else
#endif
    return 0;
}
