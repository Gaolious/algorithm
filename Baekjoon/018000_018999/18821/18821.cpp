#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const char *Base="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789`~!@#$%^&*()_-=+|[{]}:;'<,>.?/";
const char *D="df~7M@f~7M$f~7M[f~7M:f~7M'f~7M,f~7M/s~7MBt~7M7t~7Mf|~7Mh|~7M1|~7M1|~7M5|~7MV{~7Mb{~7Mb{~7Mh{~7Mh{~7M1{~7M1{~7M3{~7M3{~7M5{~7M5{~7M.{~7M.{~7MB]~7MB]~7MJ]~7MJ]~7Md]~7Md]~7Ml]~7M1]~7M5]~7M5]~7M7]~7M7]~7M9]~7M9]~7M~]~7M~]~7M@]~7M@]~7M$]~7M[]~7M]]~7M:]~7M,]~7MH}~7Mb}~7Md}~7Mv}#7Mx}#7Mz}#7Mz}#7M1}#7M1}#7M3}#7M5}#7M7}#7M9}#7M~}#7M~}#7M[}#7MV;#7MX;#7MX;#7Md;#7Ml;#7Mp;#7M5;#7M7;#7M5g%7MXi%7Mpi%7Mri%7M[i%7M]i%7M]i%7M:i%7Mxj%7M3j%7M3j%7M~j%7M$j%7M^j%7Mjm%7Mlm%7Mpm%7M1m%7M1m%7M3m%7M3m%7MTn%7MTn%7Mro%7Mro%7M.o%7M.o%7MHp%7MHp%7MJp%7MJp%7M:4%7M:4%7M'4%7MF5%7MJ5%7MJ5%7ML5%7Mb5%7Mn5%7Mn5%7M$6%7M$6%7M+6%7MZ7%7Mb7%7Mb7%7M]8%7M]8%7M:8%7Mh%%7Ml%%7Ml%%7M5%%7M5%%7M7%%7M9%%7M~%%7M~%%7MB^%7MH^%7MJ^%7ML^%7MN^%7Mb^%7Mh^%7Mj^%7Ml^%7Ml^%7Mn^%7Mv^%7M3^%7M~W&7M@W&7M@W&7M:W&7M:W&7MZa&7Mva&7Mza&7Mza&7M1a&7M1a&7M3a&7MXc&7Mbc&7Mbc&7Mhc&7Mjc&7Mlc&7Mlc&7Mpc&7Mpc&7Mrc&7M*c&7M:c&7M:c&7M'c&7MtCK8M[CK8M~DK8MbEK8MbEK8MdEK8MdEK8MfEK8M7EK8M9EK8M9EK8M~EK8M@EK8M.EK8M/EK8MBFK8MBFK8MDFK8MDFK8MFFK8M7HL8MpJL8MpJL8MrJL8MrJL8M1JL8M1JL8M3JL8M3JL8M5JL8M$JL8M[JL8M.JL8M/JL8M/JL8M1KL8M5KL8M9KL8MZLL8MbLL8M1LL8M5LL8MXML8MZML8MZML8MdML8MdML8MfML8MfML8MhML8MlML8MtML8MtML8MvML8M9ML8M1NL8M1NL8M3NL8M5NL8M7NL8M7NL8M9NL8M9NL8M~NL8M*NL8M)NL8M)NL8MjOL8MjOL8MlOL8MlOL8MnOL8MnOL8MvOL8M~OL8M@VL8M@VL8M^VL8M^VL8M]VL8MNWL8MPWL8MhWL8MjWL8MpWL8MrWL8MrWL8MvWL8MvWL8MxWL8MxWL8M~WL8M@WL8M$WL8MNXL8MPXL8MPXL8MZXL8MbXL8M";
const int B = 92;
char M[256]{};
int decode(const char *p, int len) {
    int ret=0;
    while(len--) ret = ret * B + M[p[len]];
    return ret;
}

int main()
{
    fastio;
    int i, a, b, j ;
    int F, L;
    memset(M, -1, sizeof(M));
    for (i = 0 ; Base[i] ; i ++ ) M[ Base[i] ] = i;
    F = decode("df~7M", 5);
    L = decode("bXL8M", 5);
    bitset<400000> C;
    for ( i = 0 ; i < 272 ; i +=2 ) {
        a = decode(D+i*5, 5);
        b = decode(D+(i+1)*5, 5);
        for ( j=a ; j<=b ; j++) C[j-F] = 1;
    }
    int N; cin >> N;
    for (int n; N-- && cin >> n;) {
        bool flag = n == 1 || F <= n && n <= L && C[n - F];
        cout << "OE"[flag] << '\n';
    }
    return 0;
}


