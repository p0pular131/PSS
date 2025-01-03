#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    vector<int> vec(N);
    for(int i=0;i<N;i++) cin >> vec[i];
    int M; cin >> M;

    sort(vec.begin(),vec.end());
    int l=0, r=vec[N-1], sum=0, result=0;
    while(l<=r) {
        int mid = l + (r-l)/2;
        sum = 0;
        for(int i=0;i<N;i++) {
            sum += min(vec[i],mid);
        }
        if(sum > M) {
            r = mid-1;
        }
        else {
            l = mid+1;
            result = mid;
        }
    }
    cout << result <<'\n';
    return 0;
}