#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

const long double eps = 1.0e-9;
#define ROUND( x ) ( round( (x) * 10.0 + eps ) / 10.0 + eps)

struct Data {
    vector<int> Score;
    int bonus{} ;
    int absent{};

    double grade;
    double average ;
    double adjGrade, adjAverage;
    void calcAverage() {
        int sum = 0;
        int i;

        std::sort(Score.begin(), Score.end(), greater<>());
        for (auto n: Score ) sum += n;
        // Rule 1.
        // If he has given more than 2 tests then he will drop the lowest test grade for each student
        // before computing student averages.
        if ( Score.size() > 2 ) {
            sum -= Score.back();
            Score.pop_back();
        }
        // avg
        average = ROUND( (double)sum / Score.size() );
    }
};
double getGrade(double studentAverage, double avg, double std) {
    if ( std < 1 ) std = 1.0;
    // After computing student averages he computes the overall class average (mean) and standard deviation (sd).
    // The cutoff points for grades are:
    //      an average >= one sd above the mean is an A,
    //      an average >= the mean but < one sd above the mean is a B,
    //      an average >= one sd below the mean but < the mean is a C,
    //      and an average < one sd below the mean is a D.

    if ( studentAverage >= std + avg ) return 4.0;
    else if ( studentAverage >= avg ) return 3.0;
    else if ( studentAverage >= avg - std ) return 2.0;
    return 1.0;
}
void getAvgVarStd(vector<double> &A, double &avg, double &var, double &std ) {
    double sum = 0 ;
    for ( auto &a : A) sum += a;

    avg = ROUND( sum / A.size() );
    var = 0 ;
    for ( auto &a : A)
        var += (avg - a) * (avg - a);

    var /= (double)( A.size() );
    var = ROUND(var);
    std = ROUND(sqrt(var));
}
void process() {

    int N, T, S ;
    int i, j, s, t;
    double avg, std, var;

    cin >> N ;

    while ( N -- ) {
        cin >> S >> T;
        vector<Data> A(S);

        for ( s = 0 ; s < S ; s ++ ) {
            A[s].Score.resize(T);
            for (auto &n : A[s].Score ) cin >> n ;
            cin >> A[s].bonus >> A[s].absent;
            A[s].calcAverage();
        }

        vector<double> B(S);
        for ( i = 0 ; i < A.size() ; i ++ ) B[i] = A[i].average;
        getAvgVarStd(B, avg, var, std);

        // absent
        //  For every two bonus points accrued by a student Mr. Chips increases their computed average by 3 percentage points.
        for ( i = 0 ; i < A.size() ; i ++ )
            A[i].adjAverage = ROUND( ( A[i].bonus / 2) * 3 + A[i].average );

        for ( i = 0 ; i < A.size() ; i ++ )
            A[i].grade = getGrade( A[i].adjAverage, avg, std);

        for ( i = 0 ; i < A.size() ; i ++ ) {
            if ( A[i].absent == 0 )
                A[i].adjGrade = min( 4.0, A[i].grade +1 );
            else
                A[i].adjGrade = max( 0.0, A[i].grade - A[i].absent/4 );
        }
#ifdef AJAVA_DEBUG
        cout << "AVG : " << avg << '\n';
        cout << "STD : " << std << '\n';
        cout << "A : " << avg + std << '\n';
        cout << "B : " << avg << '\n';
        cout << "C : " << avg - std << '\n';
#endif
        double S = 0;
        for ( i = 0 ; i < A.size() ; i ++ ) {
            S += A[i].adjGrade;
#ifdef AJAVA_DEBUG

            for (auto t: A[i].Score) cout << setw(3) << t << ' ';
            cout << setw(3) << A[i].bonus << ' ';
            cout << setw(3) << A[i].absent << ' ';
            cout << setw(5) << setprecision(1) << fixed << A[i].average << ' ';
            cout << setw(5) << setprecision(1) << fixed << A[i].adjAverage << ' ';
            cout << setw(5) << setprecision(1) << fixed << A[i].grade << ' ';
            cout << setw(5) << setprecision(1) << fixed << A[i].adjGrade << ' ';
            cout << '\n';
#endif
        }
        S = ROUND(S / A.size());
        cout << setprecision(1) << fixed << S << '\n';
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


