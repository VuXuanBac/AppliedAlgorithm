/// Cho dãy arr[1..N], tìm C phần tử mà khoảng cách nhỏ nhất giữa 
/// hai phần tử bất kì là lớn nhất.
#include <bits/stdc++.h>
using namespace std;
#define MAX_N int(10e5)
#define MAX_C int(10e9)
int T, N, C;
int arr[MAX_N];
int max_dist;
bool is_over(int x)
{
    int prev = arr[0];
    int set_count = C;
    for(int i = 1; i < N; ++i)
    {
        if(arr[i] - prev >= x){
            prev = arr[i];
            if(--set_count == 1)
                return false;
        }
    }
    return true;
}
int bsearch()
{
    int l = 1;
    int r = max_dist  + 1;
    int mid;
    while(l < r){
        mid = (l + r) / 2;
        if(is_over(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l-1;
}
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    freopen("../test.txt", "r", stdin);
    //freopen("../testout.txt", "w", stdout);
    cin >> T;
    for(int i = 0; i < T; ++i){
        cin >> N >> C;
        for(int j = 0; j < N; ++j)
            cin >> arr[j];
        sort(arr, arr + N);
        max_dist = arr[N-1] - arr[0];
        cout << bsearch() << "\n";
    }
    return 0;
}
