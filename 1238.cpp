// 파티
// https://www.acmicpc.net/problem/1238

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int,int>> graph[10001];
long long dist[10001];
long long startDist[1001];
long long finalDist[1001];
int N,M,X;

struct Node{
    int num;
    long long dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

void dijkstra(int start) {
    memset(dist,0x7f,sizeof(dist));
    priority_queue<Node> pq;
    dist[start] = 0; // 출발점 초기화 
    pq.push({start,0}); 
    while(!pq.empty()) {
        int curNode = pq.top().num;
        long long curDis = pq.top().dist; 
        pq.pop();
        if(dist[curNode] < curDis) continue;
        
        for(int i=0;i<graph[curNode].size();i++) {
            int nextNode = graph[curNode][i].first;
            long long nextDis = graph[curNode][i].second + curDis;
            if(dist[nextNode] > nextDis) { 
                dist[nextNode] = nextDis;
                pq.push({nextNode,nextDis});
            }
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> X;
    
    for(int i=0;i<M;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        graph[a].push_back({b,w});
    }
    for(int i=1;i<=N;i++) {
        dijkstra(i);
        startDist[i] = dist[X];
    }
    dijkstra(X);
    long long max = -1;
    for(int i=1;i<=N;i++) {
        finalDist[i] = startDist[i] + dist[i];
        if(max < finalDist[i]) {
            max = finalDist[i];
        }
    }
    cout << max;
    return 0;
}