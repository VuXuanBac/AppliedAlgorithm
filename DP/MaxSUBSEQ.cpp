/// Tìm dãy con (các phần tử liên tiếp) mà tổng các phần tử là lớn nhất
/// -> O(n)
/// sum[i] = max( sum[i - 1] + a[i], a[i] )
/// sum[i]: Tổng lớn nhất của mọi dãy con kết thúc tại a[i].
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000
int a[MAX_N];
int N;
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> a[i];
 
    long long best = -LLONG_MAX;
    long long prev_sum = a[0];
    for(int i = 1; i < N; ++i){
        prev_sum += a[i];
        if(prev_sum < a[i])
            prev_sum = a[i];
        if(best < prev_sum)
            best = prev_sum;
    }
    cout << best << "\n";
    return 0;
}