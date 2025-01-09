#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long A,B; 
    int result = 0;
    cin >> A; cin >> B;

    while(1) {
        if(A > B) {
            cout << "-1\n";
            break;
        }
        result++;
        if(A == B) {
            cout << result << '\n';
            break;
        }

        if(B%10 == 1) {
            B /= 10;
        }
        else if(B%2 == 0) {
            B /= 2;
        }
        else {
            cout << "-1\n";
            break;
        }

    }

    return 0;
}