#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) {
        int N;
        string temp;
        vector<string> vec;
        cin >> N;
        for(int j=0;j<N;j++) {
            cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end());

        bool consistent = true;
        for(int j=0;j<N-1;j++) {
            if(vec[j].length() > vec[j+1].length()) 
                continue;
            int len = vec[j].length();
            string sliced = vec[j+1].substr(0,len);
            if(vec[j] == sliced) {
                cout << "NO\n";
                consistent = false;
                break;
            }
        }
        if(consistent) {
            cout << "YES\n";
        }
    }
    return 0;
}
