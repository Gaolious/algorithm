#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

struct Reader {
    const char* p;
    Reader(){
        struct stat st; fstat(0, &st);
        p = (const char*) mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    }
} reader;

template <typename T> inline T readInt(){
    int t; T r = 0; bool pos = true;
    r = *(reader.p)++ - 48; if(r < 0) pos = false, r = *(reader.p)++ - 48;
    for(; (t = *(reader.p)++ - 48) >= 0; r = r * 10 + t);
    return pos ? r : -r;
}
template <typename T> inline T readUInt(){
    int t; T r;
    for (r = *(reader.p)++ - 48; (t = *(reader.p)++ - 48) >= 0; r = r * 10 + t);
    return r;
}
inline char readChar(){ return *(reader.p)++; }

void process() {

    char c ;
    int K, P, i ;
    int ret = 0 ;
    for (K=0, P=0, i =0  ; (c = readChar()) > ' ' ; i ++ ) {
        if ( c == 'K' )
        {
            if ( K > 0 ) K--;
            P ++;
        }
        else
        {
            if ( P > 0 ) P --;
            K ++;
        }
        ret = ret > K ? ret : K ;
        ret = ret > P ? ret : P ;
    }
    printf("%d\n", ret);
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


