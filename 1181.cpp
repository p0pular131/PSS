#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool crit(string a, string b) {
    if(a.length() > b.length()) {
        return false;
    }
    else if(a.length() < b.length()) {
        return true;
    }
    else {
        for(int i=0;i<a.length();i++) {
            if(a[i] > b[i]) {
                return false;
            }
            else if(a[i] < b[i]) {
                return true;
            }
            else continue;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<string> inputs;
    for(int i=0;i<N;i++) {
        string temp; 
        cin >> temp;
        inputs.push_back(temp);
    }
    sort(inputs.begin(),inputs.end(),crit);
    cout << inputs[0] << '\n';
    for(int i=1;i<N;i++){
        if(inputs[i] != inputs[i-1])
            cout << inputs[i] << '\n';
    } 
    return 0;
}