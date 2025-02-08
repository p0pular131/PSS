// 회의실 배정
// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> vec;
int n,a,b;
int f_num, s_num;
int result = 0;
bool first = true;
vector<int> result_vec;

bool f(vector<int> a, vector<int> b){
    if(a[1]<b[1]) return true;
    else if(a[1]==b[1]) {
        if(a[0]<b[0]) return true;
        else return false;
    }
    else return false;
}

int dfs(int idx){
    if(s_num<=vec[idx][0]) {
        if(!first){
            result += 1;
            f_num = vec[idx][0];
            s_num = vec[idx][1];
        }
    }
    if(idx == n-1) {
        result_vec.push_back(result);
        return 0;
    }
    first = false;
    dfs(idx+1);
    return 0;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> input;
        cin>>a>>b;
        input.push_back(a);
        input.push_back(b);
        vec.push_back(input);
    }
    sort(vec.begin(),vec.end(),f);
    first = true;
    result = 1;
    f_num = vec[0][0];
    s_num = vec[0][1];
    dfs(0);
    cout<<*max_element(result_vec.begin(),result_vec.end())<<'\n';
    return 0;
}