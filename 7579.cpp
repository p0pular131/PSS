// 앱
// https://www.acmicpc.net/problem/7579

#include <iostream>
using namespace std;
int N,M;
int mem[101];
int cost[101];
int dp[101][10001]; // i번째 어플, j 비용으로 얻는 최대 메모리 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int sum = 0;
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        cin >> mem[i];
    }
    for(int i=1;i<=N;i++) {
        cin >> cost[i];
        sum += cost[i];
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=0;j<=sum;j++) {
            if(j-cost[i] >= 0) { // update
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]]+mem[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]); 
        }
    }
    
    for(int j=0;j<=sum;j++) {
        if(dp[N][j] >= M) {
            cout << j << '\n';
            return 0;
        }
    }
    
    return 0;
}