#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000001];
int main() {
    int N, X;
    cin >> N;
    vector<int> vec;
    for(int i=0;i<N;i++) {
        int n; cin >> n;
        vec.push_back(n);
    }
    memset(arr,0,sizeof(arr));
    cin >> X;
    sort(vec.begin(),vec.end());

    int result = 0;
    for(int i=0;i<N;i++) {
        int curr = vec[i];
        int target = X - vec[i]; 
        if(target<=0 || target == curr) continue;
        if(target > 0 && target <= 1000000) {
            if(arr[target] == 1 && arr[curr] == 1) continue;
        }
        int l = 0, r = N-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(vec[mid] == target) {
                result++;
                arr[curr] = 1;
                arr[target] = 1;
                break;
            }
            else if(vec[mid] < target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
    }   
    cout << result;
    return 0;
}