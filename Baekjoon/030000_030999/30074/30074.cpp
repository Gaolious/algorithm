#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

void process() {
    int N, V, Z, T;
    int i, cleanCompletedTime;

    cin >> N >> V >> Z >> T;

    // N – 울타리 기둥의 수;
    // V - 톰이 울타리 기둥 하나를 청소하는 데 걸리는 minute
    // Z – Barbora가 하나의 울타리 기둥을 칠하는 데 걸리는 minute;
    // T - Tom은 Barbora보다 몇 분 일찍 일을 시작했습니다.

    int ans = 0, prevCompletedTime ;

    prevCompletedTime = 0;

    for ( i = 0 ; i < N ; i ++ ) {
        cleanCompletedTime = (i+1) * V - T;
        if ( cleanCompletedTime > prevCompletedTime)
            ans += cleanCompletedTime - prevCompletedTime;
        prevCompletedTime = max(prevCompletedTime, cleanCompletedTime) + Z;
    }
    cout << ans << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


