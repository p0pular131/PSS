// 저울
// https://www.acmicpc.net/problem/2437

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> vec;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int temp; cin >> temp; 
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    
    int cur = 1;
    for(auto elem : vec) {
        if(cur < elem) {
            break;
        }
        cur += elem;
    }
    cout << cur;
    return 0;
}