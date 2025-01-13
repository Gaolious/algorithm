#include <bits/stdc++.h>
using namespace std;

vector<int> Long, Short;
vector<int> sumLong, sumShort;

struct Random {
    mt19937 rd;
    Random() : rd((unsigned)chrono::steady_clock::now().time_since_epoch().count()) {}
    int GetInt(int l = 0, int r = 99999999) {
        return uniform_int_distribution<int>(l, r)(rd);
    }
    double GetDouble(double l = 0, double r = 1) {
        return uniform_real_distribution<double>(l, r)(rd);
    }
} R;
void RandomShuffle(vector<int> &A) {
    int i, N;
    N = A.size();
    for ( i = 0 ; i < N - 1 ; i ++ )
        swap(A[i], A[R.GetInt(i, N-1)]);
}

void simplify() {
    int i;
    std::sort(Long.begin(), Long.end());
    std::sort(Short.begin(), Short.end());

    for ( i = 0 ; i < Long.size() ; i ++ ) {
        sumLong[ i ] = Long[ i ];
        if ( i ) sumLong[ i ] += sumLong[ i - 1 ];
    }

    // 최대 Long 막대기보다 긴 Short은 제외
    for ( i = 0 ; i < Short.size() ; i ++ ) {
        if ( Short[i] > Long.back()) {
            Short.erase(Short.begin()+i);
            sumShort.erase(sumShort.begin()+i);
            break;
        }
    }
    // Long 합산을 초과하는 Short은 제외
    for ( i = 0 ; i < Short.size() ; i ++ ) {
        sumShort[ i ] = Short[ i ] ;
        if ( i ) sumShort[ i ] += sumShort[ i - 1 ];
        if ( sumShort[ i ] > sumLong.back() )  {
            Short.erase(Short.begin()+i);
            sumShort.erase(sumShort.begin()+i);
            break;
        }
    }
}
void process() {
    int N, M, i;
    cin >> N;
    Long.resize(N);
    sumLong.resize(N);
    for (auto &n : Long) cin >> n;

    cin >> M ;
    Short.resize(M);
    sumShort.resize(M);
    for (auto &n : Short) cin >> n;

    simplify();

    for ( i = 0 ; i < 10 ; i ++ )
        cout << SA() << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    process();
    return 0;
}


