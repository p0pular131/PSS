// 행렬 곱셈 순서
// https://www.acmicpc.net/problem/11049

#include <iostream>
#define INT_MAX 2147483647
using namespace std;

int N;
int dp[501][501];
int mat[501][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> mat[i][0] >> mat[i][1];
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            dp[i][j] = INT_MAX;
        }
        dp[i][i] = 0; 
    }

    for(int len=2; len<=N; len++) {
        for(int start=1; start+len-1<=N; start++) { 
            int end = start + len - 1;
            for(int k=start; k<end; k++) { 
                dp[start][end] = min(dp[start][end], 
                    dp[start][k] + dp[k+1][end] + mat[start][0] * mat[k][1] * mat[end][1]);
            }
        }
    }

    cout << dp[1][N] << '\n';
    return 0;
}
