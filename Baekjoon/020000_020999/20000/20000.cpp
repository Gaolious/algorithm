#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);
using namespace std;
typedef long long ll;
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
string BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int BInv[127]{};
void p0() {
	cout <<"BOJ 20000\n";
}
void p1() {
    char *s4="    ";
    char *s8="        ";
    cout << "#include <cstdio>\nint main(){\n    int N;\n    scanf(\"%d\",&N);\n";
    for (int i = 1 ; i <= 20000 ; i ++ ) {
        cout <<s4<< (i!=1?"else ":"") << "if(N=="<<i<<"){\n"<<s8<<"puts(\""<<i*4<<"\");\n"<<s4<<"}\n";
    }
    cout << "    else{\n        puts(\"Still working on it...\");\n    }\n    return 0;\n}\n";
}
void p2() {
    string C = "BaekjoonOnlineJudge!";
    int i, j, c ;
    string T[21];
    for ( i = 1 ; i < 1048576 ; i ++ )
        for ( j = 19 ; j>=0 ; j -- )
            if ( i % ( 1 << j ) == 0 ) {
                cout << C[j];
                break;
            }
    cout << '\n';
}

void p3draw(vector<vector<char>> &M, vector<bool> &tree, int idx, int y, int x, int len) {
    int i ;
    if ( len < 1 )
        return;
    if ( len == 1 ) {
        if ( tree[idx*2] ) M[y][x-1] = '/';
        if ( tree[idx*2+1] ) M[y][x] = '\\';
        return;
    }
    if ( tree[idx*2] ) {
        for ( i = 0 ; i < len / 2 ; i ++ ) M[y+i][x-i-1] = '/';
        p3draw(M, tree, idx*2, y+len/2, x-len/2, len/2);
    }
    if ( tree[idx*2+1] ) {
        for ( i = 0 ; i < len / 2 ; i ++ ) M[y+i][x+i] = '\\';
        p3draw(M, tree, idx*2+1, y+len/2, x+len/2, len/2);
    }
}

void p3() {
    int i, j, k ;
    string C = "QbccWQx8WorvKRjiG+Qq41GFbA4M72UxtzueKz11iKpRiddvEXnjm4u9VfHKdfZl9mmfjrlNBBEAAAAAAAAAAHpfA6Vyzyu18GET3vZx3UNDJmNNhaS56lutf//RKYyB7CBKHZLezb0mguYhI65KFoyHytHtwpZPKIy6WdBaw13TclYVfN/lq2L/byJDm99y//////////+0S7HSpdYpg04VcG2uKMqX4mR4Xa5h1iSzQOuqhKze3rWGAEFp/R4gwRV4OPa7JP3XSrCaCZXQNLo1pm5eIWVtbnfCVulfJ8gvkHaWs/eDR+L331ybWsFbYhLzgk8+a/DR9w54RXu8AQ";
    int base = 2048;
    vector<bool> tree(base*2+1);
    vector M = vector(1024, vector<char>(2048,' '));

    for ( i = 0 ; i < C.size() ; i ++ ) {
        k = BInv[C[i]];
        for ( j = 0 ; j < 6 ; j ++ ) {
            tree[base + i*6+j] = !!(k & ( 1 << (5-j) ));
        }
    }
    for (i=base-1; i > 0 ; i -- ) tree[i] = tree[i*2] || tree[i*2+1];
    p3draw(M, tree, 1, 0, 1024, 1024);

    for (auto &t: M) {
        while ( t.back() == ' ') t.pop_back();
        for (auto &c: t) cout << c;
        cout << '\n';
    }
}
void p4() {
    vector prime(1024+1, true);
    vector<string> A(1000+1);
    prime[0] = prime[1] = false;
    int i, j;
    for ( i = 4 ; i <= 1024 ; i += 2 ) prime[i] = false;
    for ( i = 3; i < 1024 ; i +=2 ) {
        if ( !prime[i] ) continue;
        for ( j=i*i ; j <= 1024 ; j += i )
            prime[j] = false;
    }
    for ( i = 0 ; i < 1000 ; i ++ )
        for ( j = 0 ; j <= i ; j ++ )
            A[i].push_back( prime[i^j] ? '#' : '.' );
    for ( i = 0 ; i < 1000 ; i ++ )
        cout << A[i] << '\n';
}
void p5() {
    int i;
    string C = "FLzm3imWUwFFAeBfNes01HUPlqzR8fgZjZKLef7iKiKtNmHAm7XXMzf1Kp5IEoKJfOoy/qU6DDe504Fb2Beobyt6C0U9l3EeSFOHerqS8+57F3WejYiRCYhZqkVjSYTSCnhb1HxqeWHiNR4gy9pllVW/ZfSvLO1hkjalmNT8pFw3rmGcx0uOnUNXhnDTcOe97R7MF0iv/qJN41eLE3Zsq5cVVKYffLO0ve8jaU4fLDm2Q38GRxvD789SD9EwK+B3rnwapnsL7ekeSI5G8yCwtnstD1610WGa32uVQhmz32N+MAkVmTFjAHHUgEok9xCzQ9t/tII7+gvpNO/R8B7BqcV1J3/yTs66KJMAU5lvI32fmII+oWUb7AMROasqvVKdi8EE6DakYJUs5qjsgt+YA9rUpGSoPed/CLVA17socSHjR4qBsiBkyyBVtg79+ZQIf2RirFl7rHAOfOefaMDWoEeT8ghIlpQwPl+17b9QsgRPJz6/zAq2XhgF9YJXQcXI+9cpjVfkXB6XfcRqRMTiXqVJchTqlwUblSDOCrf+DcaYWDp7r9cxPH1WsZSiROSEy/mVCc6nxcbtPS7We8WW4E+EhDdtdkggACibRc3A+bkN5AXE7QtoOFu50PH7TOpSwQJiDCZ94OJLFmKmZpcDh91CBfjl4H2Z8nKGeaNoD1yP8GQkYoZlnxhQfFCrTxsUFfzW2fNYtUD9Lnsk8BD2R+RAEIwXLtt0ZZG6dixBzfAxJZFozobMwtH3HFCO6cJjlfhw2sqBwspKJvo50ubOYepR9sLeJnvLywgQ/N6w9RQIYmO981jn5vXhIcnYq4WubUyu1RaUlvApDwZbUwXkmlpn5dQeX47crd4oiMfNNyB29WMQusyJwmC9rIeipj3pWTMOdle2oCPwGwGOvdxAGOtOxkyCRzz4qt1zkL3GdWIlaNaH76SnbnFa7oa3WaC7Uz0vH1kKtPTBijulxBuwJg1aN/XXWN2DIjgr59Tic95NF6Kmz0w/xg2ZVf+JGYGjiV1L+mrW5seHY7WaqwpchNCJXz/2QL/9aYHg3TzE09otYF5nlcm7RwbJGPJum7mYHMzcJA6HEybx0dUtGo6Yi3ZFcNyvMkDsav/CM1bi6XvHknCehARK8a4Qsfm/dmoimRoaRZ4ldkZjjdRf063avaTxgujtqU+J9XljU+ZhTegH6wYs/LvWthTK0sVhMqsWec32tvh0LLpOg1+BAGcDZ4aCxP2uTFSa8LbA0r9K4nfHSVt+1hIqQJOGBK4fUSm31QUJk5M4YYVcYQztnDsqultxTWx9uMCvmLLmGlJzaDwmNvjKNpl3nZztuYxQBGDou4YIH1t4oBFtTtf/EJ/ZRYqukjzPjh2RKYXCCx5/jrXAoZt6ZTZgCFCJbS/5kMQotQHaoZbl6ZsyUYB5n4VHR2FMTr7QiaMeIb/AHzGNwumUJwHTgVaDW1y7rEZqpq22YWWHOwHJ7qppIEVhfCWUFOjUoG613+xDDxfcJrd+wJHgM3+WpCXEcDSTmktScoYnCjMdUN7Msef1a4dRC/NRrYI0FVacyNzoQFxZj0dpl2QqU2l/XM9u8f7RQc7wPbM0LxAyPP8Fwf11r0LLNdj0AYk6ufeCnr6yKvmoiPQutOH4OzKXhlbpNzXTegRgbNU4rRO1KBBG4PPMXpUFA0LNKN1S9ivk/Y8t933NHcCyXujy1wEvCYp1Xj/fuhb1b69KpgVzggUR8AZc3JViDII1vNJU5eqN8Nt+AEuOFTbpLjGcjsZGA2GkHr38hod9BL4U6V97X/6sHnk5AWaVlDB8v8IfxcT2qGuSRePOaIGeBv9xkRMz+f4HI4CItk0KYZeQiuXMx7AgWUJfRMQ40NCrSaxo/TpsBMM2apl0WiWHjY9NsU2icWJsm0V8P4H+ETgKl7vcTs6toGx1MYB4Qr62IguM5jtw+aDzWeAVWeApWDb5bPALqSJUSNEhXflWygn//8qiUqDLZ0INCUzKW1r9SEQ8NEPJtNmgvvM0vh5Dg1ORsRfbmQkI1miPjXxe/kOIbkUn5QqE+8XY89FLCr6YaULne4sfQ8eRl1x6wHzm8Eed2Nu5FAIManZaA7JbPAZxUn2c/hyRb/2DlQcKSGjI9/5K40qnr7n+Ug/ITOr9Hzc1nLt9Lt7+aPHRpU+8ej+SaSLqmWSXN2/vmCihb1G5wucX9oKpViwC41KJy+k7xL2EfKN3P+/gp6SheWHyU0p6j/a6A1bsV2l2z+mjDYCz0Un1226z1ODOjSJeDtQj3WdQNsaRv0z65SkkSHYvkFaU8OFZpBvklBiZaxwLbaQcusfozrSN2WYFedrQgD4Pmsg+65MTuurC+NhJySFgTSBsm/LYf57//H9q6LpvVOSsjnXHcHuqTD5AuwcAvBQrAwkYFOGRswc8vvT0u2UGQ6RYkDKH84/lXD3lthV9RbFsl+J0sbpj9nebP8LBbpHHKOxSVK377V/OxkcSCXZa7308fxNDuJAs6h7mMSwvY6NPAMrBZvSletqaNKRutOba9hZC4rqsy9xP6kZrAres/Fj/G6vnIbhgcFDSZlixz38/A35vmhQd2FJxMYzU4j855e1wpimVCa5s7KYWVC7mhfRbydCJwGxNn1zK2GryekmtOh/hUrqF3lYCmjSSBbfTAngJYaYdb/tkH//XsQFPl2dJzqJc7lqTqv9ghmECoKoO7+Zb/ztarKTF02GZJBNq+iwx0b9aWUhbhtc8vvRpRddtnYBUXG/t3v5sOqEyShSW/r9ch214FzJlv9Q8dneRLFwfNaHgoLuP4AzY+X3MxenTHnSA4/00wPHbFepP+1Cphm3ITUM2vOkvw7i5AwXVNr8daoPTd9AsC6god58t4ozqRNLTUBlcKNxG72LSRhFVHG94unChsg39dKn+7hHHcn2YJFG+zhL2xOEHEBUO+jOxCKT7qbNsT6jXMdD1roum+69+AWm6WiIr0DGn/mv+aLCV1xtVsoM2w2/y/AgOJGQeexRB9oeoCdQvL7/FIl2lmAUqIfjI692yliYuOmKE2duCeN6eGrJME4SpLMOKwN8x7jzuvAwd6EtrgYQRylY08dOpvsGWPXoxLfLlCaTuLkp8Zma2vnT86B/uFJ9LUfmj0RJGu4p4AcIO/zEmLvyudnpvMLzDbu1uO/Klm839KdL8IlNtzuKYVDtxmhn4dhXTIOhH7EEroNex3aAblclRpOkB/PqDqlk2mJ8TLTOgjfMEaF8B4JqFNATDROuOPuoF0r3G+c5dqmk5dSfmz3ZAZ45Y7QK4ZvjTXoHwvCiAj4n+GzeD+4GDPRya5wzNC/5fL0s+5ZxAl27fKGajmBY5lriRy4ja5Jtg0h0RRJ+9mPzE7Du/7AxzWyCu5zYCRwfnku4ShEVDcEObfdC4hXJc+lohO8BXxnn7Md6pnY3ThBt/f/a+KswpYf1WXQG/Zfk2uBQAVNPFJDkDXuV8De2b7mqZ3F0x2qzFwPg4RYpXL3aBWW+XhPiTWVavx83TAvDO2ByjmF2vT3qlGz9dwXIvvmPN75YPeutqC8idBgPI5YqqnnoQjCqQHBFEoiiHVAqr61pnqwvjnRWiy9p0eDSSd2NZc5n6kXYrxbep1hdHOpjfSn/Qdb0SETDlVX9ebGLk3Ef8XkWKOicy6WXOtP4jgccCOV3svA0PyVpgpXtdxEK21fS30Jt8c6AeMFRMUKvAmgVfZsKLkAFBs24GsEDMHVfILexcD/GBTiAdGS//qXFPTwK5VIiqIEK2EzIG+aIenIv0II9GzjPNMkvp2nFkmE2vG3a7g88EiwFyTbFvkck6aTLycYP8ful0CvHt0itqza7GEGXh+x4ZVqc4agTKLkQyPkpEhPx891n+W6quMGayghUu7/G/BaBQe5OaI1423gyXrgjHbkeqa8efgamDqr8yepyiogy8WvTPyy3Cl6tiIysXPXDeflJ81Bf4RntNWzK5rXafA0JHMCeLt9l8oZJyTgKqG1nuHX9KH30v3/sXgG/15JCCF/vInxc68CoujCxtU9UjcpHwocSKsnAxzY259tsc+VlBmLbySg5fCh8tZ9MEhe9c82uHRSRNF6OhY1YYQJyq8NyR8tgHtR2EtX/N38wMiC4zspUnCRHfJqyfOT1bUKscK66y9NEeJX6wT7a5gS4meNJFnPcnEYXZSia/AZ+0wUSbXtLWx3B8cDj6E2ddbb+4LUePa61y57dwbLoZ9BNO/cw3d4TjewiEO7qOuL6+KewTd5s6Kxrcu0zrdQnzofHcn5NCMQ5yAbl9VWbTAfx5R3nBFDS3MwM3wIC6mxFR+KbPuYwh7BpG/CUSMAdoWeOLkzIbP2Q/LUuZSpncwSNnP+on6QCYG95FlFd5CJhOaWKDL4tkzKVfwIDRSCU+hWI2vaK4A13lqNPV0QZD7lib46+/pXWvXeUf6nwxH14wk5MLLJnGvKcrinU3BoFkW4PAGiyJ1vDxuhlPpbumepb5ckbJppBJ+tB+AQPHHyooAJ8Ai7k40VVpRPhiiSNgOZudYrj9UbhdvHuubpr2BGQp1T5oswffPqj485VkIhB3RDnUfP0wzP+Uy83y8OftDdA9GP1aStoJYTPq00MStF7WQhMPwreLNGa+O4+R1EeBDPM4S9iriUsG4Ki8k53w8RXOtCVfw1m4UDDA019BarjklwLHBBnLYguB+v+PJxmUPJbvPkaZBC2sSjFx0bNO0v4MiUcbqCmCjqz6optfqtEtrKDk+jFapaB/xmTLeVgtShXAiDF5KI5nM0Qte9j/u3Kem5N2PjwpC4x9c2lw76OAJXdRXIPmSD3nCIRMEwW0uI99y109BioNb87+84mPaKtS6CG8a3jZM3oQzWDcPD+guc/rd2c2xw+e373j93uaD/nUNqcM3ysjUuUS536+B7uFOfGnuwyPtbbwX+Od8wDsHZ8bq42aCn95iaUD7pygIqEjzDIlWQEiIIVlXk95DxmcHJJktFOWPUVgypGlIniP";
    for ( i = 0 ; i < 200 ; i ++ ) cout << C;
    cout << '\n';
}

vector<int> p6block = { 13, 17, 19, 28, 31, 37, 39, 46, 64, 71, 73, 79, 82, 91, 93, 97 };
vector<bool> p6check;
bool p6first;
void p6f(int idx, int len, long long n) {
    if ( n >= 10 ) {
        int v = n % 100;
        auto ret = binary_search(p6block.begin(),p6block.end(), v);
        if ( ret ) {
            bool found = false;
            for( ll k = n/100 ; k && !found ; k/=10)
                if ( (k%10) * 2 == v%10 + v/10 ) found = true;
            if (!found ) return ;
        }
    }
    if ( idx >= len ) {
        if (p6first) p6first = false;
        else cout << ' ';
        cout << n;
        return;
    }
    for ( int i = 1 ; i<= 9 ; i ++ ) {
        if ( p6check[i] ) continue;
        p6check[i] = true;
        p6f(idx+1, len, n*10+i);
        p6check[i] = false;
    }
}
void p6() {
    p6first = true;
    p6check.resize(10, false);
    for (int i = 4 ; i < 10 ; i ++)
        p6f(0, i, 0);
    cout <<'\n';
}
vector<bool> p7v;
int p7Idx;
vector<string> p7ans;
void p7f(int x, int y, int l) {
    // 십자 모양 저장
    for (int i = 0; i < l - 3; i++) {
        p7ans[x + i][y] = '.';
        p7ans[x - i][y] = '.';
        p7ans[x][y + i] = '.';
        p7ans[x][y - i] = '.';
    }
    // 십자의 끝에서 연결 구간 조건에 맞게 저장
    if (p7v[p7Idx++]) for (int i = 1; i < 5; i++) p7ans[x - l + 4][y - i] = '.';
    else for (int i = 1; i < 5; i++) p7ans[x - i][y - l + 4] = '.';
    if (p7v[p7Idx++]) for (int i = 1; i < 5; i++) p7ans[x - i][y + l - 4] = '.';
    else for (int i = 1; i < 5; i++) p7ans[x - l + 4][y + i] = '.';
    if (p7v[p7Idx++]) for (int i = 1; i < 5; i++) p7ans[x + l - 4][y + i] = '.';
    else for (int i = 1; i < 5; i++) p7ans[x + i][y + l - 4] = '.';
    if (p7v[p7Idx++]) for (int i = 1; i < 5; i++) p7ans[x + i][y - l + 4] = '.';
    else for (int i = 1; i < 5; i++) p7ans[x + l - 4][y - i] = '.';

    if (l == 8) return; // 말단인 경우
    l /= 2;
    p7f(x - l, y - l, l);
    p7f(x - l, y + l, l);
    p7f(x + l, y + l, l);
    p7f(x + l, y - l, l);
}

void p7() {
    string C = "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";
    p7ans.resize(2400, string(2400, '#'));
    p7v.resize(C.size()*6);
    int i, j, k, d;

    for ( i = 0 ; i < C.size() ; i ++ ) {
        k = BInv[C[i]];
        for ( j = 0 ; j < 6 ; j ++ )
            p7v[i*6+j] = !!(k & ( 1 << (5-j) ));
    }
    p7f(512, 512, 512);
    for (int i = 3; i < 1022; i++) {
        for (int j = 3; j < 1022; j++) {
            if (p7ans[i][j] == '.')
                cout << '.';
            else {
                bool found = false;
                for (d = 0; d < 8; d++)
                    if(p7ans[i + dy[d]][j + dx[d]] == '.') {
                        found = true;
                        break;
                    }
                cout << (found ? '#' : '.');
            }
        }
        cout << '\n';
    }
}

int p8v[] = { 0, 1, 2, 2187, 2189, 4374, 4375, 4376 };
void p8f(int s, int n, vector<int> &v) {
    if (n == 1) {
        v[s/6] |= 1 << (5-s%6);
        return;
    }
    n /= 3;
    for (int i : p8v)
        p8f(s + n * i, n, v);
}
void p8() {
    vector d(797161, 0);
    string ans;
    p8f(0, 2187, d);
    for (auto n: d) ans.push_back(BASE64[n]);
    cout << ans << '\n';
}
void p9() {
    ll m = 1695327975ll, k, t;
    for (ll i = 0; i < 100000; i++) {
        k = i % m;
        t = (376739550ll * i + 28540875ll ) % m;
        t = (t * k + 565524465ll) % m;
        t = (t * k + 855292706ll) % m;
        t = (t * k + 20000ll) % m;
        if ( i ) cout << ',';
        cout << t ;
    }
    cout << '\n';
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int n, i;
    cin >> n ;
    for ( i = 0 ; i < BASE64.size() ; i ++ ) BInv[BASE64[i]] = i;

    if ( n == 0 ) p0();
    if ( n == 1 ) p1();
    if ( n == 2 ) p2();
    if ( n == 3 ) p3();
    if ( n == 4 ) p4();
    if ( n == 5 ) p5();
    if ( n == 6 ) p6();
    if ( n == 7 ) p7();
    if ( n == 8 ) p8();
    if ( n == 9 ) p9();

    return 0;
}