// 숨바꼭질 3
// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 100000
#define MIN 0
int visit[100001];
int N,K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    memset(visit,0x3f,sizeof(visit));
    queue<int> q;
    q.push(N);
    visit[N] = 0;
    int result = 1e9;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(curr*2 <= MAX) {
            if(visit[curr]+1 < visit[curr*2]) {
                q.push(curr*2);
                visit[curr*2] = visit[curr];
            }
        }
        if(curr > MIN) {
            if(visit[curr]+1 < visit[curr-1]) {
                q.push(curr-1);
                visit[curr-1] = visit[curr]+1;
            }
        }
        if(curr < MAX) {
            if(visit[curr]+1 < visit[curr+1]) {
                q.push(curr+1);
                visit[curr+1] = visit[curr]+1;
            }
        }
        result = min(result,visit[K]);
    }
    cout << result;
    return 0;
}