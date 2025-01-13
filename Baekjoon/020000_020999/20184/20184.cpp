#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isYoon(int y) {
    return y % 400 == 0 || ( y % 4 == 0 && y % 100 != 0);
}
int Month[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};

struct DateTime {
    int year{}, month{}, day{}, hour{}, minute{}, second{};
    ll cal= -1 ;
    bool operator < (DateTime &o) {
        return num() < o.num();
    }
    bool operator == (DateTime &o) {
        return num() == o.num();
    }
    bool operator != (DateTime &o) {
        return num() != o.num();
    }
    ll num() {
        auto &ret = cal;
        if ( ret < 0 ) {
            ll days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
            days += Month[month-1] + ( month > 2 && isYoon(year) ) + day - 1;
            ret = ((days * 24 + hour - 1) * 60 + minute - 1) * 60 + second;
        }
        return ret;
    }

    ll operator - (DateTime &o) {
        return num() - o.num();
    }
};
struct USER {
    int rank{};
    ll no{};
    string name;
    ll TotalScore{}, TotalPenalty{};
    ll lastAcceptedSubmitId{};
    ll lastSubmitId{};

    vector<ll> ProblemScore;
    vector<ll> ProblemSubmitCount;
    vector<ll> ProblemTryCount;
    vector<ll> ProblemPenalty1;
    vector<ll> ProblemPenalty2;
    vector<ll> ProblemPenalty;
    vector<bool> ProblemAC;
    vector<bool> ProblemPartialAC;

    bool operator <(USER &o) const {
        return name < o.name;
    }
};
struct PROBLEM {
    ll id{}, order{}, problemScore{}; // 번호, 순서, 배점

    // 일반 문제: 제출 결과는 "성공", "실패" 2가지가 있다.
    // 점수 문제: 제출 결과는 "성공", "부분 성공", "실패" 3가지가 있다. "성공", "부분 성공"의 경우 제출의 점수가 존재한다.
    bool isScoreProblem{}; // 일반 문제 or 점수 문제

    bool operator <(PROBLEM &o) const {
        return order < o.order;
    }
};
struct SUBMIT {
    ll id{}, result{}, score{};
    bool partialResult{};
    DateTime dt;

    bool isCE() const { return result == 11; }
    bool isEmpty() const { return result == 13; }
    bool isAC() const { return result == 4; }
    bool isPartialAC() const { return result == 4 && partialResult; }
    bool operator <(SUBMIT &o) {
        return id < o.id ;
    }
};

struct COMPETITION {
    int nCompetitionPenalty{}; // 대회 패널티(0~100)
    bool isScoreCompetition{}; // 점수대회:1, 일반대회:0
    bool isLastPenalty{}, isExceptCompileError{}, isHMFormat{}; // 마지막 페널티, 컴파일에러 제외, 분으로 보여주는경우 0, 시분으로 보여주는경우 1
    DateTime StartDT;
};

istream &operator >>(istream &in, DateTime &d) {
    char c;
    in >> d.year >> c >> d.month >> c >> d.day >> d.hour >> c >> d.minute >> c >> d.second;
    return in;
}
istream &operator >> (istream &in, COMPETITION &c) {
    in >> c.nCompetitionPenalty >> c.StartDT >> c.isLastPenalty >> c.isExceptCompileError >> c.isScoreCompetition >> c.isHMFormat;
    return in;
}
istream &operator >> (istream &in, PROBLEM &p) {
    in >> p.id >> p.order >> p.problemScore;
    return in;
}

COMPETITION competition;
vector<PROBLEM> ProblemList;
vector<USER> UserList;

void onSubmitScoreCompetition(ll userIndex, ll problemIndex, SUBMIT &submit) {
//    일반 문제: "성공"의 경우 문제의 배점을 모두 획득, "실패"의 경우 0점
//    점수 문제: "성공", "부분 성공"의 경우 제출의 점수를 획득, "실패"의 경우 0점
//    이다. 점수 대회의 경우 0점이 아니면 맞은 문제이다.
    auto &user = UserList[ userIndex ] ;
    auto &problem = ProblemList[ problemIndex ];
    auto &submitCount = user.ProblemSubmitCount[ problemIndex ];
    auto &tryCount = user.ProblemTryCount[ problemIndex ];
    auto &score = user.ProblemScore[problemIndex];
    auto &penalty1 = user.ProblemPenalty1[problemIndex];
    auto &penalty2 = user.ProblemPenalty2[problemIndex];

    user.lastSubmitId = max(user.lastSubmitId, submit.id);
    submitCount ++;

    if (submit.isAC())
        user.lastAcceptedSubmitId = max(user.lastAcceptedSubmitId, submit.id);

    if (problem.isScoreProblem ) {
        assert (score <= problem.problemScore );
        if ( score >= submit.score || submit.score < 1 ) return;

        if ( submit.score == problem.problemScore ) {
            user.ProblemAC[problemIndex] = true;
            user.ProblemPartialAC[problemIndex] = false;
            tryCount = submitCount;
            score = submit.score;
        }
        else if ( submit.score < problem.problemScore ) {
            user.ProblemPartialAC[problemIndex] = false;
            tryCount = submitCount;
            score = submit.score;
        }
        else
            return;

//    페널티 1
//        (좋은 제출 전까지 유저 u가 문제 p에 제출한 횟수) × (대회의 페널티)
//        좋은 제출이 없으면 0
        penalty1 = ( tryCount - 1 ) * competition.nCompetitionPenalty;
//    페널티 2
//        대회 시작부터 좋은 제출이 제출되기까지 쇼요된 시간, 단위는 분
//        좋은 제출이 없으면 0
        penalty2 = ( submit.dt.num() - competition.StartDT.num() ) / 60 ;
    }
    else {
        if ( score >= problem.problemScore ) return;

        if ( submit.isAC() ) {
            user.ProblemAC[problemIndex] = true;
            user.ProblemPartialAC[problemIndex] = false;
            tryCount = submitCount;
            score = problem.problemScore;
        }
        else return;

//    페널티 1
//        (좋은 제출 전까지 유저 u가 문제 p에 제출한 횟수) × (대회의 페널티)
//        좋은 제출이 없으면 0
        penalty1 = ( tryCount - 1 ) * competition.nCompetitionPenalty;
//    페널티 2
//        대회 시작부터 좋은 제출이 제출되기까지 쇼요된 시간, 단위는 분
//        좋은 제출이 없으면 0
        penalty2 = ( submit.dt.num() - competition.StartDT.num() ) / 60 ;
    }
}

void onSubmitNormalCompetition(ll userIndex, ll problemIndex, SUBMIT &submit) {
//    일반 대회의 경우
//
//    일반 문제: "성공"만 맞은 문제
//    점수 문제: "성공"만 맞은 문제
    auto &user = UserList[ userIndex ] ;
    auto &problem = ProblemList[ problemIndex ];
    auto &submitCount = user.ProblemSubmitCount[ problemIndex ];
    auto &tryCount = user.ProblemTryCount[ problemIndex ];
    auto &score = user.ProblemScore[problemIndex];
    auto &penalty1 = user.ProblemPenalty1[problemIndex];
    auto &penalty2 = user.ProblemPenalty2[problemIndex];

    user.lastSubmitId = max(user.lastSubmitId, submit.id);
    submitCount ++;

    if (submit.isAC())
        user.lastAcceptedSubmitId = max(user.lastAcceptedSubmitId, submit.id);

    if ( score != 0 ) return;

    if ( submit.isAC() ) {
        user.ProblemAC[problemIndex] = true;
        user.ProblemPartialAC[problemIndex] = false;
        tryCount = submitCount;
        score = 1;
//        페널티 1
//            (좋은 제출 전까지 유저 u가 문제 p에 제출한 횟수) × (대회의 페널티)
//            좋은 제출이 없으면 0
        penalty1 = ( tryCount - 1 ) * competition.nCompetitionPenalty;
//        페널티 2
//            대회 시작부터 좋은 제출이 제출되기까지 쇼요된 시간, 단위는 분
//            좋은 제출이 없으면 0
        penalty2 = ( submit.dt.num() - competition.StartDT.num() ) / 60 ;
    }

//    일반 대회: 맞은 적이 있으면, 제출 번호가 가장 작은 제출이 좋은 제출이다.  (???)

}

void updateUserScoreWithLastPenalty(ll userIndex) {
//    유저 u의 페널티는 대회의 "마지막 페널티" 값에 따라서 다르게 계산한다.
//        마지막 페널티를 사용한 경우: (각 문제의 "페널티 2" 중에서 최댓값) + (모든 문제의 "페널티 1"의 합)
    auto &user = UserList[ userIndex ] ;

    user.TotalPenalty = *max_element(user.ProblemPenalty2.begin(), user.ProblemPenalty2.end());
    user.TotalScore = 0 ;
    for ( int i = 0 ; i < ProblemList.size() ; i ++ ) {
        user.ProblemPenalty[i] = user.ProblemPenalty2[i];
        user.TotalPenalty += user.ProblemPenalty1[i];
        user.TotalScore += user.ProblemScore[i];
    }
}

void updateUserScore(ll userIndex) {
//    유저 u의 페널티는 대회의 "마지막 페널티" 값에 따라서 다르게 계산한다.
//        마지막 페널티를 사용하지 않는 경우 유저 u가 각 문제에서 획득한 모든 페널티를 합한다.
    auto &user = UserList[ userIndex ] ;

    user.TotalPenalty = 0 ;
    user.TotalScore = 0 ;
    for ( int i = 0 ; i < ProblemList.size() ; i ++ ) {
        user.ProblemPenalty[i] = user.ProblemPenalty1[i] + user.ProblemPenalty2[i];
        user.TotalPenalty += user.ProblemPenalty1[i] + user.ProblemPenalty2[i];
        user.TotalScore += user.ProblemScore[i];
    }
}
string HMFormat(ll penalty) {
    stringstream ss;
    if ( competition.isHMFormat )
        ss << penalty / 60 << ":" << setw(2) << setfill('0') << penalty%60 ;
    else
        ss << penalty ;
    return ss.str();
}
void dumpUserNormalCompetition(int userIndex){
    // 맞은 경우: "a/시도한 횟수/획득한 페널티"
    //시도를 한 적은 있으나 맞지 못한 경우: "w/시도한 횟수/--"
    //시도를 한 적이 없는 경우: "0/--"
    auto &user = UserList[ userIndex ] ;

    cout << user.rank << "," ;
    cout << user.name << ",";

    for ( int i = 0 ; i < ProblemList.size() ; i ++ ) {
        if ( user.ProblemAC[ i ] ) {
            cout << "a/" << user.ProblemTryCount[i] << "/" << HMFormat(user.ProblemPenalty[i]) << ',';
        }
        else if ( user.ProblemSubmitCount[i] > 0 ) {
            cout << "w/" << user.ProblemSubmitCount[i] << "/--,";
        }
        else {
            cout << "0/--,";
        }
    }
    cout << user.TotalScore << "/" << HMFormat(user.TotalPenalty) << '\n';
}
void dumpUserScoreCompetition(int userIndex){
    // 맞은 경우: "성공 여부/좋은 제출의 점수/시도한 횟수/획득한 페널티"
    //성공 여부는 좋은 제출의 점수가 문제의 배점이 같으면 a, 아니면 p이다.
    //시도를 한 적은 있으나 좋은 제출이 없는 경우: "w/시도한 횟수/--"
    //시도를 한 적이 없는 경우: "0/--"
    auto &user = UserList[ userIndex ] ;

    cout << user.rank << "," << user.name << ",";

    for ( int i = 0 ; i < ProblemList.size() ; i ++ ) {
        if ( user.ProblemScore[i] == ProblemList[i].problemScore ) {
            cout << "a/" << user.ProblemScore[i] << "/" << user.ProblemTryCount[i] << "/" << HMFormat(user.ProblemPenalty[i]) << ',';
        }
        else if ( user.ProblemScore[i] > 0 ) {
            cout << "p/" << user.ProblemScore[i] << "/" << user.ProblemTryCount[i] << "/" << HMFormat(user.ProblemPenalty[i]) << ',';
        }
        else if ( user.ProblemSubmitCount[i] > 0 ) {
            cout << "w/" << user.ProblemSubmitCount[i] << "/--,";
        }
        else {
            cout << "0/--,";
        }
    }
    cout << user.TotalScore << "/" << HMFormat(user.TotalPenalty) << '\n';

}
void process() {
    int N, i;
    unordered_map<ll, ll> ProblemIndexMapping;
    unordered_map<string, ll> UserIndexMapping;
    unordered_map<ll, unordered_map<ll, vector<SUBMIT>>> SubmitList;

    cin >> competition;

    cin >> N ;
    ProblemList.resize(N);
    for ( i = 0 ; i < N ; i ++ ) cin >> ProblemList[ i ];
    std::sort(ProblemList.begin(), ProblemList.end());
    for ( i = 0 ; i < N ; i ++ ) ProblemIndexMapping[ ProblemList[i].id ] = i;

    cin >> N ;
    UserList.resize(N);
    for ( i = 0 ; i < N ; i ++ ) {
        auto &user = UserList[i];
        cin >> user.name ;
        user.ProblemScore.resize(ProblemList.size());
        user.ProblemSubmitCount.resize(ProblemList.size());
        user.ProblemTryCount.resize(ProblemList.size());
        user.ProblemPenalty1.resize(ProblemList.size());
        user.ProblemPenalty2.resize(ProblemList.size());
        user.ProblemAC.resize(ProblemList.size());
        user.ProblemPartialAC.resize(ProblemList.size());
        user.ProblemPenalty.resize(ProblemList.size());
    }
    std::sort(UserList.begin(), UserList.end());
    for ( i = 0 ; i < N ; i ++ ) UserIndexMapping[ UserList[i].name ] = i;

    cin >> N;
    while ( N -- ) {
        SUBMIT submit;
        ll problemId;
        string name;
        cin >> submit.id >> problemId >> name >> submit.result >> submit.partialResult >> submit.score >> submit.dt ;

        if ( competition.isExceptCompileError && submit.isCE() )  continue;
        if ( submit.isEmpty() ) continue;

        if ( ProblemIndexMapping.count(problemId) == 0 ) continue;
        if ( UserIndexMapping.count(name) == 0 ) continue;

        auto problemIndex = ProblemIndexMapping[problemId];
        auto userIndex = UserIndexMapping[name];

        ProblemList[problemIndex].isScoreProblem |= submit.score > 0 ;
        SubmitList[userIndex][problemIndex].push_back(submit);
    }
    for (auto &[userIndex, submit_mapping]: SubmitList) {
        for (auto &[problemIndex, submit_list]: submit_mapping) {
            for (auto &submit : submit_list ) {
                if ( competition.isScoreCompetition )
                    onSubmitScoreCompetition(userIndex, problemIndex, submit);
                else
                    onSubmitNormalCompetition(userIndex, problemIndex, submit);
            }
        }
    }

    if ( competition.isLastPenalty ) {
        for ( i = 0 ; i < UserList.size() ; i ++ )
            updateUserScoreWithLastPenalty(i);
    }
    else {
        for ( i = 0 ; i < UserList.size() ; i ++ )
            updateUserScore(i);
    }


    vector<int> userIndex(UserList.size());
    for ( i = 0 ; i < UserList.size() ; i ++ )
        userIndex [ i ] = i ;
    std::sort(UserList.begin(), UserList.end(), [](USER &a, USER &b) {
        // 획득한 점수가 높은 순
        //페널티가 적은 순
        //마지막으로 맞은 제출 번호가 작은 순
        //마지막으로 제출한 제출 번호가 작은 순
        //유저의 아이디가 사전 순으로 앞서는 순
        if ( a.TotalScore != b.TotalScore ) return a.TotalScore > b.TotalScore ;
        if ( a.TotalPenalty != b.TotalPenalty ) return a.TotalPenalty < b.TotalPenalty ;
        if (a.lastAcceptedSubmitId != b.lastAcceptedSubmitId )
            return a.lastAcceptedSubmitId < b.lastAcceptedSubmitId ;
        if ( a.lastSubmitId != b.lastSubmitId ) return a.lastSubmitId < b.lastSubmitId ;
        return a.name < b.name;
    });
    for ( i = 0 ; i < UserList.size() ; i ++ ) {
        UserList[ userIndex[i] ].rank = i + 1 ;
        if ( i > 0 ) {
            if ( UserList[ userIndex[i] ].TotalScore != UserList[ userIndex[i-1] ].TotalScore ) continue;
            if ( UserList[ userIndex[i] ].TotalPenalty != UserList[ userIndex[i-1] ].TotalPenalty ) continue;

            UserList[ userIndex[i] ].rank = UserList[ userIndex[i-1] ].rank ;
        }
    }

    if ( competition.isScoreCompetition ) {
        for ( i = 0 ; i < UserList.size() ; i ++ )
            dumpUserScoreCompetition(userIndex[i]);
    }
    else {
        for ( i = 0 ; i < UserList.size() ; i ++ )
            dumpUserNormalCompetition(userIndex[i]);
    }
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    process();
    return 0;
}
/*
let score = [];
$('div.team').each(function(idx, o) {
    let name =$(o).find('div.team-name a.team-name-link').text().trim();
    let sol = $(o).find('h2.total-solved').text().trim();
    let pen = $(o).find('small.total-penalty').text().trim();
    if (sol.length < 1 ) sol = '0';
    if (pen.length < 1 ) pen = '0';
    score.push( name + ',' + sol + '/' + pen);
});
console.log(score.join('\n'));
 * */