// 컵라면
// https://www.acmicpc.net/problem/1781

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N;
struct _Prob {
    int dl;
    int cn;
};
typedef struct _Prob Prob;
vector<Prob> vec;
priority_queue<int, vector<int>, greater<int>> pq;

bool f(Prob a, Prob b) {
    if(a.dl < b.dl) return true;
    else if(a.dl > b.dl) return false;
    else {
        if(a.cn > b.cn) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    int maxTime = 0, result = 0;
    for(int i=0;i<N;i++) {
        Prob temp;
        cin >> temp.dl >> temp.cn;
        vec.push_back(temp);
        maxTime = max(temp.dl, maxTime);
    }
    sort(vec.begin(), vec.end(),f);
    
    for(auto elem : vec) {
        if(pq.size() >= elem.dl) {
            if(pq.top() < elem.cn) {
                result -= pq.top();
                pq.pop();
            }
            else 
                continue;
        }
        pq.push(elem.cn);
        result += elem.cn;
    }
    
    cout << result;
    return 0;
}