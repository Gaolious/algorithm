#include <bits/stdc++.h>
using namespace std;

const string SUIT = "CDHS";
const string RANK = "23456789TJQKA";
int RANK_SIZE = 13;
int INV[256];
#define SORT(s) sort( (s).begin(), (s).end())

struct CARD
{
	char rank{}, suit{};
};
vector<pair<string, int>> StraightFlush, FourofaKind, FullHouse, Flush, Straight, ThreeofaKind, TwoPair, OnePair, HighCard;

int Find(vector<pair<string, int>> &A, string &str, int left, int right, int idx)
{
	int lower=-1, upper=-1;
	int l = left, r = right;
	if ( left < 0 || right < 0 || left > right ) return -1;
	if ( left == right ) return A[left].first == str ? left : -1;

	while ( l <= r )
	{
		int m = (l+r) / 2;
		if ( A[m].first[idx] < str[idx] ) l = m + 1;
		else { r = m - 1; lower = m; }
	}
	if ( lower == -1 ) return -1;

	l = lower, r = right;
	while ( l <= r )
	{
		int m = (l+r) / 2;
		if ( A[m].first[idx] > str[idx] ) r = m - 1;
		else { l = m + 1; upper = m ; }
	}
	if ( upper == -1 ) return -1;

	return Find(A, str, lower, upper, idx+1);
}

void init()
{
	int i, j, k, l, m, n;
	string s;
#define RC(a) RANK[ ( (a) + RANK_SIZE) % RANK_SIZE ]
#define GEN(a, b, c, d, e) do { s = { RC(a), RC(b), RC(c), RC(d), RC(e) }; sort( s.begin(), s.end() ); } while(false)
#define FORR(i) for ( i = RANK_SIZE - 1; i >= 0; i-- )
#define FORP(i, j) for ( i = j - 1; i >= 0; i-- )
	for ( i = 0 ; i < RANK.size() ; i++) INV[ RANK[i] ] = i;
	for ( i = 0 ; i < SUIT.size() ; i++) INV[ SUIT[i] ] = i;

	for ( n = 1, i = RANK_SIZE-1 ; i >=3 ; i -- )
	{
		GEN(i, i-1, i-2, i-3, i-4);
		StraightFlush.emplace_back(s, n++);
	}
	sort(StraightFlush.begin(), StraightFlush.end());

	// FourOfaKind
	FORR(i) FORR(j)
	{
		if ( i==j ) continue;
		GEN(i, i, i, i, j);
		FourofaKind.emplace_back(s, n++);
	}
	sort(FourofaKind.begin(), FourofaKind.end());

	// FullHouse
	FORR(i) FORR(j)
	{
		if ( i==j) continue;
		GEN(i, i, i, j, j);
		FullHouse.emplace_back(s, n++);
	}
	sort(FullHouse.begin(), FullHouse.end());

	// Flush
	FORR(i) FORP(j, i) FORP(k, j) FORP(l, k) FORP(m, l)
	{
		GEN(i, j, k, l, m);
		if ( Find(StraightFlush, s, 0, StraightFlush.size()-1, 0) != -1)
			continue;
		Flush.emplace_back(s, n++);
	}
	sort(Flush.begin(), Flush.end());
	for ( i = RANK_SIZE-1 ; i >=3 ; i -- )
	{
		GEN(i, i-1, i-2, i-3, i-4);
		Straight.emplace_back(s, n++);
	}
	sort(Straight.begin(), Straight.end());

	FORR(i) FORR(j)
	{
		if ( j == i ) continue;
		FORP(k,j)
		{
			if ( k == i) continue;
			GEN(i, i, i, j, k);
			ThreeofaKind.emplace_back(s, n++);
		}
	}
	sort(ThreeofaKind.begin(), ThreeofaKind.end());

	FORR(i) FORP(j,i) FORR(k)
	{
		if ( k == i || k == j) continue;
		GEN(i, i, j, j, k);
		TwoPair.emplace_back(s, n++);
	}
	sort(TwoPair.begin(), TwoPair.end());
	FORR(i) FORR(j)
	{
		if ( i == j ) continue;
		FORP(k,j)
		{
			if ( i == k ) continue;
			FORP(l,k)
			{
				if ( i == l ) continue;
				GEN(i, i, j, k, l);
				OnePair.emplace_back(s, n++);
			}
		}
	}
	sort(OnePair.begin(), OnePair.end());

	FORR(i) FORP(j, i) FORP(k, j) FORP(l, k) FORP(m, l)
	{
		GEN(i, j, k, l, m);
		if ( Find(StraightFlush, s, 0, StraightFlush.size()-1, 0) != -1)
			continue;
		HighCard.emplace_back(s, n++);
	}
	sort(HighCard.begin(), HighCard.end());
}

void process(int Case)
{
	int idx;
	string a;
	string strRank;
	vector<CARD> card[4];
	for ( int i = 0 ; i < 5 ; i ++ )
	{
		cin >> a ;
		for (auto &c:a) if ( 'a' <= c && c <='z' ) c = c - 'a' +'A';
		strRank.push_back(a[0]);
		card[ INV[a[1]] ].push_back( {a[0], a[1]} );
	}
	SORT(strRank);

#define LOOKUP_AT(x) do {\
	idx = Find( (x), strRank, 0, (x).size()-1, 0) ; \
	if ( idx >= 0 ) { cout << 7463 - (x)[idx].second << '\n'; return; } \
	} while (false)

	for (auto &v: card)
	{
		if ( v.size() == 5 )
		{
			LOOKUP_AT(StraightFlush);
			LOOKUP_AT(Flush);
		}
	}
	LOOKUP_AT(FourofaKind);
	LOOKUP_AT(FullHouse);
	LOOKUP_AT(Straight);
	LOOKUP_AT(ThreeofaKind);
	LOOKUP_AT(TwoPair);
	LOOKUP_AT(OnePair);
	LOOKUP_AT(HighCard);
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
