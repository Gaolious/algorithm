#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    ull output[] = {
            1,
            1,
            1,
            2,
            3,
            5,
            9,
            18LL,
            35LL,
            75LL,
            159LL,
            355LL,
            802LL,
            1858LL,
            4347LL,
            10359LL,
            24894LL,
            60523LL,
            148284LL,
            366319LL,
            910726LL,
            2278658LL,
            5731580LL,
            14490245LL,
            36797588LL,
            93839412LL,
            240215803LL,
            617105614LL,
            1590507121LL,
            4111846763LL,
            10660307791LL,
            27711253769LL,
            72214088660LL,
            188626236139LL,
            493782952902LL,
            1295297588128LL,
            3404490780161LL,
            8964747474595LL,
            23647478933969LL,
            62481801147341LL,
            165351455535782LL,
            438242894769226LL,
            1163169707886427LL,
            3091461011836856LL,
            8227162372221203LL,
            21921834086683418LL,
            58481806621987010LL,
            156192366474590639LL,
            417612400765382272LL,
            1117743651746953270LL,
    };
    int n ;
    cin >> n ;
    cout << output[ n - 1 ];
    return 0;
}


