#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N; cin >> K;
    int l = 1, r = K;
    int result = 0;
    while(l<=r) {
        int mid = l + (r-l)/2;
        int sum = 0;
        for(int i=1;i<=N;i++) {
            sum += mid/i > N ? N : mid/i;
        }
        if(sum<K) {
            l = mid+1;
        }
        else if(sum>=K) {
            result = mid;
            r = mid-1;
        }
    }
    cout << result << '\n';
    return 0;
}