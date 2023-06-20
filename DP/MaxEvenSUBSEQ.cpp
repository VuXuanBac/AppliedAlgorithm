/// Tìm dãy con (các phần tử liên tiếp) mà tổng các phần tử là chẵn và lớn nhất.
/// -> O(N)
/// - Duyệt từ đầu đến cuối.
/// - odd_sum[i] = tổng lẻ lớn nhất của dãy con (các phần tử liên tiếp) kết thúc tại i.
/// - even_sum[i], tương tự.
/// -> odd_sum[i] = odd_sum[i-1] + a[i] nếu a[i] chẵn.
/// -> odd_sum[i] = max( even_sum[i-1] + a[i], a[i] ) nếu a[i] lẻ.
/// -> odd_sum[i] = 0 khi và chỉ khi không thể tạo tổng lẻ từ mọi dãy con kết thúc tại i.
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000
int a[MAX_N];
int N;

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> a[i];
    if(N == 1 && a[0] % 2)
        cout << "NOT_FOUND\n";
    else{
        long long best = -LLONG_MAX;
        long long even_sum = 0;
        long long odd_sum = 0;
        long long temp;
        if(a[0] % 2 == 0){
            even_sum = a[0];
            best = a[0];
        }
        else
            odd_sum = a[0];
        for(int i = 1; i < N; ++i){
            if(a[i] % 2 == 0)
            {
                even_sum = max(even_sum + a[i], (long long)a[i]);
                if(odd_sum != 0)
                    odd_sum += a[i];
            }
            else{
                temp = odd_sum;
                odd_sum = max(even_sum + a[i], (long long)a[i]);
                even_sum = (temp == 0 ? 0 : temp + a[i]);
            }
            best = max(best, even_sum);
        }
        cout << best << "\n";
    }
    
    return 0;
}