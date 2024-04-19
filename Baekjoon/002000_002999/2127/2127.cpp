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

vector<string> getInput() {
    string s ;
    string t;

    getline(cin, s);
    stringstream ss(s);
    vector<string> token;
    while( getline(ss, t, ',') ) {
        token.push_back(t);
    }
    return token;
}
ll StringToMoney(string &s) {
    ll ret = 0 ;
    for (auto c: s) {
        if ( '0' <= c && c <= '9' ) {
            ret = ret * 10 + (c-'0');
        }
    }
    return ret;
}
struct PersonInfo {
    string name;
    // 나머지 필드는 금액으로, 왼쪽에서 오른쪽으로 고객의 IAT 최대 지시 한도, IAT 일일 노출 한도, 일반 결제 최대 지시 한도, 일반 결제 일일 노출 한도입니다.
    ll IATLimit;
    ll IATDailyLimit;
    ll generalPaymentLimit;
    ll generalPaymentDailyLimit;
    void update(vector<string> &data ){
        name = data[1];
        IATLimit = StringToMoney(data[2]);
        IATDailyLimit = StringToMoney(data[3]);
        generalPaymentLimit = StringToMoney(data[4]);
        generalPaymentDailyLimit = StringToMoney(data[5]);
    }

    unordered_map<string, ll> cumDailyIAT;
    unordered_map<string, ll> cumDailyGeneralPayment;
    bool canDailyIAT(string key, ll money) {
        if (getDailyIAT(key) + money > IATDailyLimit) return false;
        return true;
    }
    bool canDailyGeneralPayment(string key, ll money) {
        if (getDailyGeneralPayment(key) + money > generalPaymentDailyLimit) return false;
        return true;
    }
    ll getDailyIAT(string key) {
        if (cumDailyIAT.find(key) == cumDailyIAT.end() )
            return 0;
        return cumDailyIAT[key];
    }
    ll getDailyGeneralPayment(string key) {
        if (cumDailyGeneralPayment.find(key) == cumDailyGeneralPayment.end() )
            return 0;
        return cumDailyGeneralPayment[key];
    }
};
struct Account {
    string ownerName;
    string accountNo;
    void update(vector<string> &data ){
        ownerName = data[1];
        accountNo = data[2];
    }
};
struct Instruction {
    string ymd;
    string srcUserName, srcAccountNo;
    ll price;
    string targetAccountNo;
    void update(vector<string> &data ){
        ymd = data[1].substr(0,8);
        srcUserName = data[2];
        srcAccountNo = data[3];
        price = StringToMoney(data[4]);
        targetAccountNo = data[5];
    }
};
void process() {
    vector<PersonInfo> personList;
    vector<Account> accountList;
    vector<Instruction> instructionList;
    while (true) {
        auto t= getInput();
        if (t.empty() ) break;
        if ( t[0] == "1" ) personList.emplace_back().update(t);
        else if ( t[0] == "2" ) accountList.emplace_back().update(t);
        else if ( t[0] == "5" ) instructionList.emplace_back().update(t);
        else if ( t[0] == "9" )
            break;
    }
    unordered_map<string, int> byAccountNo, byName;
    for ( int i = 0 ; i < personList.size() ; i ++ )
        byName[ personList[i].name ] = i;
    for ( int i = 0 ; i < accountList.size() ; i ++ )
        byAccountNo[ accountList[i].accountNo ] = byName[ accountList[i].ownerName ];

    int n;
    for ( n = 1 ; n <= instructionList.size() ; n ++ ) {
        auto &inst = instructionList[n-1];

        auto srcAccountIndex = byAccountNo[ inst.srcAccountNo ];
        auto srcNameIndex = byName[ inst.srcUserName ];
        auto destIndex = byAccountNo[ inst.targetAccountNo ];
        string result ;
        bool possibleTotal = true, possibleDaily = true;

        if ( srcAccountIndex != srcNameIndex ) {
            result = "NOT OWNER";
        }
        else if ( srcAccountIndex == destIndex ) { // IAT
            // check daily
            if ( !personList[ srcAccountIndex ].canDailyIAT(inst.ymd, inst.price))
                possibleDaily = false;

            if ( inst.price > personList[ srcAccountIndex ].IATLimit )
                possibleTotal = false;

//            if ( !possibleDaily && !possibleTotal )
//                result = ". . . MAX EXCEEDED";
            if ( !possibleTotal )
                result = "IAT MAX EXCEEDED";
            else if ( !possibleDaily)
                result = "IAT DEL EXCEEDED";
            else {
                result = "IAT OK";
                personList[ srcAccountIndex ].cumDailyIAT[ inst.ymd ] += inst.price;
            }
        }
        else { // general
            if ( !personList[ srcAccountIndex ].canDailyGeneralPayment(inst.ymd, inst.price) )
                possibleDaily = false;

            if ( inst.price > personList[ srcAccountIndex ].generalPaymentLimit )
                possibleTotal = false;

//            if ( !possibleDaily && !possibleTotal )
//                result = ". . . MAX EXCEEDED";
            if ( !possibleTotal )
                result = "PAYMENT MAX EXCEEDED";
            else if ( !possibleDaily)
                result = "PAYMENT DEL EXCEEDED";
            else {
                result = "PAYMENT OK";
                personList[ srcAccountIndex ].cumDailyGeneralPayment[ inst.ymd ] += inst.price;
            }
        }

        cout << "INSTRUCTION " << n << ": " << result << '\n';

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


