#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
vector<pair<int,int>> A;

void print(vector<int> &P, int idx)
{
    if ( P[idx] >= 0 )
        print(P, P[idx]);
    cout << A[idx].second << ',';
}

void process() {
    fastio;
    int N, a, b, i ;
    int idx;

    cin >> N ;
    vector<int> Seq;
    vector<int> SeqIdx;
    vector<int> P(N);

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> a >> b ;
        A.emplace_back(a, b) ;
    }
    // 가장 긴 증가하는 부분 수열:
    std::sort(A.begin(), A.end());
    for ( i = 0 ; i < N ; i ++ ) {
        a = A[i].second;

        idx = lower_bound(Seq.begin(), Seq.end(), a) - Seq.begin() ;

        if (idx < Seq.size() )
        {
            Seq[idx] = a ;
            SeqIdx[idx] = i;
        }
        else
        {
            Seq.push_back(a);
            SeqIdx.push_back(i);
        }
        P[i] = idx == 0 ? -1 : SeqIdx[idx - 1];
    }
    vector<bool> flag(500'000+1);
    for ( i = SeqIdx.back() ; i >= 0 ; i = P[i] )
        flag[ A[i].first ] = true;

    cout << N - Seq.size() << '\n';
    for ( i = 0 ; i < N ; i ++ )
        if ( !flag[ A[i].first ])
            cout << A[i].first << '\n';
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


