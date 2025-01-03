#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N, M;
    cin >> T; 
    for(int test=0;test<T;test++) {
        cin >> N;
        vector<int> vec(N);
        for(int i=0;i<N;i++) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        cin >> M;
        for(int i=0;i<M;i++) {
            int l=0,r=N-1,target,mid; cin >> target;
            bool found = false;
            while(l<=r) {
                mid = l+(r-l)/2;
                if(vec[mid] == target) {
                    found = true;
                    break;
                }
                else if(vec[mid] < target) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            if(found) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}