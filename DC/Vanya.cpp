#include <bits/stdc++.h>
using namespace std;
int N, L;
int arr[1001];
int main()
{
    cin >> N >> L;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr, arr+N);
    double result = max(arr[0], L-arr[N-1]) * 2.0;
    for(int i = 1; i < N; ++i)
        if(arr[i] - arr[i-1] > result)
            result = arr[i] - arr[i-1];
    cout.precision(10);
    cout << fixed << result/2.0 << "\n";
    return 0;
}