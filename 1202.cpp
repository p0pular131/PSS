// 보석 도둑
// https://www.acmicpc.net/problem/1202

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N,K;
struct Jewel {
    int m;
    int v;
};
vector<Jewel> js;
multiset<int> bags;

bool comp(Jewel a, Jewel b) {
    if(a.v == b.v) 
        return a.m < b.m;
    else 
        return a.v > b.v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    
    for(int i=0;i<N;i++) {
        Jewel temp;
        cin >> temp.m >> temp.v;
        js.push_back(temp);
    }
    for(int i=0;i<K;i++) {
        int temp;
        cin >> temp;
        bags.insert(temp);
    }
    sort(js.begin(),js.end(),comp);
    long long valueSum = 0;
    for(auto target : js) {
        auto it = bags.lower_bound(target.m);
        if (it != bags.end()) {
            valueSum += target.v;
            bags.erase(it);
        }
    }
    cout << valueSum << '\n';
    return 0;
}