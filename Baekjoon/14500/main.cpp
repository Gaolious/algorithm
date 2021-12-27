#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <stdlib.h>

using namespace std;

class FIO
{
    #define BUFF_LEN (1<<22)
    char *p;
    char out[BUFF_LEN]{};
    int nOut ;
public :
    FIO()
    {
        struct stat rstat{};
        this->p = nullptr ;

        if ( fstat(0, &rstat) == 0 && rstat.st_size > 0 )
            this->p = (char*)mmap(nullptr, rstat.st_size, PROT_READ, MAP_SHARED, 0, 0) ;

        if ( this->p == MAP_FAILED ) this->p = nullptr ;
        nOut = 0;
    }
    ~FIO() {
        this->write_flush();
    }
    void skip() { while ( this->p && *this->p && *this->p <= ' ' ) this->p++; }
    bool Char(char &c)  { if ( !this->p || *this->p <= 0 ) return false ; c = *this->p++; return true ; }
    bool Line(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();

        for ( len = 0 ; this->Char(c) && c > 0 && c != '\n' && len < maxLen ; len++ )
            *s++ = c ;
        *s = 0x00;
        return c || len > 0;
    }
    bool Word(char *s, int &len, const int maxLen)
    {
        char c = 0 ;
        this->skip();

        for ( len = 0 ; this->Char(c) && c > 0 && c > ' ' && len < maxLen ; len++ )
            *s++ = c ;
        *s = 0x00;
        return c || len > 0;
    }
    template<typename T> bool Int(T &n)
    {
        char c ;
        bool flag = true ;
        n = 0 ;
        this->skip();
        if ( ! this->Char(c) )  return false ;
        if ( c == '-' )
        {
            flag = false;
            if ( ! this->Char(c) ) return false ;
        }

        while ( c > ' ' )
        {
            n = n * 10 + c - 48 ;
            if ( ! this->Char(c) ) break;
        }
        if ( !flag ) n = -n;
        return true ;
    }
    template<typename T> bool Int(T &a, T &b) { return this->Int(a) && this->Int(b); }
    template<typename T> bool Int(T &a, T &b, T &c) { return this->Int(a, b) && this->Int(c); }
    template<typename T> bool Int(T &a, T &b, T &c, T &d) { return this->Int(a, b) && this->Int(c, d); }

    void write_flush(){
        if ( this->nOut > 0 ) fwrite(this->out, 1, this->nOut, stdout);
        this->nOut = 0;
    }
    void write_Char(char c) { if ( this->nOut >= BUFF_LEN ) this->write_flush(); this->out[ this->nOut ++ ] = c ; }
    void write_CharLn(char c) { this->write_Char(c); this->write_Char('\n'); }
    void write_Str(char *c) { while ( c && *c) this->write_Char(*c++); }
    void write_Str(const char *c) { while ( c && *c) this->write_Char(*c++); }
    template<typename T> void write_Int(T a)
    {
        if ( a < 0 )
        {
            this->write_Char('-');
            a *= -1;
        }
        else if ( a == 0 )
            this->write_Char('0');
        char buff[30];
        int nBuff = 0;
        for ( int i = 0 ; a > 0; a /= 10 )
            buff[nBuff++] = '0' + (a%10);
        while ( nBuff > 0 )
            write_Char(buff[--nBuff]);
    }
    template<typename T> void write_IntLn(T a)
    {
        write_Int(a);
        write_Char('\n');
    }
};

struct POINT {
    int dy, dx;
    bool operator == (POINT o) const {
        return (this->dy == o.dy && this->dx == o.dx );
    }
    bool operator <(POINT o) const {
        return this->dy == o.dy ? this->dx < o.dx : this->dy < o.dy;
    }
};
struct SHAPE {
    POINT p[4];
    int minx, maxx;
    int miny, maxy;
};
vector<SHAPE> Shapes;
const int MaxShapeSize = 4 ;

void clone_shape(SHAPE *src, SHAPE *dest) {
    memcpy(dest, src, sizeof(SHAPE));
}
void simply(SHAPE *src) {
    int i ;
    sort(src->p+0, src->p+4);
    for ( i = 0 ; i < 4 ; i ++ ) {
        src->p[i].dx -= src->minx ;
        src->p[i].dy -= src->miny ;
    }
    src->maxx -= src->minx ;
    src->minx -= src->minx ;
    src->maxy -= src->miny ;
    src->miny -= src->miny ;
}

void rotate(SHAPE *src) {
    int i ;
    POINT t;
    int minx, maxx, miny,maxy ;
    minx = miny = MaxShapeSize ;
    maxx = maxy = -1 ;

    for ( i = 0 ; i < 4 ; i ++ ) {
        t = src->p[i];
        src->p[i].dy = t.dx ;
        src->p[i].dx = (MaxShapeSize-1) - t.dy;
        minx = min(minx, src->p[i].dx);
        miny = min(miny, src->p[i].dy);
        maxx = max(maxx, src->p[i].dx);
        maxy = max(maxy, src->p[i].dy);
    }
    src->minx = minx ;
    src->maxx = maxx ;
    src->miny = miny ;
    src->maxy = maxy ;
    simply(src);
}

void mirrorX(SHAPE *src) {
    int i ;
    int minx, maxx, miny,maxy ;
    minx = miny = MaxShapeSize ;
    maxx = maxy = -1 ;

    for ( i = 0 ; i < 4 ; i ++ ) {
        src->p[i].dx = ( MaxShapeSize - 1 ) - src->p[i].dx;
        minx = min(minx, src->p[i].dx);
        miny = min(miny, src->p[i].dy);
        maxx = max(maxx, src->p[i].dx);
        maxy = max(maxy, src->p[i].dy);
    }
    src->minx = minx ;
    src->maxx = maxx ;
    src->miny = miny ;
    src->maxy = maxy ;
    simply(src);
}

void mirrorY(SHAPE *src) {
    int i ;
    int minx, maxx, miny,maxy ;
    minx = miny = MaxShapeSize ;
    maxx = maxy = -1 ;

    for ( i = 0 ; i < 4 ; i ++ ) {
        src->p[i].dy = ( MaxShapeSize - 1 ) - src->p[i].dy;
        minx = min(minx, src->p[i].dx);
        miny = min(miny, src->p[i].dy);
        maxx = max(maxx, src->p[i].dx);
        maxy = max(maxy, src->p[i].dy);
    }
    src->minx = minx ;
    src->maxx = maxx ;
    src->miny = miny ;
    src->maxy = maxy ;
    simply(src);
}

void add_tetromino(SHAPE *shape) {
    SHAPE shape_list[20];
    int shape_count = 0;

    SHAPE origin, target, mirror;
    int i, j ;
    sort(shape->p+0, shape->p+4);
    clone_shape(shape, &origin);

    for ( i = 0 ; i < 4 ; i ++ ) {
        clone_shape(&origin, &target);
        // 1
        shape_list[ shape_count++ ] = target;
        // 2
        clone_shape(&target, &mirror);
        mirrorX(&mirror);
        shape_list[ shape_count++ ] = mirror;
        // 3
        mirrorY(&mirror);
        shape_list[ shape_count++ ] = mirror;

        // 4
        clone_shape(&target, &mirror);
        mirrorY(&mirror);
        shape_list[ shape_count++ ] = mirror;
        // 5
        mirrorX(&mirror);
        shape_list[ shape_count++ ] = mirror;

        rotate(&origin);
    }
    for ( i = 0 ; i < shape_count ; i ++ ){
        bool find = false ;
        for ( auto s : Shapes) {
            bool is_equal = true ;
            for ( j = 0 ; j < 4 ; j ++ ) {
                if (s.p[j].dx != shape_list[i].p[j].dx || s.p[j].dy != shape_list[i].p[j].dy) {
                    is_equal = false;
                    break ;
                }
            }
            if (is_equal) {
                find = true ;
                break;
            }
        }
        if (!find) {
            Shapes.push_back(shape_list[i]);
        }
    }
}

void dump(SHAPE *shape) {
    int i, j ;
    int A[4][4]={0,};
    for ( i = 0 ; i < 4 ; i ++ ) {
        A[ shape->p[i].dy ][ shape->p[i].dx ] = 1 ;
    }

    printf("Shape (%d,%d) - (%d,%d)\n", shape->miny, shape->minx, shape->maxy, shape->maxx);
    for ( i = 0 ; i < 4 ; i ++ ) {
        for ( j = 0 ; j < 4 ; j ++ ) {
            printf("%c ", ( A[i][j] == 1 ) ? '*' : '.' );
        }
        printf("\n");
    }

}

int A[500][500]={0,};
void process() {
    FIO fio;
    int N, M ;
    int i, j, k, ret, s;
    SHAPE init[5] = {
            {{{0,0}, {0,1}, {0,2}, {0,3} }, 0, 3, 0, 0 },
            {{{0,0}, {0,1}, {1,1}, {1,0} }, 0, 1, 0, 1 },
            {{{0,0}, {1,0}, {2,0}, {2,1} }, 0, 1, 0, 2 },
            {{{0,0}, {1,0}, {1,1}, {2,1} }, 0, 1, 0, 2 },
            {{{0,0}, {0,1}, {0,2}, {1,1} }, 0, 2, 0, 1 },
    };
    for ( auto s: init) {
        add_tetromino(&s);
    }
//
//    for (auto s: Shapes) {
//        dump( &s);
//    }
    fio.Int(N, M);
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < M ; j ++ ) {
            fio.Int(A[i][j]);
        }
    }

    ret = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        for (j = 0; j < M; j++) {
            for (auto shape: Shapes) {
                if (shape.maxx + j < M && shape.maxy + i < N )
                {
                    for ( s = 0, k = 0 ; k < 4 ; k ++ )
                        s += A[ i + shape.p[k].dy ][ j + shape.p[k].dx ] ;
                    ret = max(ret, s);
                }
            }
        }
    }
    fio.write_IntLn(ret);
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


