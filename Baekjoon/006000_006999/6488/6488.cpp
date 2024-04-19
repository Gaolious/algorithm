#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

struct Data {
    int from, mid, to;
    bool operator <(Data &o) {
        if ( to != o.to ) return to > o.to ;
        return from > o.from;
    }
    bool Can(vector<int> &A) {
        return ( A[from] && A[mid] && !A[to]);
    }
    void Move(vector<int> &A) {
        A[from] = A[mid] = 0 ;
        A[to] = 1;
    }
};
vector<Data> P = {
        {31,32,33},
        {25,30,33},
        {24,29,32},
        {33,32,31},
        {23,28,31},
        {28,29,30},
        {18,25,30},
        {17,24,29},
        {30,29,28},
        {16,23,28},
        {25,26,27},
        {13,20,27},
        {24,25,26},
        {12,19,26},
        {33,30,25},
        {27,26,25},
        {23,24,25},
        {11,18,25},
        {32,29,24},
        {26,25,24},
        {22,23,24},
        {10,17,24},
        {31,28,23},
        {25,24,23},
        {21,22,23},
        {9,16,23},
        {24,23,22},
        {8,15,22},
        {23,22,21},
        {7,14,21},
        {18,19,20},
        {17,18,19},
        {30,25,18},
        {20,19,18},
        {16,17,18},
        {6,11,18},
        {29,24,17},
        {19,18,17},
        {15,16,17},
        {5,10,17},
        {28,23,16},
        {18,17,16},
        {14,15,16},
        {4,9,16},
        {17,16,15},
        {16,15,14},
        {27,20,13},
        {11,12,13},
        {26,19,12},
        {10,11,12},
        {25,18,11},
        {13,12,11},
        {9,10,11},
        {3,6,11},
        {24,17,10},
        {12,11,10},
        {8,9,10},
        {2,5,10},
        {23,16,9},
        {11,10,9},
        {7,8,9},
        {1,4,9},
        {22,15,8},
        {10,9,8},
        {21,14,7},
        {9,8,7},
        {18,11,6},
        {4,5,6},
        {17,10,5},
        {16,9,4},
        {6,5,4},
        {11,6,3},
        {1,2,3},
        {10,5,2},
        {9,4,1},
        {3,2,1},
};
bool FindAndMove(vector<int> &A) {
    for (auto &d: P)
        if ( d.Can(A) ) {
            d.Move(A);
            return true;
        }
    return false;
}
void process() {
    int N, n ;
    int i, t;

    cin >> N ;

    for ( t = 0 ; t < N ; t ++ ) {
        vector<int> A(34);
        while ( cin >> n && n ) A[n] = 1;
        while ( FindAndMove(A) );
        int s = 0 ;
        for ( i = 1 ; i <= 33 ; i ++ ) if ( A[i] ) s += i ;
        cout << s << '\n';
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


