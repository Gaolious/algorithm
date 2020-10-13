#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

namespace FIO 
{
    const static int BUFF_SIZE = 1<<21;
    static char buf[BUFF_SIZE];
    static char *p = buf + BUFF_SIZE;
    static int last_read = 0 ;
    inline static bool readByte(char &ret)
    {
        if ( p - buf >= BUFF_SIZE )
        {
            // last_read = (int)read(0, (void *)buf, sizeof(buf));
            last_read = (int)fread(buf, sizeof(char), sizeof(buf), stdin);
            p = buf ;
        }
        else if ( last_read < BUFF_SIZE )
        {
            if ( (int)( p - buf) >= last_read ) // EOF
            {
                ret = 0x00 ;
                return false;
            }
        }
        ret = *p++;
        return true ;
    }

    inline bool readInt(int *ret)
    {
        int n = 0 ;
        int flag = 0 ;
        register char c ;
        if (!readByte(c)) return false;
        
        while (c <= ' ') 
            if ( !readByte(c) ) return false;
        
        if (c == '-') 
        {
            flag = 1;
            if ( !readByte(c) ) return false;
        }

        while ( c > ' ' ) {
            n = n * 10 + c - '0';
            if (!readByte(c) ) break;
        }
        *ret = flag ? -n : n;
        return true ;
    }

    inline bool readChar(FILE *fp, char *ret)
    {
        register char c;
        if ( !readByte(c) ) return false ;
        
        while (c <= ' ') 
            if (!readByte(c) ) return false ;

        *ret = c;
        return true ;
    }

    inline static int readLine(char *str, int maxLen )
    {
        register char c = 0x00 ;
        int i ;

        while (c < ' ' )
            if ( !readByte(c) ) return false ;

        for ( i = 0 ; i < maxLen && c && c != '\n' ; i ++, readByte(c) )
            str[i] = c ;
        str[ i ] = 0x00 ;
        return i;
    }

    char outbuf[BUFF_SIZE + 20];
    char* outp = outbuf;

    void printInt(int n)
    {
        unsigned nn;
        if (n < 0) nn = -n, *outp++ = '-';
        else nn = n;
        char *end = outp;
        do
        {
            *end++ = nn % 10 + '0';
            nn /= 10;
        } while (nn);
        reverse(outp, end);
        if (end < outbuf + BUFF_SIZE) outp = end;
        else
        {
            syscall(0x01, 1, outbuf, end - outbuf);
            outp = outbuf;
        }
    }

    void printChar(char c)
    {
        char *end = outp;
        *end++ = c;
        if (end < outbuf + BUFF_SIZE) outp = end;
        else
        {
            syscall(0x01, 1, outbuf, end - outbuf);
            outp = outbuf;
        }
    }
    void printNewline()
    {
        printChar('\n');
    }
    void flush()
    {
        syscall(0x01, 1, outbuf, outp - outbuf);
    }    
} 

void dump(char *s, int width, int gap)
{
    int i = 0 ;


}

void dump(char T[], int offsetT, int posT, int width)
{
    int lenT = strlen(T);
    int i ;
    printf("%*s", offsetT*width , "");
    for ( i = 0 ; i < lenT ; i ++ )
    {
        if ( i == posT ) 
            printf(" *%c", T[i]);
        else
            printf("  %c", T[ i ]);
    }
    printf("\n");
}
void dump2(int F[], char T[], int offsetT, int posT, int width)
{
    int lenT = strlen(T);
    int i ;
    printf("%*s", offsetT*width , "");
    for ( i = 0 ; i < lenT ; i ++ )
    {
        if ( i == posT ) 
            printf(" *%c", T[i]);
        else
            printf("  %c", T[ i ]);
    }
    printf("\n");
    if (F)
    {
        printf("%*s", offsetT*width , "");
        for ( i = 0 ; i < lenT ; i ++ )
        {
            if ( i == posT ) 
                printf(" *%d", F[i]);
            else
                printf("  %d", F[ i ]);
        }
        printf("\n");

    }
}

void dump(int F[], char T[], int offsetT, int posT, char P[], int offsetP, int posP)
{
    dump2(NULL, T, offsetT, posT, 3);
    dump2(F, P, offsetP, posP, 3);
    printf("\n");
}

#define MAX_N (1000000)

void KMP(char T[], int lenT, char P[], int lenP)
{
    int F[MAX_N+1]={0,};
    int i, j ;
    int k ;
    vector<int> sol ;
    
    for ( i = 1, j = 0 ; i < lenP ; i ++ )
    {
        while ( j > 0 && P[ i ] != P [ j ] )
            j = F[ j - 1 ] ;
            
        if ( P[ i ] == P [ j ] )
            F[ i ] = ++ j;
    }

    for ( i = 0, j = 0  ; i < lenT ;i++)
    {
        // char T[], int offsetT, int posT, char P[], int offsetP, int posP)
        // printf(" i = %d , j = %d\n", i, j);
        // dump(F, T, 0, i, P, i - j , j );
        while ( j > 0 && T[ i ] != P [ j ] )
            j = F[ j - 1 ] ;
        
        if ( T[ i ] == P [ j ] )
        {
            if ( j == lenP - 1 )
            {
                sol.push_back(i - lenP + 1);
                j = F[ j ];
            }
            else
                j++ ;
        }
    }

    printf("%d\n", sol.size());
    for ( i = 0 ; i < sol.size() ; i ++)
        printf("%d ", sol[i] + 1);
}
void process()
{ 
    char T[MAX_N+1], P[MAX_N+1];
    int F[MAX_N+1]={0,};
    int lenT, lenP;
    int i, j, k ;

    lenT = FIO::readLine(T, MAX_N);
    lenP = FIO::readLine(P, MAX_N);

    KMP( T, lenT, P, lenP );
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
    fflush(stdout);
    fflush(stdin);
#else 
#endif 
    return 0; 
} 


