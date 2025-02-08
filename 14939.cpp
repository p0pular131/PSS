// 불 끄기
// https://www.acmicpc.net/problem/14939

#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9

using namespace std;
char map[10][10], copy_map[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void turn_on(int x, int y){ 
    if(copy_map[x][y] == 'O') copy_map[x][y] = '#';
    else copy_map[x][y] = 'O';
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10){ // map에 범위에 맞는지 확인
            if(copy_map[nx][ny] == 'O') copy_map[nx][ny] = '#';
            else copy_map[nx][ny] = 'O';
        }
    }
}

void reset_map(){ 
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            copy_map[i][j] = map[i][j];
        }
    }
}

bool all_light_on(){ 
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(copy_map[i][j] == 'O') return false;
        }
    }
    return true;
}

void solve(){
    int ans = INF; 
    for(int step = 0; step < 1024; step++){ 
        int cnt = 0;
        reset_map();
        for(int i = 0; i < 10; i++){ 
            if(step & (1 << i)){
                cnt++;
                turn_on(0, i);
            }
        }
        for(int i = 1; i < 10; i++){ 
            for(int j = 0; j < 10; j++){
                if(copy_map[i-1][j] == 'O'){
                    turn_on(i, j);
                    cnt++;
                }
            }
        }
        if(all_light_on()) ans = min(ans, cnt);
    }
    if(ans == INF) cout << "-1";
    else cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cin >> map[i][j];
        }
    }
    solve();
    return 0;
}