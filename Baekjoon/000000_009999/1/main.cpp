#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int len = rocks.size();
    if(len == n)
        return distance;

    sort(rocks.begin(), rocks.end());
    vector<int> A;
    int start = 0;
    for(int i = 0; i < len; i++){
        A.push_back(rocks[i] - start);
        start = rocks[i];
    }
    A.push_back(distance - start);

    int low = 1;
    int high = distance;
    while(low < high){
        int mid = (low + high + 1) / 2;
        int count = 0;
        int prev = 0;
        for(int i = 0; i < len + 1; i++){
            if(mid <= A[i] + prev){
                prev = 0;
            }
            else{
                count++;
                prev += A[i];
            }
        }
        if(count > n)
            high = mid - 1;
        else
            low = mid;
    }
    return low;
}

int solution(vector<string> arr)
{
    int answer = -1;
    memset(D, -1, sizeof(D));
    return sol(0,arr.size()/2-1,1, arr);
}

int main()
{
    fastio;
    vector<string> cmd = {
            "1", "-", "3", "+", "5", "-", "8"
    };
    cout << solution( cmd);
    return 0;
}


