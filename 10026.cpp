#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,result;
int visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char normArr[101][101];
char abnormArr[101][101];

int dfs(int x, int y, char clr, int normal) {
    if(x<1 || x>N || y<1 || y>N) {
        return -1;
    }
    if(visit[x][y] == 1) {
        return -1;
    }

    if(normal) {
        if(normArr[x][y] != clr) {
            return -1;
        }
        else {
            visit[x][y] = 1;
            for(int i=0;i<4;i++) {
                int nx=x+dx[i], ny=y+dy[i];
                dfs(nx,ny,clr,normal);
            }
        }
    }
    else {
        if(abnormArr[x][y] != clr) {
            return -1;
        }
        else {
            visit[x][y] = 1;
            for(int i=0;i<4;i++) {
                int nx=x+dx[i], ny=y+dy[i];
                dfs(nx,ny,clr,normal);
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            char temp;
            cin >> temp;
            normArr[i][j] = temp;
            abnormArr[i][j] = temp;
            if(temp == 'R' || temp == 'G')
                // 'R'로 통일해서 저장
                abnormArr[i][j] = 'R';
        }
    }
    memset(visit,0,sizeof(visit));
    result = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(visit[i][j]==0) {
                if(dfs(i,j,normArr[i][j],1)==0)
                    result++;
            }
        }
    }
    cout << result << ' ';

    memset(visit,0,sizeof(visit));
    result = 0;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(visit[i][j]==0) {
                if(dfs(i,j,abnormArr[i][j],0)>=0)
                    result++;
            }
        }
    }    
    cout << result << '\n';
    return 0;
}