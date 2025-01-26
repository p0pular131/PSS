// 열쇠
// https://www.acmicpc.net/problem/9328

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;  

int visited[104][104], n, m, t, ret; 
char a[104][104], keys[26]; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 
string s; 

void bfs(int y, int x){
    queue<int> q; 
    queue<int> door[26];  
    visited[y][x] = 1; 
    q.push(1000 * y + x);  
    while(q.size()){
        int y = q.front() / 1000; 
        int x = q.front() % 1000; 
        q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) 
                continue; 
            char word = a[ny][nx]; 
            if(word == '*') 
                continue; 

            visited[ny][nx] = 1; 
            if(word == '.') 
                q.push(1000 * ny + nx); 
            else if(word == '$'){
                ret++; 
                q.push(1000 * ny + nx); 
            }
            else if(word >= 'A' && word <= 'Z'){ 
                if(keys[word - 'A']) 
                    q.push(1000 * ny + nx); 
                else 
                    door[word - 'A'].push(1000 * ny + nx); 
            }
            else if(word >= 'a' && word <= 'z'){
                q.push(1000 * ny + nx); 
                if(!keys[word - 'a']){
                    keys[word - 'a'] = 1; 
                    while(door[word - 'a'].size()){
                        q.push(door[word - 'a'].front()); 
                        door[word - 'a'].pop();
                    }
                }
            } 
        }
    }
    return;
}

void solve(){ 
    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);  
    bfs(0, 0);  
    return; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t; 
    while(t--){
        for(int i = 0; i < 26; i++)
            keys[i] = 0;  
        ret = 0; 
        cin >> n >> m;   
        fill(&a[0][0], &a[0][0] + 104 * 104, '.'); 
        for(int i = 1; i <= n; i++){
            cin >> s;  
            for(int j = 1; j <= m; j++){
                a[i][j] = s[j - 1];  
            }
        } 
        n += 2; m += 2;
        cin >> s; 
        if(s != "0"){
            for(int i = 0; i < s.size(); i++){
                keys[s[i] - 'a'] = 1;  
            }
        } 

        solve();
        cout << ret << "\n"; 
    } 
}