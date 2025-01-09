#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>>& vec,vector<int>& result,int num,int parent){
    if(result[num]==-1){ //방문하지 않은 경우
        result[num] = parent;
        for(int i=0;i<vec[num].size();i++){ // 방문한 노드와 연결된 노드의 수만큼
            dfs(vec,result,vec[num][i],num);
        }
        return 0;
    }
    else
    return 0; // 이미 방문했으면 바로 종료
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a,b;
    vector<vector<int>> vec(n+1,vector<int>());
    vector<int> result(n+1,-1);
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);}
    // dfs 1부터 시작. 그러면 끝남. 
    dfs(vec,result,1,0);
    for(int i=2;i<n+1;i++) cout<<result[i]<<'\n';
    
}