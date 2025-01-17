#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int M,N,H;
int map[101][101][101];
int visit[101][101][101];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int normTomato;

typedef struct {
    int x;
    int y;
    int z;
}Node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> M >> N >> H;
    normTomato = 0; // 남은 토마토 개수
    queue<Node> q1;
    queue<Node> q2;
    queue<Node> *Q[] = {&q1, &q2}; // bfs queue
    memset(visit,0,sizeof(visit));

    for(int i=1;i<=H;i++) {
        for(int j=1;j<=N;j++) {
            for(int k=1;k<=M;k++) {
                cin >> map[i][j][k];
                if(map[i][j][k] == 0)
                    normTomato++;
                else if(map[i][j][k] == 1) {
                    // 처음 bfs를 시작할 위치들 enqueue
                    Node temp = {i,j,k};
                    Q[0]->push(temp);
                    visit[i][j][k] = 1;
                }
            }
        }
    }

    int day = 0;
    while(1) {
        queue<Node> *currQ = Q[day%2]; // pop할 queue
        queue<Node> *nextQ = Q[(day%2+1)%2]; // enqueue할 queue
        if(normTomato == 0) {
            break;
        }
        if(currQ->empty() && nextQ->empty()) {
            if(normTomato != 0)
                day = -1;
            break;
        }
        // bfs for each ripen tomato
        while(!currQ->empty()) {
            Node currNode = currQ->front();
            currQ->pop();
            int x=currNode.x, y=currNode.y, z=currNode.z;
            for(int i=0;i<6;i++) {
                int nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
                if(nx<1 || nx>H || ny<1 || ny>N || nz<1 || nz>M) {
                    continue;
                }
                if(visit[nx][ny][nz] == 1) {
                    // 이미 방문했으면
                    continue;
                }
                if(map[nx][ny][nz] == -1) {
                    // 인접점 벽이면 pass
                    continue;
                }
                else if(map[nx][ny][nz] == 0) {
                    // 인접점이 그냥 토마토면 익히고 다음 queue에 삽입
                    map[nx][ny][nz] = 1;
                    normTomato--;
                    nextQ->push({nx,ny,nz});
                    visit[nx][ny][nz] = 1;
                }
            }
        }       
        day++;
    }
    cout << day << '\n';
    
    // for(int i=1;i<=H;i++) {
    //     for(int j=1;j<=N;j++) {
    //         for(int k=1;k<=M;k++) {
    //             cout << visit[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }

}