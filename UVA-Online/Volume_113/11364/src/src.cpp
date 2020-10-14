#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

namespace FIO 
{
    const int FD_STDIN = 0;
    const int FD_STDOUT = 1;
    const int FD_STDERR = 2;

    const static int BUFF_SIZE = 1<<21;
    static char buf[BUFF_SIZE];
    static char *p = buf + BUFF_SIZE;
    static int last_read = 0 ;
    inline static bool readByte(char &ret)
    {
        if ( p - buf >= BUFF_SIZE )
        {
            last_read = (int)read(FD_STDIN, (void *)buf, sizeof(buf));
            p = buf ;
        }
        else if ( last_read < BUFF_SIZE )
        {
            if ( (int)( p - buf) >= last_read ) // EOF
                return false;
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

        for ( i = 0 ; i < maxLen && c && c != '\n' ; i ++ )
        {
            str[i] = c ;
            if ( !readByte(c) ) 
                break;
        }
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

#define MAX_N (100)
void process()
{
    int T, l, h, t, v ;
    FIO::readInt(&T);
    while (T--)
    {
        FIO::readInt(&t);
        l = 100, h = 0;
        while (t--)
        {
            FIO::readInt(&v);
            l = min(l,v);
            h = max(h,v);
        }

        printf("%d\n", (h-l)*2);

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
    printf ("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);    
    printf("\n[Press Enter to Continue ...]");
    fflush(stdout);
    fflush(stdin);
#else 
#endif 
    return 0; 
} 


