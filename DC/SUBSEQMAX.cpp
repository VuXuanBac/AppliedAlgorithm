/// Max sub sequence, n <= 10^6
#include <iostream>
using namespace std;
#define MAX_LENGTH 1000000
int a[MAX_LENGTH];
int addLeft(int start, int end)
{
    int result = a[start];
    int sum = 0;
    for(int i = end; i >= start; --i)
    {
        sum += a[i];
        if(sum > result)
            result = sum;
    }
    return result;
}
int addRight(int start, int end)
{
    int result = a[start];
    int sum = 0;
    for(int i = start; i <= end; ++i)
    {
        sum += a[i];
        if(sum > result)
            result = sum;
    }
    return result;
}
int findMax(int start, int end)
{
    if(end-start<1){
        return a[start];
    }
    else if(end-start==1){
        if(a[end]>=0&&a[start]>=0)
            return a[end]+a[start];
        else
            return a[start]>a[end]?a[start]:a[end];
    }
    int midInd = (end+start)/2;
    int left = findMax(start, midInd);
    int right = findMax(midInd+1, end);
    int mid = addLeft(start, midInd) + addRight(midInd+1, end);
    int result = left > right ? left : right;
    return result > mid ? result : mid;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
 
    cout << findMax(0, n-1);
 
    return 0;
}