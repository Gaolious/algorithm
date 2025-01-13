#include <bits/stdc++.h>

using namespace std;

string dump(float n) {
    int* ptr = reinterpret_cast<int*>(&n);
    int bits = *ptr;

    // 부호 비트, 지수 비트, 가수 비트 추출
    int sign = (bits >> 31) & 0x1;               // 부호 비트
    int exponent = (bits >> 23) & 0xFF;           // 지수 비트 (8비트)
    int mantissa = bits & 0x7FFFFF;               // 가수 비트 (23비트)

    // 출력
    string s;
    ostringstream iss(s);
    iss << sign << ' ' << bitset<8>(exponent) << ' ' << bitset<23>(mantissa) ;
    return iss.str();
}

string dump(double n) {
    // double의 메모리 구조를 long long으로 캐스팅하여 확인
    long long* ptr = reinterpret_cast<long long*>(&n);
    long long bits = *ptr;

    // 부호 비트, 지수 비트, 가수 비트 추출
    int sign = (bits >> 63) & 0x1;               // 부호 비트
    int exponent = (bits >> 52) & 0x7FF;          // 지수 비트 (11비트)
    long long mantissa = bits & 0xFFFFFFFFFFFFF;  // 가수 비트 (52비트)


    string s;
    ostringstream iss(s);
    iss << sign << ' ' << bitset<11>(exponent) << ' ' << bitset<52>(mantissa) ;
    return iss.str();

}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

    long long a = 99999999999999990;
    double b = 99999999999999990;
    long long c = 99999999999999991;

    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}
