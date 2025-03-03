// Parcel
// https://www.acmicpc.net/problem/16287

#include <iostream>
#include <vector>
using namespace std;
int W,N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
        
    cin >> W >> N;
    
    vector<int> vec(N);
    vector<bool> dp(W+1, false);
    for(int i=0;i<N;i++) {
        cin >> vec[i];
    }
    
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            int sum = vec[i]+vec[j];
            if(sum > W)
                continue;
            if(dp[W-sum] == 1) {
                cout << "YES" << '\n';
                return 0;
            } 
        }
        for(int j=0;j<i;j++) {
            int sum = vec[i]+vec[j];
            if(sum < W) 
                dp[sum] = 1;
        }
    }
    
    cout << "NO" << '\n';
    
    return 0;
}