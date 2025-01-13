#include <bits/stdc++.h>
using namespace std;

enum STATEMENT_TYPE {IF, WHILE, SET, PRINT};
enum EXPR_TYPE {NUMBER, VARIABLE, OPERATOR};

struct Expr
{
	EXPR_TYPE type;
	int num{};
	string op;
	Expr(EXPR_TYPE type, int n) : type(type), num(n) {}
	Expr(EXPR_TYPE type, string o) : type(type), op(o) {}
	void dump()
	{
		if ( type == NUMBER ) cout << "NUM(" << num << ")";
		else if ( type == VARIABLE ) cout << "VAR(" << (char)(num+'a') << ")" ;
		else if ( type == OPERATOR ) cout << "OP(" << op << ")";
		cout << " / ";
	}
};

struct Statement
{
	STATEMENT_TYPE type ;
	int varIndex{}; // set
	vector<Expr> expression ; // if, while, set, print
	vector<Statement> true_statements; // if, while
	vector<Statement> false_statements; // else
	Statement (STATEMENT_TYPE t) : type(t) {}

	void dump(int depth = 0)
	{
		string padding = string(depth*4, ' ');
		if ( type == IF )
		{
			cout << padding << "Statement : IF ";
			for ( auto &e: expression ) e.dump();
			cout << '\n' << padding << "if true? \n";
			for (auto &t: true_statements ) t.dump(depth+1);
			cout << '\n' << padding << "else \n";
			for (auto &t: false_statements ) t.dump(depth+1);
		}
		else if ( type == WHILE )
		{
			cout << padding << "Statement : WHILE ";
			for ( auto &e: expression ) e.dump();
			cout << '\n';
			for (auto &t: true_statements ) t.dump(depth+1);
		}
		else if ( type == SET )
		{
			cout << padding << "Statement : SET ";
			cout << "Var : " << (char)(varIndex+'a') << " = " ;
			for ( auto &e: expression ) e.dump();
		}
		else
		{
			cout << padding << "Statement : PRINT ";
			for ( auto &e: expression ) e.dump();
		}
		cout << '\n';
	}
};
unordered_map<string, int> Order;

struct Problem
{
	int N ;
	string line ;
	int offset;
	int var[26]{};

	Problem(int N) : N(N) { }
	void skipSpace(int addOffset)
	{
		if ( addOffset < 0 ) offset = 0;
		else offset += addOffset;
		for ( ; offset < line.length() && ( line[offset] == ' ' || line[offset] == '\t' ) ; offset++ ){}
	}
	void setExpression(Statement &currStatement)
	{
		int i, n ;
		bool canUnaryMinus = true;
		stack<string> St;
		string o;
		auto &exprList = currStatement.expression;

		for ( i = offset ; i < line.length() ; i++ )
		{
			if ( isspace(line[i]) ) continue;
			if ( isdigit(line[i]) )
			{
				canUnaryMinus = false;
				for ( n = line[i]-'0'; i+1 < line.length() && isdigit(line[i+1]); i++ )
					n = n*10 + line[i+1] - '0';
				exprList.emplace_back(NUMBER, n);
			}
			else if ( isalpha(line[i]) )
			{
				canUnaryMinus = false;
				exprList.emplace_back(VARIABLE, (int)(line[i] - 'a'));
			}
			else if ( line[i] == '(' )
			{
				St.emplace("(");
				canUnaryMinus = true;
			}
			else if ( line[i] == ')' )
			{
				while ( St.top() != "(" )
				{
					exprList.emplace_back(OPERATOR, St.top());
					St.pop();
				}
				St.pop();
				canUnaryMinus = false;
			}
			else
			{
				o = {line[i]};

				switch (line[i])
				{
					case '-': // -- : unary
						if ( canUnaryMinus ) o.push_back('-');
					break;
					case '!':
					case '<':
					case '>':
						if ( line[i+1] == '=') o.push_back(line[++i]);
						break;
					case '=':
					case '&':
					case '|':
						o.push_back(line[++i]);
						break;
				}
				canUnaryMinus = true;

				while ( !St.empty() && St.top() != "(" )
				{
					int t = Order[St.top()] - Order[o];
					if ( t > 0 )
					{
						exprList.emplace_back(OPERATOR, St.top()); St.pop();
					}
					else
					{
						if ( t == 0 && St.top() != "!" && St.top() != "--" )
						{
							exprList.emplace_back(OPERATOR, St.top()); St.pop();
						}
						break;
					}
				}

				St.push(o);
			}
		}

		while ( !St.empty() )
		{
			exprList.emplace_back(OPERATOR, St.top()); St.pop();
		}
	}
	bool readStatement(vector<Statement>& statementList)
	{
		while ( N-- > 0 )
		{
			getline(cin, line); skipSpace(-1);

			if ( line.compare(offset, 3, "set" ) == 0 )
			{
				auto &statement = statementList.emplace_back(SET); skipSpace(3);

				statement.varIndex = line[offset] - 'a'; skipSpace(1);
				if ( line[offset] == '=' ) skipSpace(1);
				setExpression(statement);
			}
			else if ( line.compare(offset, 5, "while" ) == 0 )
			{
				auto &statement = statementList.emplace_back(WHILE); skipSpace(5);
				setExpression(statement);
				readStatement(statement.true_statements);
			}
			else if ( line.compare(offset, 2, "if" ) == 0 )
			{
				auto &statement = statementList.emplace_back(IF); skipSpace(2);
				setExpression(statement);
				auto hasElse = readStatement(statement.true_statements);
				if ( hasElse )
					readStatement(statement.false_statements);
			}
			else if ( line.compare(offset, 5, "print" ) == 0)
			{
				auto &statement = statementList.emplace_back(PRINT); skipSpace(5);
				setExpression(statement);
			}
			else if ( line.compare(offset, 4, "else" ) == 0)
				return true;
			else if ( line.compare(offset, 3, "end" ) == 0 )
				break;
		}
		return false;
	}

	int getExpression(vector<Expr> &expression)
	{
		stack<int> nums ;
		int a, b;

		for (auto &e: expression)
		{
			if ( e.type == NUMBER ) nums.push(e.num);
			else if ( e.type == VARIABLE ) nums.push(var[e.num]);
			else if ( e.type == OPERATOR )
			{
				b = nums.top(); nums.pop();
				if ( e.op == "--" )
				{
					nums.push(-b);
					continue;
				}
				if ( e.op == "!")
				{
					nums.push(!b);
					continue;
				}

				a = nums.top(); nums.pop();

				if ( e.op == "*") nums.push(a * b);
				else if ( e.op == "/") nums.push(a / b);
				else if ( e.op == "%") nums.push(a % b);
				else if ( e.op == "+") nums.push(a + b);
				else if ( e.op == "-") nums.push(a - b);
				else if ( e.op == "<") nums.push(a < b);
				else if ( e.op == "<=") nums.push(a <= b);
				else if ( e.op == ">") nums.push(a > b);
				else if ( e.op == ">=") nums.push(a >= b);
				else if ( e.op == "==") nums.push(a == b);
				else if ( e.op == "!=") nums.push(a != b);
				else if ( e.op == "&&") nums.push(a && b);
				else if ( e.op == "||") nums.push(a || b);
			}
		}
		return nums.top();
	}

	void execute(vector<Statement>& statementList)
	{
		int ret ;
		for ( auto &statement : statementList )
		{
			switch ( statement.type )
			{
				case IF:
					{
						ret = getExpression(statement.expression);
						if ( ret != 0 )
							execute(statement.true_statements);
						else if ( !statement.false_statements.empty() )
							execute(statement.false_statements);
					}
					break;
				case WHILE:
					{
						while ( getExpression(statement.expression) != 0 )
							execute(statement.true_statements);
					}
				break;
				case SET:
					{
						var[statement.varIndex] = getExpression(statement.expression);
					}
				break;
				case PRINT:
					{
						ret = getExpression(statement.expression);
						cout << ret << '\n';
					}
					break;
			}
		}
	}
};

void process(int N) {
	vector<Statement> statementList;

	Problem p(N);
	p.readStatement(statementList);
	p.execute(statementList);
	// for (auto &s : statementList) s.dump(0);
}
void init()
{
	Order["("] = Order[")"] = 7;
	Order["--"] = Order["!"] = 6;
	Order["*"] = Order["/"] = Order["%"] = 5;
	Order["+"] = Order["-"] = 4;
	Order["<"] = Order["<="] = Order[">"] = Order[">="] = 3;
	Order["=="] = Order["!="] = 2;
	Order["&&"] = 1;
	Order["||"] = 0;
}
int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int N;
	init();
	while ( cin >> N && N )
	{
		cin.ignore();
		process(N);
	}
    return 0;
}
