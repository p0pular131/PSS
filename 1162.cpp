#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int,int>> graph[10001];
int N,M,K;

struct Node{
    int num;
    long long dist;
    int p;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

long long dijkstra() {
    long long dist[10001][21];
    memset(dist,0x7f,sizeof(dist));
    priority_queue<Node> pq;
    dist[1][0] = 0; // 출발점 초기화 
    pq.push({1,0,0}); // {node, distance, paved}
    while(!pq.empty()) {
        int curNode = pq.top().num;
        long long curDis = pq.top().dist; 
        int isPaved = pq.top().p;
        pq.pop();
        if(dist[curNode][isPaved] < curDis) continue;
        
        for(int i=0;i<graph[curNode].size();i++) {
            int nextNode = graph[curNode][i].first;
            long long nextDis = graph[curNode][i].second + curDis;
            if(dist[nextNode][isPaved] > nextDis) { 
                dist[nextNode][isPaved] = nextDis;
                pq.push({nextNode,nextDis,isPaved});
            }
            if(isPaved < K && dist[nextNode][isPaved+1] > curDis) {
                dist[nextNode][isPaved+1] = curDis;
                pq.push({nextNode,curDis,isPaved+1});
            }
        }
    }
    long long result = dist[N][0];
    for(int i=1;i<=K;i++) {
        result = min(result,dist[N][i]);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    
    for(int i=0;i<M;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }

    cout << dijkstra() << '\n';

    return 0;
}