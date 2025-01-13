#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int L;
    string word;
    cin >> L >> word;

    int alphabet_num[L];
    unsigned long long M = 1234567891;                // moduler
    unsigned long long hash_key = 0;   // 해시값을 저장할 변수
    unsigned long long Unique_num = 1; // 31의 거듭제곱 변수
    for (int i = 0; i < L; i++)
    {
        hash_key = ( hash_key + alphabet_num[i] * Unique_num ) % M;
        Unique_num = (Unique_num * 31) % M ;

        alphabet_num[i] = word[i] - 96;

        unsigned long long temp = 0;
        temp = ((alphabet_num[i] % M) * (Unique_num % M));
        hash_key += temp;
        Unique_num = (Unique_num * 31) % M;
        hash_key %= M;

        cout << word[i] << "(" << i << ") : Hash = " << hash_key << '\n';
    }

    cout << hash_key << '\n';

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
