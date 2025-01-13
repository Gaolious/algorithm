#include <bits/stdc++.h>
using namespace std;

void init(){
}
// (), ~, &, ^, |
struct Solution {
    string S;
    int len;
    bool UsedVariable[26];
    bool Value[26];
    string expr1, expr2;
    int Order(char c) {
        switch (c) {
            case '(' : return 1;
            case ')' : return 1;
            case '~' : return 2;
            case '&' : return 3;
            case '^' : return 4;
            case '|' : return 5;
        }
        return -1;
    }
    bool isVariable(char c) {
        return ('a' <= c && c <= 'z') ;
    }
    bool isValid(char c) {
        if (isVariable(c) || Order(c) > 0) return true;
        return false;
    }
    int parseUnary(int pos, string &out) {
        while (pos < len && !isValid(S[pos])) pos++;
        if ('a' <= S[pos] && S[pos] <= 'z') {
            UsedVariable[ S[pos]-'a' ] = true;
            out.push_back(S[pos]);
            pos = parseBinary(pos + 1, out);
        } else if (S[pos] == '(') {
            out.push_back(S[pos]);
            pos = parseUnary(pos + 1, out);
            if ( S[pos] == ')')
                out.push_back(S[pos]);
            pos = parseBinary(pos+1, out);
        } else if (S[pos] == '~') {
            int cnt;
            for (cnt = 1; pos < len && S[pos + 1] == '~'; pos++, cnt++);
            if (cnt % 2 == 1)
                out.push_back(S[pos]);
            pos = parseUnary(pos + 1, out);
        }
        return pos;
    }
    int parseBinary(int pos, string &out) {
        while (pos < len && !isValid(S[pos])) pos++;
        if (S[pos] == '&' || S[pos] == '^' || S[pos] == '|') {
            out.push_back(S[pos]);
            pos = parseUnary(pos + 1, out);
        }
        return pos;
    }

    bool getResult(string &expr) {
        stack<char> op;
        stack<bool> val;
        int order;
        auto calc = [&op, &val]() {
            bool a, b;
            switch (op.top()) {
                case '~' :
                    a = val.top(); val.pop();
                    val.push(!a);
                break;
                case '&' :
                    a = val.top(); val.pop(); b = val.top(); val.pop();
                    val.push(a && b);
                break;
                case '^' :
                    a = val.top(); val.pop(); b = val.top(); val.pop();
                    val.push(a != b);
                    break;
                case '|' :
                    a = val.top(); val.pop(); b = val.top(); val.pop();
                    val.push(a || b);
                    break;
            }
        };
        for (auto c: expr ) {
            if (isVariable(c) )
                val.push(Value[c-'a']);
            else {
                if ( c == ')' ) {
                    for (; !op.empty() && op.top() != '('; op.pop())
                        calc();
                    op.pop();
                }
                else {
                    for (; !op.empty() && op.top() != '(' && Order(op.top()) <= Order(c); op.pop())
                        calc();
                    op.push(c);
                }
            }
        }
        for ( ; !op.empty() ; op.pop() )
            calc();

        return val.top();
    }
    void dump(string &expr, vector<int> &perm) {
        cout << "Expr : " << expr << " : " << getResult(expr) << '\n';
        for ( auto n: perm)
            cout << "\t var " << (char)('a'+n) << " : " << Value[n] << '\n';
    }
    bool solve() {
        memset(UsedVariable, 0, sizeof(UsedVariable));
        getline(cin, S);
        len = S.size();
        int pos = 0, i, N, j;
        pos = parseUnary(pos, expr1);
        pos = parseUnary(pos, expr2);
//        cout << expr1 << '\t' << expr2 << '\n';

        vector<int> perm;
        for ( i = 0 ; i < 26 ; i ++ )
            if ( UsedVariable[i] )
                perm.push_back(i);

        N = 1 << perm.size();

        for ( i = 0 ; i < N ; i ++ ) {
            for ( j = 0 ; j < perm.size() ; j ++ ) {
                Value[ perm[j] ] = ((1 << j) & i) != 0;
                if ( getResult(expr1) != getResult(expr2) ) {
//                    dump(expr1, perm);
//                    dump(expr2, perm);
                    return false;
                }
            }
        }
        return true;
    }
};


void process(int Case) {
    Solution sol;
    cout << "Data set " << Case << ": ";
    if ( sol.solve() )
        cout << "Equivalent\n";
    else
        cout << "Different\n";

}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
    cin >> T ;
    cin.ignore();
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
