#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

namespace FIO {
    const static int BUFF_SIZE = 1<<19;
    static char buf[BUFF_SIZE];
    static char *p = buf + BUFF_SIZE;
    static int last_read = 0 ;
#define RF if (!readByte(c)) return false;
#define RB if (!readByte(c)) break;
#define SK while (c <= ' ') RF
    inline bool readByte(char &ret)
    {
        if ( p - buf >= BUFF_SIZE )
        {
            last_read = (int)fread(buf, 1, sizeof(buf), stdin);
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
    inline bool readLong(long long &ret)
    {
        long long n = 0 ;
        int flag = 0 ;
        char c = 0;
        SK
        
        if (c == '-') 
        {
            flag = 1; RF
        }

        while ( c > ' ' ) {
            n = n * 10 + c - '0'; RB
        }
        ret = flag ? -n : n;
        return true ;
    }
    inline bool readInt(int &ret)
    {
        long long n ;
        if ( !readLong(n ) ) return false ;
        ret = (int)n;
        return true ;
    }
    inline bool readInt(unsigned int &ret)
    {
        long long n ;
        if ( !readLong(n ) ) return false ;
        ret = (unsigned int)n;
        return true ;
    }
    inline bool readInt(int &a, int &b)
    {
        return readInt(a) && readInt(b);
    }
    inline bool readInt(int &a, int &b, int &c)
    {
        return readInt(a, b) && readInt(c);
    }
    inline bool readChar(char &c)
    {
        c=0; SK; return true ;
    }
    inline int readWord(char str[], int maxLen )
    {
        char c = 0x00 ;
        int i ;
        SK
        for ( i = 0 ; i < maxLen && c > ' ' ; i ++ )
        {
            str[i] = c ;
            if ( !readByte(c) ) 
            {
                i++;
                break;
            }
        }
        str[ i ] = 0x00 ;
        return i;
    }
    inline int readLine(char *str, int maxLen )
    {
        char c = 0x00 ;
        int i ;
        SK
        for ( i = 0 ; i < maxLen && c && c != '\n' ; i ++ )
        {
            str[i] = c ;
            if ( !readByte(c) ) 
            {
                i++;
                break;
            }
        }
        str[ i ] = 0x00 ;
        return i;
    }

    char outbuf[BUFF_SIZE+10];
    char* outp = outbuf;
    inline void printLongLong(long long int n)
    {
        unsigned long long int nn;
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
    inline void printInt(int n)
    {
        printLongLong((long long)n);
    }

    inline void printChar(char c)
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
    inline void printStr(char *s)
    {
        while ( s && *s ) printChar(*s++);
    }
    inline void flush()
    {
        syscall(0x01, 1, outbuf, outp - outbuf);
    }    
#undef RF
#undef RB
#undef SK
}


#define ADD(a, b) ( (a) |= (0x01 << ((b)-1) ))
#define REMOVE(a, b) ( (a) &= ~(0x01 << ((b)-1) ))
#define CHECK(a, b) ( (a) & (0x01 << ((b)-1) ))
#define TOGGLE(a, b) ( (a) ^= (0x01 << ((b)-1) ))
#define ALL(a,b) ( (a) = 0xfffff)
#define EMPTY(a,b) ( (a) = 0x00 )

void process()
{
    unsigned int a = 0, b = 0;
    char command[20]={0,};
    int len ;
    int N;
    FIO::readInt(N);
    
    EMPTY(a,b);

    while (N--)
    {
        len = FIO::readWord(command, 20);
        if ( command[0] == 'a')
        {
            if ( command[1] == 'd' ) FIO::readInt(b), ADD(a, b);
            else if ( command[1] == 'l' ) ALL(a, b);
        } 
        else if ( command[0] == 'r' ) FIO::readInt(b), REMOVE(a,b);
        else if ( command[0] == 'c' ) 
        {
            FIO::readInt(b);
            if ( CHECK(a,b) ) FIO::printStr("1\n");
            else FIO::printStr("0\n");
        }
        else if ( command[0] == 't' ) FIO::readInt(b), TOGGLE(a,b);
        else if ( command[0] == 'e' ) EMPTY(a,b);
    }

    FIO::flush();
}

int main() 
{ 
    process(); 
    return 0;
} 

