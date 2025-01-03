#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T, N, M;
    cin >> T; 

    cin >> N;
    vector<int> Aa(N);
    for(int i=0;i<N;i++) {
        cin >> Aa[i];
    }
    
    cin >> M;
    vector<int> Bb(M);
    for(int i=0;i<M;i++) {
        cin >> Bb[i];
    }
    
    vector<int> sumA, sumB;
    
    for(int i=0;i<N;i++) {
        int currSum = 0;
        for(int j = i; j < N; j++) {
            currSum += Aa[j];
            sumA.push_back(currSum);
        }
    }
    
    for(int i=0;i<M;i++) {
        int currSum = 0;
        for(int j = i; j < M; j++) {
            currSum += Bb[j];
            sumB.push_back(currSum);
        }
    }
    
    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());
    
    long long idx = 0, result = 0;
    
    for(int i=0;i<sumA.size();i++) {
        long long curr = sumA[i], target = T-curr;
        auto range = equal_range(sumB.begin(),sumB.end(),target);
        if(*range.first == target) 
            result += range.second - range.first;
    }
    
    cout << result << '\n';
    return 0;
}
