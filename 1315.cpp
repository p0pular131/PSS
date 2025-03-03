// RPG
// https://www.acmicpc.net/problem/1315

#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;
int N,result;
int dp[1001][1001];
struct Quest {
    int Str;
    int Int;
    int Pnt;
}; 
vector<Quest> vec;

void solve(int a, int b) {
    if(dp[a][b] != 0)  // 이미 확인했으면 의미 없음
        return;
        
    int clearCnt = 0, clearPoint = 0;
    for(int i=0;i<N;i++) {
        Quest qst = vec[i];
        if(a >= qst.Str || b >= qst.Int) {
            clearPoint += qst.Pnt;
            clearCnt++;
        }
    }

    dp[a][b] = clearCnt; 
    result = max(result,dp[a][b]);

    // 스탯을 올릴 수 있는 포인트는 현재 사용한 포인트 차감한만큼
    int possblePoint = clearPoint - a - b + 1 + 1; 
    for(int na=a;na<=a+clearPoint;na++) { 
        int nb = b+(clearPoint-na); 
        if(na > 1000 || nb > 1000) 
            continue;
        solve(na,nb);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    result = 0;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++) {
        Quest temp;
        cin >> temp.Str >> temp.Int >> temp.Pnt;
        vec.push_back(temp);
    }
    solve(1,1);
    
    cout << result;
    return 0;
}