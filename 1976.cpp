#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,M,target;
int visit[201];
vector<int> arr[201]; 

int dfs(int curr) {
    if(visit[curr] == 1) {
        return -1;
    }
    if(curr == target) {
        return 0;
    }
    visit[curr] = 1;
    for(int next : arr[curr]) {
        if(dfs(next) == 0)
            return 0;
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N; cin >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            int temp;
            cin >> temp;
            if(temp == 1) {
                arr[i].push_back(j);
            }
        }
    }
    vector<int> candi;
    for(int i=0;i<M;i++) {
        int temp; cin >> temp; candi.push_back(temp);
    }

    memset(visit,0,sizeof(visit));
    int start = candi[0];
    for(int i=1;i<candi.size();i++) {
        target = candi[i];
        memset(visit,0,sizeof(visit));
        if(dfs(start)<0) {
            cout << "NO\n";
            return 0;
        }
        start = target;
    }

    cout << "YES\n";
    return 0;
}