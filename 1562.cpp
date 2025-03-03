// 계단 수
// https://www.acmicpc.net/problem/1562

#include <iostream>
#define MOD 1000000000
using namespace std;
int N;
int dp[101][10][1024];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    
    cin >> N;
    for(int j=0;j<=9;j++) {
        dp[1][j][1<<j] = 1;
    }
    
    for(int i=1;i<N;i++) {
        for(int j=0;j<=9;j++) {
            for(int k=0;k<1024;k++) {
                if(j<9) {
                    dp[i+1][j+1][k | 1<<(j+1)] += dp[i][j][k];
                    dp[i+1][j+1][k | 1<<(j+1)] %= MOD;
                }
                if(j>0) {
                    dp[i+1][j-1][k | 1<<(j-1)] += dp[i][j][k];
                    dp[i+1][j-1][k | 1<<(j-1)] %= MOD;
                }
            }
        }
    }
    
    long long result = 0;
    for(int j=1;j<=9;j++) {
        result += dp[N][j][1023];
        result %= MOD;
    }
    cout << result;
    return 0;
}