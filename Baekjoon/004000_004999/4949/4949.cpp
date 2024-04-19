#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

namespace FIO {
    const static int BUFF_SIZE = 1<<21;
    static char buf[BUFF_SIZE];
    static char *p = buf + BUFF_SIZE;
    static int last_read = 0 ;
    inline static bool readByte(FILE *fp, char &ret)
    {
        if ( p - buf >= BUFF_SIZE )
        {
            last_read = (int)fread(buf, 1, sizeof(buf), fp);
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

    inline bool readInt(FILE *fp, int &ret)
    {
        int n = 0 ;
        int flag = 0 ;
        register char c ;
        if (!readByte(fp, c)) return false;

        while (c <= ' ')
            if ( !readByte(fp, c) ) return false;

        if (c == '-')
        {
            flag = 1;
            if ( !readByte(fp, c) ) return false;
        }

        while ( c > ' ' ) {
            n = n * 10 + c - '0';
            if (!readByte(fp, c) ) break;
        }
        ret = flag ? -n : n;
        return true ;
    }
    inline bool readInt(FILE *fp, int &a, int &b)
    {
        if ( !readInt(fp, a) ) return false ;
        if ( !readInt(fp, b) ) return false ;
        return true ;
    }
    inline bool readInt(FILE *fp, int &a, int &b, int &c)
    {
        if ( !readInt(fp, a, b) ) return false ;
        if ( !readInt(fp, c) ) return false ;
        return true ;
    }
    inline bool readChar(FILE *fp, char &ret)
    {
        register char c;
        if ( !readByte(fp, c) ) return false ;

        while (c <= ' ')
            if (!readByte(fp, c) ) return false ;

        ret = c;
        return true ;
    }

    inline static int readLine(FILE *fp, char *str, int maxLen )
    {
        register char c = 0x00 ;
        int i ;

        while (c <= ' ')
            if ( !readByte(fp, c) ) return false ;

        for ( i = 0 ; i < maxLen && c && c != '\n' ; i ++ )
        {
            str[i] = c ;
            if ( !readByte(fp, c) )
            {
                i++;
                break;
            }
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
    void printStr(char *str)
    {
        for ( char *p = str ; p && *p ; p++)
            printChar(*p);
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

void process(FILE *fp)
{
    char c ;
    bool flag ;

    while ( FIO::readByte(fp, c) )
    {
        vector<char> Q;
        flag = true ;
        if ( c == '.' ) break;
        do
        {
            if ( c == '\n' ) break;
            switch ( c )
            {
                case '(' :
                case '[' :
                    Q.push_back(c);
                    break;
                case ')' :
                    if ( Q.size() == 0 || Q.back() != '(' ) flag = false ;
                    else Q.pop_back();
                    break;
                case ']' :
                    if ( Q.size() == 0 || Q.back() != '[' ) flag = false ;
                    else Q.pop_back();
                    break;
            }
        } while ( FIO::readByte(fp, c) );

        if ( Q.size() != 0 || flag == false )
            printf("no\n");
        else
            printf("yes\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    FILE *fp = freopen("input/input.txt", "rt", stdin );

    clock_t t = clock();
#else
    FILE *fp = stdin ;
#endif

    process(fp);

#ifndef ONLINE_JUDGE
    if (fp) fclose(fp);
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
    printf("\n[Press Enter to Continue ...]");
    fflush(stdout);
    fflush(stdin);
    getchar();
#else
#endif
    return 0;
}

