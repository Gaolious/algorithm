#include <string>
#include <vector>
#include <queue>

typedef struct _ {
    int num, cnt ;
} DATA;
std::vector<DATA> Q;


using namespace std;
const int MaxN = 1000000;
int D[MaxN];
int solution(int N, int number) {


    int i, j, t ;
    int answer = 0;

    for ( i = 0 ; i < MaxN ; i ++ )
        D[i] = 10;

    for ( t=N, i=1; i<=6 ; i ++, t=t*10+N )
    {
        Q.push_back( DATA{t, i});
        D[t] = i;
    }

    DATA d = OP(+, 1, 1);
    return D[number] > 8 ? -1 : D[number];
}

int main()
{

#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

//    process();
    printf("%d\n", solution(1, 1121));

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


