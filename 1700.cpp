// 멀티탭 스케줄링
// https://www.acmicpc.net/problem/1700

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K;
vector<int> vec;
vector<int> keys;
int mtt[101];

struct _Node {
    int next_idx;
    int idx;
    int value;
    bool operator<(const _Node& other) const {
        return next_idx > other.next_idx; // 가장 늦게 등장하는 것 기준 정렬
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int temp; cin >> temp;
        vec.push_back(temp);
    }

    if (N >= K) { // 멀티탭 구멍이 더 많으면 플러그를 뽑을 필요 없음
        cout << "0\n";
        return 0;
    }
        
    int cnt = 0, result = 0;
    memset(mtt, 0, sizeof(mtt));

    for (int i = 0; i < vec.size(); i++) {
        int cur = vec[i];

        if (mtt[cur] == 0) { // 안 꽂혀 있는 경우
            if (cnt < N) { // 멀티탭에 자리가 남아있는 경우
                mtt[cur] = 1;
                cnt++;
                keys.push_back(cur);
            } 
            else { // 교체가 필요함
                vector<_Node> det;
                
                for (int j = 0; j < keys.size(); j++) {
                    int key = keys[j];
                    auto loc = find(vec.begin() + i + 1, vec.end(), key);
                    int next_use = (loc == vec.end()) ? K + 1 : (loc - vec.begin()); 
                    det.push_back({next_use, j, key});
                }

                sort(det.begin(), det.end()); // next_use 기준으로 정렬
                _Node victim = det.front(); // 가장 늦게 등장하는 것 제거

                mtt[victim.value] = 0;
                keys[victim.idx] = cur;
                mtt[cur] = 1;
                result++;
            }
        }
    }
    
    cout << result << '\n';
    return 0;
}
