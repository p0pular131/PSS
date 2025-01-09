#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visited[1001][1001][2];
int map[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N,M;

typedef struct {
    int x;
    int y;
    int wall;
}Node;

int bfs() {
    queue<Node> q;
    visited[1][1][0] = 1;
    q.push({1,1,0});

    while(!q.empty()) {
        Node curr = q.front();
        q.pop();
        // 종료조건 
        if(curr.x == N && curr.y == M) {
            return visited[N][M][curr.wall];
        }

        for(int i=0;i<4;i++) {
            int nx=curr.x+dx[i], ny=curr.y+dy[i], w=curr.wall;
            // 경계밖 또는 이미 방문
            if(nx<1 || nx>N || ny<1 || ny>M || visited[nx][ny][w]!=0) { 
                continue;
            }
            // 벽인데 방문도 안했고 아직 부수지도 않았으면
            if(map[nx][ny]==1 && visited[nx][ny][w]==0 && w==0) {
                Node temp = {nx,ny,1}; // 부수기 
                q.push(temp);
                visited[nx][ny][1] = visited[curr.x][curr.y][curr.wall]+1;
            }
            // 벽아니고 아직 방문 안했으면
            else if(map[nx][ny]==0 && visited[nx][ny][w]==0) {
                Node temp = {nx,ny,w};
                q.push(temp);
                visited[nx][ny][w] = visited[curr.x][curr.y][curr.wall]+1;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++)  {
            char temp;
            cin >> temp;
            map[i][j] = temp - '0';
        }
    }
    memset(visited,0,sizeof(visited));

    cout << bfs() << '\n';

    return 0;
}