#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

void init(){}

bool isLarger(string &a, string &b) // a > b ?
{
	if ( a.size() > b.size() ) return true;
	int len = a.size();
	for ( int i = len-1; i >= 0 ; i -- )
		if ( a[i] != b[i] ) return a[i] > b[i];
	return false;
}
void setPalindrome(string &a, int pos, int add)
{
	int len = a.size();
	int i, j, c, t;
	for ( i = pos, c = add ; i < len ; i ++ )
	{
		t = ( a[i] - '0' + c );
		c = t / 10;
		a[i] = (t % 10) + '0';
	}
	if ( c != 0 ) a.push_back( c + '0' );

	len = a.size();
	for ( i = len/2, j=i-(len % 2==0) ; i < len ; i ++, j-- )
		a[j] = a[i];
}

void process(int Case) {
	string B, A ;
	int pos, i, len ;
	cin >> B ;
	reverse(B.begin(), B.end());
	A = B;

	for ( i = 0 ; i < 10 ; i ++ ) {
		len = A.size();
		setPalindrome(A, len/2, i);
		if ( isLarger(A, B) )
		{
			cout << A << '\n';
			break;
		}
	}
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
