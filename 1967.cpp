#include <iostream>
#include <vector>
using namespace std;

int N;
int maxNode;
long long leng = 0;
vector<pair<int,int>> grp[10001];
vector<int> visit(10001,0);

int dfs(int node, int currLeng) {
    visit[node] = 1;
    for(auto elem : grp[node]) {
        int currChild = elem.first;
        if(visit[currChild] == 1) {
            continue;
        }
        int nexLeng = currLeng + elem.second;
        if(nexLeng >= leng) {
            maxNode = currChild;
            leng = nexLeng;
        }
        dfs(currChild, nexLeng);
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int parent,child,weight;
    for(int i=0;i<N-1;i++) {
        cin >> parent >> child >> weight;
        grp[parent].push_back({child,weight});
        grp[child].push_back({parent,weight});
    }

    dfs(1,0);
    visit.assign(10001,0);
    leng = 0;
    dfs(maxNode,0);
    cout << leng << '\n';
}