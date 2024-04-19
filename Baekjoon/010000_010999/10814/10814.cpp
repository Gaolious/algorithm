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
    inline bool readLong(FILE *fp, long long &ret)
    {
        long long n = 0 ;
        int flag = 0 ;
        char c ;
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
    inline bool readInt(FILE *fp, int &ret)
    {
        int n = 0 ;
        int flag = 0 ;
        char c ;
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
        char c;
        if ( !readByte(fp, c) ) return false ;

        while (c <= ' ')
            if (!readByte(fp, c) ) return false ;

        ret = c;
        return true ;
    }

    inline static int readLine(FILE *fp, char *str, int maxLen )
    {
        char c = 0x00 ;
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
    void printLongLong(long long int n)
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
    void printInt(int n)
    {
        printLongLong((long long)n);
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

struct DATA
{
    int age, order;
    char name[100+1];
};
bool cmp(const DATA &a, const DATA &b)
{
    if (a.age != b.age ) return a.age < b.age ;
    return a.order < b.order ;
}
void process(FILE *fp)
{
    int N, i;

    FIO::readInt(fp, N);
    vector<DATA> D(N);

    for (i = 0 ; i < N ; i ++ )
    {
        D[i].order = i;
        FIO::readInt(fp, D[i].age);
        FIO::readLine(fp, D[i].name, sizeof(D[i].name)-1);
    }
    sort( D.begin(), D.end(), cmp);

    for (i = 0 ; i < N ; i ++ )
    {
        FIO::printInt( D[i].age);
        FIO::printChar(' ');
        FIO::printStr(D[i].name);
        FIO::printChar('\n');
    }
    FIO::flush();
}

int main()
{
#ifndef ONLINE_JUDGE
    FILE *fp = fopen("input/input.txt", "rt" );

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
#else
#endif
    return 0;
}
