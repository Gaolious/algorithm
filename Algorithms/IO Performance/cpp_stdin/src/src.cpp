// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

typedef void (*fnCallback)(struct Test *);
typedef char (*fnByteReader)();
typedef int (*fnIntReader)(fnByteReader reader);
typedef void (*fnPreprocess)();
const int MOD = 1e9+7;


const size_t BUFF_SIZE = 1 << 21 ;
char IOBUFF[BUFF_SIZE];
char Buff[BUFF_SIZE];
char *p = Buff + BUFF_SIZE ;
size_t last_read = 0 ;



struct Test 
{
    const char *name ;
    clock_t start_t, end_t ;
    fnPreprocess pre ;
    fnByteReader byte_reader ;
    fnIntReader int_reader ;
    int result ;
    Test(const char *name, fnPreprocess pre, fnByteReader byte_reader, fnIntReader int_reader)
    {
        this->name = name ;
        this->pre = pre ;
        this->byte_reader = byte_reader ;
        this->int_reader = int_reader ;
        this->result = 0;
    }
    void start()
    {}
    void end()
    {}
    void update(int n)
    {
        this->result = ( this->result  + n ) % MOD ;
    }
};

/////////////////////////////////////////////////////////////////////////////
// Generate input data
/////////////////////////////////////////////////////////////////////////////
void generate()
{
    /*
        N ; number of following lines(integers)
        n1 (integer. 0 < n[i] < 2^30 )
        n2 
        n3 
        n4 
        n5 
    */
    int N;
    int i ;
    int t ;

    N = 300000000 ;
    printf("%d\n", N);

    for ( t = 0, i = 0 ; i < N ; i ++ )
    {
        t = t + i * 9973 ;
        printf("%d\n", t % 1007 );
    }
}


/////////////////////////////////////////////////////////////////////////////
// functions to read integer
/////////////////////////////////////////////////////////////////////////////
int read_int_from_byte(fnByteReader reader )
{
    int n = 0 ;
    char c ;
    for ( c = reader() ; c > ' ' ; c = reader() )
        n = n * 10 + c - '0';
    return n ;
}
int read_int_scanf(fnByteReader reader) { 
    int n;
    scanf("%d ", &n);
    return n;
}
int read_int_fscanf(fnByteReader reader) { 
    int n;
    fscanf(stdin, "%d ", &n);
    return n;
}
int read_int_cin(fnByteReader reader) { 
    int n ;
    cin >> n ;
    return n;
}


/////////////////////////////////////////////////////////////////////////////
// functions to read byte
/////////////////////////////////////////////////////////////////////////////
char read_byte_getchar() { return getchar(); }
char read_byte_getc() { return getc(stdin); }
char read_byte_fgetc() { return fgetc(stdin); }
char read_byte_read()
{
    if ( p - Buff >= BUFF_SIZE )
    {
        last_read = read(0, (void *)Buff, sizeof(Buff));
        p = Buff ;
    }
    else if ( last_read < BUFF_SIZE && ( p - Buff ) >= last_read ) 
        return -1;
    return *p++;
}
char read_byte_fread()
{
    if ( p - Buff >= BUFF_SIZE )
    {
        last_read = fread((void *)Buff, sizeof(char), sizeof(Buff), stdin);
        p = Buff ;
    }
    else if ( last_read < BUFF_SIZE && ( p - Buff ) >= last_read ) 
        return -1;
    return *p++;
}
char read_byte_mmap()
{
    return *p++;
}


/////////////////////////////////////////////////////////////////////////////
// functions to pre-process
/////////////////////////////////////////////////////////////////////////////
void pre_mmap()
{
    struct stat rstat;
    fstat(0, &rstat);
    size_t rsize = rstat.st_size;    
    p = (char*)mmap(0, rsize, PROT_READ,MAP_FILE|MAP_PRIVATE, 0, 0);
}
void pre_fread_buff()
{
    setvbuf(stdin, IOBUFF, sizeof(IOBUFF), _IOFBF);
}
void pre_disable_sync_studio()
{
    cin.sync_with_stdio(false);
}
void pre_disable_sync_studio_tie_null()
{
    cin.sync_with_stdio(false);    
    cin.tie(NULL);
}

void pre_tie_null()
{
    cin.tie(NULL);
}

void process(Test *pTester)
{
    int N, n ;
    int i ;
    char c ;

    if ( pTester->pre )
        pTester->pre();

    pTester->start();

    N = pTester->int_reader(pTester->byte_reader) ;

    for ( i = 0 ; i < N ; i ++ )
    {
        n = pTester->int_reader(pTester->byte_reader) ;    
        pTester->update(n);
    }
    pTester->end();
}

int main(int argc, char *argv[]) 
{ 
    int idx ;

    // test for READ INTEGERs
    Test tests[] = {
        Test("scanf"    , NULL, NULL, read_int_scanf ),
        Test("fscanf"   , NULL, NULL, read_int_fscanf),

        Test("getchar"  , NULL , read_byte_getchar, read_int_from_byte),
        Test("getc"     , NULL , read_byte_getc   , read_int_from_byte),
        Test("fgetc"    , NULL , read_byte_fgetc  , read_int_from_byte),

        Test("read"             , NULL          , read_byte_read , read_int_from_byte),
        Test("fread"            , NULL          , read_byte_fread, read_int_from_byte),
        Test("fread_with_setbuf", pre_fread_buff, read_byte_fread, read_int_from_byte),
        Test("mmap"             , pre_mmap      , read_byte_mmap , read_int_from_byte),
        
        Test("cin"                        , NULL                            , NULL, read_int_cin),
        Test("cin_without_sync"           , pre_disable_sync_studio         , NULL, read_int_cin),
        Test("cin_without_sync_tie_null"  , pre_disable_sync_studio_tie_null, NULL, read_int_cin),
        Test("cin_tie_null"               , pre_tie_null                    , NULL, read_int_cin),
    } ;

    if ( argc != 2 )
    {
        printf("missing argumnet\n");
        return -1;
    }
    
    idx = atoi(argv[1]);
    if ( idx < 0 )
    {
        generate();
    }
    else if ( idx > sizeof(tests)/sizeof(tests[0]) )
    {
        printf("out of index\n");
        return -1;
    }
    else 
    {
        process(tests + idx);
        // printf("%s : %d\n", tests[idx].name, tests[idx].result);
    }

    return 0;
}