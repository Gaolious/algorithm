#include <iostream>
#include <math.h>

using namespace std;

long long dp[54];

long long my_pow(int n){
    long long mul = 1;
    for (int i = 0; i < n; i++)
    {
        mul *= 2;
    }
    return mul;
    
}

long long solution(long long x){
    if (x <= 0)
    {
        return 0;
    }
    
    if (x == 1)
    {
        return 1;
    }
    if (x == 2)
    {
        return 2;
    }
    
    int bit = int(log(x) / log(2));
    long long pow = my_pow(bit);
    long long res = x - pow + 1;
    
    return dp[bit] + res + solution(res - 1);
}

int main(void){
    long long a,b;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 4;
    for (int i = 3; i <= 53; i++)
    {
        dp[i] = dp[i-1] + my_pow(i-1) + ((i - 1) * my_pow(i-2));
    }

    cin >> a >> b;
    cout << solution(b) - solution(a - 1) << "\n";
    return 0;
    
}
