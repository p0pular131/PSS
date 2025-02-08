// 단어 수학
// https://www.acmicpc.net/problem/1339

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> num(26,0);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    while(N--) {
        string input;
        cin >> input;
        for(int i=input.length()-1, weight=1; i>=0; i--, weight*=10) {
            int curNum = input[i]-'A';
            num[curNum] += weight;
        }
    }
    sort(num.begin(), num.end(), greater<int>());
    int result = 0, curr = 9;
    for(int i=0; i<26 && curr>=0; i++) {
        result += num[i] * curr;
        curr--;
    }
    cout << result << '\n';
    return 0;
}
