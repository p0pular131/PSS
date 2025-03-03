// 퇴사 2
// https://www.acmicpc.net/problem/15486

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Work {
    int t, p;
};

vector<Work> vec;
int dp[1500001];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vec.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> vec[i].t >> vec[i].p;
    }

    memset(dp,0,sizeof(dp));

    int result = 0;
    for (int i=0;i<N;i++) {
        if (i>0) dp[i] = max(dp[i],dp[i - 1]);

        int nextDay = i + vec[i].t;
        if (nextDay <= N) {
            dp[nextDay] = max(dp[nextDay],dp[i] + vec[i].p);
        }
        result = max(result, dp[i]);
    }

    result = max(result, dp[N]);

    cout << result << '\n';
    return 0;
}
