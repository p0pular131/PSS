#include <iostream>
int arr[20000001]; // counting sort
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N;
    for(int i=0;i<20000001;i++)
        arr[i] = 0;
    for(int i=0;i<N;i++) {
        int idx;
        cin >> idx;
        arr[idx+10000000] = 1;
    }
    cin >> M;
    for(int i=0;i<M;i++) {
        int curr;
        cin >> curr;
        if(arr[curr+10000000] == 1) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }
    return 0;
}