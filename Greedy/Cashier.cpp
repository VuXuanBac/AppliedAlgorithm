/// Cashier Problem: Tìm cách trả lại tiền thừa sao cho số đồng tiền sử dụng là nhỏ nhất.
/// Greedy: Đúng với các đồng tiền mệnh giá: 1, 5, 10, 50, 100, 500
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, c = 0, i = 0, t;
    int v[] = {500, 100, 50, 10, 5, 1};
    cin >> N;
    N = 1000 - N;
    while(N > 0){
        while(N < v[i])
            i--;
        t = N / v[i];
        N -= t*v[i];
        c += t;
    }
    cout << c;
    return 0;
}
