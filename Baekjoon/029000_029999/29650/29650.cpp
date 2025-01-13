#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*
M   --+-- A1 --+-- A11
    --+-- A2
    --+-- A3 --+-- A31 --+-- A311
               +-- A32 --+-- A321 --+-- A3211
                                    +-- A3212
                       --+-- A322
    --+-- A4
    --+-- A5 --+-- A51
    --+-- A6 --+-- A61
    --+-- A7
 * */

struct Data {
    string name;
    bool isDead;
    vector<Data *> ChildList;
};

unordered_map<string, Data *> M;
Data Cache[2001*2];
int CacheIdx = 0;
int TotalCount = 1;

Data *getNewCache(Data *parent, string &name) {
    Cache[CacheIdx] = {name, false, {}};
    M[name] = Cache + CacheIdx;
    return Cache + CacheIdx++;
}

void addChild(string &parent, string &child){
    if ( M.count(parent) == 0 )
        return;

    Data *p = M[parent] ;
    Data *c = getNewCache(p, child);
    p->ChildList.push_back(c);
    TotalCount ++;
}

void dead(string &name) {
    if ( M.count(name) == 0 )
        return;
    Data *p = M[name] ;
    p->isDead = true;
    TotalCount --;
}

void init() {}
Data * getNth(Data *root, int nth) {
    vector<Data *> kings;
    int size, i;
    kings.push_back(root);
    i = 0;

    if ( TotalCount < nth ) return NULL;
    if ( !root->isDead ) {
        if ( nth == 1) return root;
        else nth--;
    }

    while ( true ) {
        size = kings.size() ;
        for ( ; i < size ; i ++ ) {
            for ( auto c: kings[i]->ChildList ) {
                if ( !c->isDead ) {
                    if ( nth == 1 ) return c;
                    nth--;
                }
                kings.push_back(c);
            }
        }
        if ( size == kings.size() ) break;
    }
    return NULL;
}
void process(int Case) {
    int N ;
    char cmd;
    string a, b;
    int nth;

    cin >> N ;
    string rootName = "M";
    auto root = getNewCache(NULL, rootName);

    while ( N -- ) {
        cin >> cmd ;
        if ( cmd == '+' ) {
            cin >> a >> b;
            addChild(a, b);
//
//            cout << "\tAfter add " << b << '\n';
//            for ( int i = 1; i <= 5 ; i ++ ) {
//                auto ret = root->getNth(i);
//                if ( ret ) cout << '\t' << i << "-th : " << ret->name << '\n';
//                else cout << '\t' << i << "-th : empty\n";
//            }
        }
        else if ( cmd == '?' ) {
            cin >> nth;
            auto ret = getNth(root, nth);
            if ( ret )
                cout << ret->name << '\n';
            else
                cout << "-\n";
        }
        else if ( cmd == '-' ) {
            cin >> a;
            dead(a);
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
