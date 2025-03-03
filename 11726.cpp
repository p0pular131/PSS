// 2xn 타일링
// https://www.acmicpc.net/problem/11726

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec(1001);
    vec[1] = 1;
    vec[2] = 2;
    for(int i=3;i<1001;i++){
        vec[i] = (vec[i-1] + vec[i-2])%10007;
    }
    int n;
    cin>>n;
    cout<<vec[n]<<'\n';
    
}
