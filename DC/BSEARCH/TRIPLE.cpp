//Đếm số cách phân tích một số nguyên dương K 
//bằng tổng của 3 phần tử trong dãy cho trước.
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 5000
int N, K;
int arr[MAX_N];
int bsearch(int start, int value)
{
    int l = start;
    int r = N - 1;
    int m = l;
    while(l <= r){
        m = (l + r) >> 1;
        if(arr[m] > value)
            r = m - 1;
        else if(arr[m] < value)
            l = m + 1;
        else break;
    }
    if(arr[m] != value)
        return 0;
    int i = m;
    int result = 1;
    while(--i >= start && arr[i] == value) ++result;
    i = m;
    while(++i < N && arr[i] == value) ++result;
    return result;
}
// Đếm số cách phân tích <value> thành <number> phần tử
// của dãy với chỉ số phần tử đầu tiên là <start>
int dc(int start, int value, int number)
{
    if(start + number > N || value < arr[start])
        return 0;
    if(number == 1){
        return bsearch(start, value);
    }
    return  dc(start + 1, value - arr[start], number - 1) +
            dc(start + 1, value, number);
}
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    freopen("../test.txt", "r", stdin);
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr, arr + N);
    cout << dc(0, K, 3);
    return 0;
}
