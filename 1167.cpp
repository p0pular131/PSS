// 트리의 지름
// https://www.acmicpc.net/problem/1167

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

int N;
int maxNode;
long long leng = 0;
vector<pair<int, int>> grp[100001];
vector<int> visit(100001, 0);

int dfs(int node, int currLeng) {
    visit[node] = 1;
    for (auto elem : grp[node]) {
        int currChild = elem.first;
        if (visit[currChild] == 1) {
            continue;
        }
        int nexLeng = currLeng + elem.second;
        if (nexLeng >= leng) {
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
    cin.ignore(); 

    string input;
    int parent, child, weight;
    for (int i = 0; i < N; i++) {
        getline(cin, input);  
        stringstream ss(input); 

        ss >> parent; 
        while (ss >> child) {
            if (child == -1) break;  
            ss >> weight;  
            grp[parent].push_back({child, weight});
            grp[child].push_back({parent, weight});
        }
    }

    dfs(1, 0);  
    visit.assign(100001, 0); 
    leng = 0;  
    dfs(maxNode, 0);  

    cout << leng << '\n';  
}
