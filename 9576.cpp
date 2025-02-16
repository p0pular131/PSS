// 책 나눠주기
// https://www.acmicpc.net/problem/9576

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, M;
struct Book {
    int mm, xx;
};

bool cmp(Book a, Book b) {
    if (a.xx == b.xx) return a.mm < b.mm;
    return a.xx < b.xx;
}

int sold[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vector<Book> vec(M);
        memset(sold, 0, sizeof(sold));
        
        for (int i = 0; i < M; i++) {
            cin >> vec[i].mm >> vec[i].xx;
        }
        sort(vec.begin(), vec.end(), cmp);
        int result = 0;

        for (auto elem : vec) {
            for (int idx = elem.mm; idx <= elem.xx; idx++) {
                if (sold[idx] == 0) {
                    sold[idx] = 1;
                    result++;
                    break;
                }
            }
        }

        cout << result << '\n';
    }
    
    return 0;
}