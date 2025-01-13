#include <bits/stdc++.h>
using namespace std;

void init(){
}

void process(int Case) {
	int N;
	int len;
	string S, A;
	cin >> N >> S;
	reverse(S.begin(), S.end());

	while ( S.size() > 0 )
	{
		A.push_back(S.back());
		S.pop_back();

		while ( (len = A.size()) >= 3 && A[len-1] == 'B' && A[len-2] == 'B' && A[len-3] == 'A' )
		{
			A.pop_back();
			A.pop_back();
			A.pop_back();
			A.push_back('B');
			S.push_back('A');
		}
	}
	cout << A << '\n' ;
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
